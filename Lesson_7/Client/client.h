#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Client;
}
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void bConnectToServer();
    void bSend();

    void newMessage();
    void connectedToServer();

private:
    Ui::Client *ui;
    QTcpSocket *m_socket;

    void updateUsersList(QByteArray rawUsers);
};
#endif // CLIENT_H
