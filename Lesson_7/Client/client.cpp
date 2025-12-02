#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    m_socket = new QTcpSocket(this);

    ui->sb_port->setRange(0,65535);
    ui->te_chat->setReadOnly(true);

    connect (m_socket, &QTcpSocket::connected, this, &Client::connectedToServer);
    connect (ui->pb_connect, &QPushButton::clicked, this, &Client::bConnectToServer);
    connect (ui->pb_send, &QPushButton::clicked, this, &Client::bSend);
    connect (m_socket, &QTcpSocket::readyRead, this, &Client::newMessage);
}

Client::~Client()
{
    delete ui;
}

void Client::bConnectToServer()
{
    m_socket->connectToHost(ui->le_ip->text(), ui->sb_port->value());
}

void Client::bSend()
{
    m_socket->write("m:" + ui->te_mesage->toPlainText().toUtf8());
    ui->te_mesage->clear();
}

void Client::newMessage()
{
    //ui->te_chat->setPlainText(ui->te_chat->toPlainText() + QString(m_socket->readAll()) + "\n");
    QByteArray rawDataFromServer = m_socket->readAll();
    char cmd = rawDataFromServer[0];
    QByteArray message = rawDataFromServer;
    message = message.remove(0,2);

    switch (cmd) {
    case 'm': ui->te_chat->setPlainText(ui->te_chat->toPlainText() + QString(message) + "\n"); break;
    case 'u': updateUsersList(message); break;
    default: qDebug() << "Wrong command from server: " << cmd;
    }
}

void Client::connectedToServer()
{
    ui->stackedWidget->setCurrentIndex(1);
    m_socket->write("l:" + ui->le_login->text().toUtf8());
}

void Client::updateUsersList(QByteArray rawUsers)
{
    ui->lw_users->clear();
    ui->lw_users->addItems(QString(rawUsers).split(":"));
}
