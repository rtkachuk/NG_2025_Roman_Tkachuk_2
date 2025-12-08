#include "aiworker.h"

aiWorker::aiWorker(QObject *parent)
    : QObject{parent}
{
    m_manager = new QNetworkAccessManager(this);

    connect (m_manager, &QNetworkAccessManager::finished, this, &aiWorker::receiveAnswer);
}

void aiWorker::askAI(QString prompt)
{
    QNetworkRequest request(QUrl("http://127.0.0.1:11434/api/generate"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["model"] = "llama3.2";
    json["prompt"] = prompt;
    json["stream"] = false;

    QNetworkReply *reply = m_manager->post(request, QJsonDocument(json).toJson());
}

void aiWorker::receiveAnswer(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        emit answerReady(QJsonDocument::fromJson(reply->readAll()).object().value("response").toString());
    }
}
