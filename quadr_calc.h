#ifndef QUADR_CALC_H
#define QUADR_CALC_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QtCore/qmath.h>

class quadr_calc : public QWidget
{
    Q_OBJECT
public:
    explicit quadr_calc(QWidget *parent = nullptr);

    QGridLayout *mainGrid; 
    QPushButton *button_сalc;
    QPushButton *button_Cls;

    QLineEdit *num_A;
    QLineEdit *num_B;
    QLineEdit *num_C;

    QLabel *condition;
    QLabel *answer;
    QLabel *text_x2;
    QLabel *text_x;
    QLabel *text_equality;

private:
    double numA, numB, numC, numD, result_x1, result_x2;
    QString numA_txt, numB_txt, numC_txt;

signals:

public slots:
    void on_button_calc_clicked();
    void on_button_Cls_clicked();
};

#endif // QUADR_CALC_H
