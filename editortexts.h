#ifndef EDITORTEXTS_H
#define EDITORTEXTS_H
#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include "settings.h"

class EditorTexts : public QWidget
{
    Q_OBJECT
public:
    explicit EditorTexts(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; 
    QPushButton *but_Open;
    QPushButton *but_Save;
    QPushButton *but_Help;

    QPlainTextEdit *Ed;

    QString qss = "QWidget{""background-color: hsl(0,0%,50%);""}"
                  "QPlainTextEdit{""background-color: hsl(0,0%,100%);""border-color: hsl(240,100%,50%);""border: 5px solid hsl(240,100%,50%);""}"
                  "QPushButton{""border-radius: 00px;""background-color: hsl(0,0%,50%);""qproperty-iconSize: 30px 30px;""}"
                  "QPushButton:pressed{"" border-radius: 10px;""background-color: hsl(240,100%,50%);""}";

    QString qssDark = "QWidget{""background-color: hsl(0, 0%, 21%);""text-color: hsl(0,0%,100%);""}"
                  "QPlainTextEdit{""background-color: hsl(0, 0%, 10%);""border-color: hsl(240,100%,50%);"
                      "             ""border: 5px solid hsl(240,100%,50%);""text-color: hsl(0,0%,100%);""}"
                  "QPushButton{""border-radius: 00px;""background-color: hsl(0, 0%, 21%);""qproperty-iconSize: 30px 30px;""}"
                  "QPushButton:pressed{"" border-radius: 10px;""background-color: hsl(240,100%,50%);""}";
signals:

public slots:
    void on_but_Open_clicked();
    void on_but_Save_clicked();
    void on_but_Help_clicked();
   };

#endif // EDITORTEXTS_H
