#ifndef AIWORKER_H
#define AIWORKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

class aiWorker : public QObject
{
    Q_OBJECT
public:
    explicit aiWorker(QObject *parent = nullptr);

public slots:
    void askAI(QString prompt);

private slots:
    void receiveAnswer(QNetworkReply *reply);

signals:
    void answerReady(QString text);
private:
    QNetworkAccessManager *m_manager;
};

#endif // AIWORKER_H
