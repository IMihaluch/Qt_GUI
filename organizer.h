#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <QDebug>

class Organizer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Write READ getData WRITE setData)

public:
    explicit Organizer(QObject *parent = nullptr);
    Q_INVOKABLE QByteArray readFile();
    Q_INVOKABLE void writeFile(QString outputStr);
    const QString &getData() const;
    void setData(const QString &newData);

private:
    const QString filename = "task.dat";
    QFile file;
    QString data;

signals:

};

#endif // ORGANIZER_H
