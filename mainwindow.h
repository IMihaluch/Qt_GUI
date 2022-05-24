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

    QGridLayout *mainGrid {nullptr}; 
    QPushButton *push_button_1 {nullptr};

    System_viewer *Files_Viewer {nullptr};


 public slots:

    void push_button_1_clicked();
    
};

#endif // MAINWINDOW_H
