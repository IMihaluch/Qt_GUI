#include "htmlparser.h"

Html_pars::Html_pars(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);
    plane1 = new QPlainTextEdit(this);
    condition = new QLabel(this);
    condition->setWordWrap(true);
    condition->setText("Weather and currency exchange rate search");

    weather = new QLabel(this);
    weather->setText("Weather");
    usd = new QLabel(this);
    usd->setText("Dollar");
    eu = new QLabel(this);
    eu->setText("Euro");
    Open_Html = new QPushButton(this);
    Open_Html->setText("Open HTML");

    mainGrid->addWidget(condition, 0 ,0 , 1 , 2);
    mainGrid->addWidget(plane1, 1, 0, 4, 1);
    mainGrid->addWidget(weather, 1, 1);
    mainGrid->addWidget(usd, 2, 1);
    mainGrid->addWidget(eu, 3, 1);
    mainGrid->addWidget(Open_Html, 4, 1);

    this->setLayout(mainGrid);
    this->setWindowTitle("Parser HTML");

    connect(Open_Html, SIGNAL(clicked()), this, SLOT(on_Open_Html_clicked()));
}

void Html_pars::on_Open_Html_clicked() {
    QString fileName;
    try	{
    fileName = QFileDialog::getOpenFileName(nullptr,
            tr("Open file"), QDir::currentPath(), tr("Data Files (*.html)"));
    }
    catch (const std::exception&){
            fileName = "";
    }

    usd->clear();
    eu->clear();
    weather->clear();

    if (!fileName.isEmpty()){
        QFile file(fileName);
        QByteArray data; 
        if (!file.open(QIODevice::ReadOnly)) 
                        return;
        data = file.readAll(); 
        QString txtHtml(data);
        plane1->setPlainText(txtHtml);
        QStringList list = getParametr(txtHtml);
        usd->setText(list[0]);
        eu->setText(list[1]);
        weather->setText(list[2]);
    } else {
       plane1->setPlainText("Error!");
    }
}

QStringList Html_pars::getParametr(QString _str){ 

    QString strSearch = "https://news.mail.ru/currency/src/MOEX/charcode/USD/\",\"type\":\"USD\",\"rate\":";
    auto index = _str.indexOf(strSearch);
    auto indexLast = _str.indexOf(",", index + strSearch.size());
    QString dol = "$ " + _str.mid(index + strSearch.size(), indexLast - index - strSearch.size());

    strSearch = "https://news.mail.ru/currency/src/MOEX/charcode/EUR/\",\"type\":\"EUR\",\"rate\":";
    index = _str.indexOf(strSearch);
    indexLast = _str.indexOf(",", index + strSearch.size());
    QString eur = "E " + _str.mid(index + strSearch.size(),indexLast - index - strSearch.size());

   
    strSearch = "https://pogoda.mail.ru/prognoz/" ;
    index = _str.indexOf(strSearch);
    indexLast = _str.indexOf("/", index + strSearch.size());
    QString city = _str.mid(index + strSearch.size(), indexLast - index - strSearch.size());
    strSearch = "https://pogoda.mail.ru/prognoz/" + city + "/\",\"now\":{\"temp\":\"";
    index = _str.indexOf(strSearch);
    indexLast = _str.indexOf("\"", index + strSearch.size());
    QString weat = _str.mid(index + strSearch.size(), indexLast - index - strSearch.size());

    return QStringList() << dol << eur << city + ": " + weat;
}
