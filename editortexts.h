#ifndef EDITORTEXTS_H
#define EDITORTEXTS_H
#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

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

    QPlainTextEdit *editor;

    QCheckBox *cbDark;

    QString qss = "QWidget{""background-color: rgb(239, 239, 239);""}"
                  "QPlainTextEdit{""background-color: rgb(255, 255, 255);""border-color: rgb(0, 179, 255);""border: 5px solid rgb(0, 179, 255);""}"
                  "QPushButton{""border-radius: 00px;""background-color: rgb(239, 239, 239);""qproperty-iconSize: 28px 28px;""}"
                  "QPushButton:pressed{"" border-radius: 10px;""background-color: rgb(0, 179, 255);""}";

    QString qssDark = "QWidget{""background-color: rgb(53, 53, 53);""text-color: rgb(255, 255, 255);""}"
                  "QPlainTextEdit{""background-color: rgb(25, 25, 25);""border-color: rgb(0, 179, 255);"
                      "             ""border: 5px solid rgb(0, 179, 255);""text-color: rgb(255, 255, 255);""}"
                  "QPushButton{""border-radius: 00px;""background-color: rgb(53, 53, 53);""qproperty-iconSize: 28px 28px;""}"
                  "QPushButton:pressed{"" border-radius: 10px;""background-color: rgb(0, 179, 255);""}";
signals:

public slots:
    void on_but_Open_clicked();
    void on_but_Save_clicked();
    void on_but_Help_clicked();
    void on_cbDark_clicked();
};

#endif // EDITORTEXTS_H
