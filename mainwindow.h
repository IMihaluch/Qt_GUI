#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include "grafedit.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

    QGridLayout *mainGrid; 
    QPushButton *push_button_1;
    QPushButton *push_button_2;
    QPushButton *push_button_3;

 public slots:

   void push_button_1_clicked();
    void push_button_2_clicked();
    void push_button_3_clicked();
private:
    graphic_elements *GrafElement {nullptr};

};

#endif // MAINWINDOW_H
