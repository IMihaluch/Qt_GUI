#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "quadr_calc.h"
#include "triangl_calc.h"
#include "plantext.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    QGridLayout *mainGrid; 
    QPushButton *push_button_1;
    QPushButton *push_button_2;
    QPushButton *push_button_3;

    quadr_calc *calc;
    triangl_calc *calcTriangl;
    planText *planTexte;

 public slots:

    void push_button_1_clicked();
    void push_button_2_clicked();
    void push_button_3_clicked();
};
#endif // MAINWINDOW_H
