#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "parserhtml.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; 
    QPushButton *push_button_1;
    
    Html_pars *html_pars;

 public slots:

    void push_button_1_clicked();
    void push_button_2_clicked();
    void push_button_3_clicked();
};
#endif // MAINWINDOW_H
