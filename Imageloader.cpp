#include "imageloader.h"
#include <QMessageBox>
#include <QFile>
#include <QLabel>
#include <QRandomGenerator>
#include <algorithm>
#include <iostream>

Imageloader::Imageloader(QWidget *parent)
    : QWidget{parent}
{
    mainGrid = new QGridLayout (this);
    btn = new QPushButton ("->", this);
    le = new QLineEdit(this);
    le->setText("кот");
    QLabel *lb = new QLabel{"Введите запрос:", this};

    mainGrid->addWidget(lb, 0,0,1,3);
    mainGrid->addWidget(le, 1, 0, 1, 2);
    mainGrid->addWidget(btn, 1, 2);

    connect(btn, &QPushButton::clicked, this, &Imageloader::on_pushButton_btn);


    this->setLayout(mainGrid);
}

void Imageloader::showPixMap(const QString &path)
{
    Downloads *downloadPix = new Downloads(this);
    connect(downloadPix, SIGNAL(done(const QUrl&, const QByteArray&)),
            this, SLOT(doneDownloadPix(const QUrl&, const QByteArray&)));
    downloadPix->download(path);
}

void Imageloader::parseQuery(const QString path, const int count)
{
    QFile file(path); 
    if (!file.open(QIODevice::ReadOnly)) return;
    QString file_str = file.readAll();
    file.close();

    std::srand( time( 0 ) );
    QList<int> list;
    for (int i=0; i < count ;i++ ) {
        int value = std::rand() % (count*10);
        list << value;
    }
    std::sort(list.begin(), list.end());
    qDebug() << list;

    long long newPosPix = 0;
    int numberLink = 0;

    for (int i = 0;i < count ; i++ ) {
        newPosPix = file_str.indexOf("\"url\":\"", newPosPix) + 7;
        qDebug() << "номер: " + QString::number(newPosPix) + " символ: [" + file_str[newPosPix] + "]";
        if(newPosPix == -1) return;
        QString urlPixMap;

        do {
            urlPixMap += file_str[newPosPix];
            newPosPix++;
        }   while (file_str[newPosPix] != '\"');

        if(urlPixMap.indexOf(".jpg") == -1) {i--; continue;}
        if(numberLink == list[i]) {
            qDebug() << urlPixMap;
            showPixMap(urlPixMap);
        } else {
            numberLink++;
            i--;
        }
    }
}

QString Imageloader::saveFile(const QUrl &url, const QByteArray &ba)
{
    QFile file(url.path().section('/', -1)); 
    if (!file.open(QIODevice::WriteOnly)) return QString();
    file.write(ba);
    file.close();
    qDebug() << "файл сохранен: " + file.fileName();
    return file.fileName();
}

void Imageloader::on_pushButton_btn()
{
    QUrl url = QUrl("https://yandex.ru/images/search?text=" + le->text());
    QString nameFile = url.path().section('/', -1);
    
    Downloads *download = new Downloads(this);
    connect(download, SIGNAL(done(const QUrl&, const QByteArray&)),
            this, SLOT(doneDownload(const QUrl&, const QByteArray&)));
    download->download(url);
}

void Imageloader::doneDownload(const QUrl &url, const QByteArray &ba)
{
    QString fileName = saveFile(url, ba);
    parseQuery(fileName, 3);
}

void Imageloader::doneDownloadPix(const QUrl &url, const QByteArray &ba)
{
    QString fileName = saveFile(url, ba);

    QPixmap pix(fileName);
    pix = pix.scaled(pix.size()/3);
    QLabel* lbl = new QLabel(this);
    lbl->setWindowFlag(Qt::Window);
    lbl->setPixmap(pix);
    lbl->setFixedSize(pix.size());
    qDebug() << "Открывается файл: " + fileName;
    lbl->show();
}
