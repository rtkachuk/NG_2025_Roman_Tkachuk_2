#include "servak.h"

Servak::Servak(QObject *parent)
    : QObject{parent}
{
    m_server = new QTcpServer();

    connect (m_server, &QTcpServer::newConnection, this, &Servak::newClient);
}

bool Servak::startServer(QString ip, int port)
{
    bool ok = m_server->listen(QHostAddress(ip), port);
    if (ok == false)
        qDebug() << "Error starting server: " << m_server->errorString();
    else
        qDebug() << "Server started: " << m_server->serverAddress().toString() << ":" << m_server->serverPort();
    if (m_server->isListening()) {
        qDebug() << "Server is listening!";
    }
    return ok;
}

void Servak::sendUserList()
{
    QByteArray message = "u";
    for (QByteArray login : m_users.values()) {
        message += ":";
        message += login;
    }

    sendToAll(message);
}

void Servak::sendToAll(QByteArray message)
{
    for (QTcpSocket * user : m_users.keys()) {
        user->write(message);
        user->flush();
    }
}

void Servak::newClient()
{
    QTcpSocket *socket = m_server->nextPendingConnection();
    m_users[socket] = "User";
    qDebug() << "New user from " << socket->localAddress();

    connect (socket, &QTcpSocket::readyRead, this, &Servak::newMessageFromUser);
    connect (socket, &QTcpSocket::disconnected, this, &Servak::userDisconnected);
    sendUserList();
}

void Servak::newMessageFromUser()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    QByteArray userData = socket->readAll();

    // m - message
    // l - login

    // m:Hello - message "Hello" from user
    // l:Tester - Change login to Tester
    QByteArray message = userData;
    message = message.remove(0,2); // remove first two symbols, which represent command
    char cmd = userData[0];
    qDebug() << cmd << ":::" << message;
    switch (cmd) {
    case 'l': m_users[socket] = message; qDebug() << "Saved login: " << message; sendUserList(); break;
    case 'm': sendToAll("m:" + m_users[socket] + ": " + message); break;
    default: qDebug() << "User " << m_users[socket] << " performed an invalid action " << cmd;
    }
}

void Servak::userDisconnected()
{
    QTcpSocket *socket = (QTcpSocket*)sender();

    disconnect (socket, &QTcpSocket::readyRead, this, &Servak::newMessageFromUser);
    disconnect (socket, &QTcpSocket::disconnected, this, &Servak::userDisconnected);

    m_users.remove(socket);

    qDebug() << "User disconnected: " << socket->localAddress();
}
