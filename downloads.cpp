#include "downloads.h"

#include <QNetworkReply>
#include <QMessageBox>

Downloads::Downloads(QObject *parent)
    : QObject{parent}
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(slotFininshed(QNetworkReply*)));
}

void Downloads::download(const QUrl &url)
{
    networkManager->get(QNetworkRequest(url));
}

void Downloads::slotFininshed(QNetworkReply* reply)
{
    if(reply->error() != QNetworkReply::NetworkError::NoError) {
     
       QMessageBox::critical(nullptr, "Error", "Error!");
    }
    else emit done(reply->url(), reply->readAll());
    reply->deleteLater();
}
