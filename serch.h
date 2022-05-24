#ifndef SERCH_H
#define SERCH_H

#include <QDirIterator>
#include <QThread>
#include <QObject>
#include <QFileInfo>
#include <QDir>



class Serch : public QObject

{
    Q_OBJECT
public:
    explicit Serch(QObject *parent = nullptr);
    void startSerching(QString path, QString needFiles);

signals:
    void foundFile(QString);

};

#endif // SERCH_H
