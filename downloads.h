#ifndef DOWNLOADS_H
#define DOWNLOADS_H

#include <QObject>
#include <QNetworkAccessManager>

class Downloads : public QObject
{
    Q_OBJECT
public:
    explicit Downloads(QObject *parent = nullptr);
    void download(const QUrl &url);

signals:
    void done(const QUrl&, const QByteArray&);

private slots:
    void Fininsh_slot(QNetworkReply*);

private:
    QNetworkAccessManager* networkManager {nullptr};
};

#endif // DOWNLOADS_H
