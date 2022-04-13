#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QByteArray>
#include <QFile>

class Html_pars: public QWidget
{
    Q_OBJECT
public:
    explicit Html_pars(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; 
    QPlainTextEdit *plane1;
    QLabel *condition;
    QLabel *weather;
    QLabel *usd;
    QLabel *eu;
    QPushButton *Open_Html;

    QStringList getParametr(QString _str);
signals:

public slots:
    void on_Open_Html_clicked();

};



#endif // HTMLPARSER_H
