#include "serch.h"

Serch::Serch(QObject *parent) : QObject(parent)
{

}

void Serch::startSerching(QString path, QString needFiles)
{
    QDirIterator it(path,  QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QFile file(it.next());
        QFileInfo item(file);
        if( (item.isFile() || item.isDir() ) && item.fileName().contains(needFiles, Qt::CaseInsensitive) )
        {
            QString findFile = item.absoluteFilePath();
            emit foundFile(findFile);
        }
    }
}
