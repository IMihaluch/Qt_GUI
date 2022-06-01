#include "organizer.h"

Organizer::Organizer(QObject *parent)
    : QObject{parent}
{
    if (!file.exists()) {
        file.setFileName(filename);
      }
}

QByteArray Organizer::readFile()
{
    QByteArray block;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))  {
        block = file.readAll();

        file.close();
    }

    return block;
}

void Organizer::writeFile(QString outputStr)
{
//    if (!file.exists()) return;
    if(file.open(QIODevice::WriteOnly | QIODevice::Append))  {
        QTextStream writeStream(&file); 
        writeStream << outputStr << "\r\n"; 

        file.close();
    }
}

const QString &Organizer::getData() const
{
    return data;
}

void Organizer::setData(const QString &newData)
{
    data = newData;
    writeFile(data);
}
