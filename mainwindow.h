#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "imageloader.h"

class  MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

    QGridLayout *mainGrid {nullptr}; 
    QPushButton *push_button_1 {nullptr};
    
    Imageloader *image_loader {nullptr};


 public slots:

    void push_button_1_clicked();
   


};

#endif // MAINWINDOW_H
