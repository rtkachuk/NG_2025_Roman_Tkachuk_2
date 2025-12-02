#ifndef SERVAK_H
#define SERVAK_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class Servak : public QObject
{
    Q_OBJECT
public:
    explicit Servak(QObject *parent = nullptr);
    bool startServer(QString ip, int port);

private:
    QTcpServer *m_server;
    QMap<QTcpSocket*, QByteArray> m_users;

    void sendUserList();
    void sendToAll(QByteArray message);

private slots:
    void newClient();
    void newMessageFromUser();
    void userDisconnected();
signals:
};

#endif // SERVAK_H
