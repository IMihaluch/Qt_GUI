#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "System_viewer.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

    QGridLayout *mainGrid; 
    QPushButton *push_button_1;

    System_viewer *FSV;


 public slots:

    void push_button_1_clicked();
    void push_button_2_clicked();
    void push_button_3_clicked();

};

#endif // MAINWINDOW_H
