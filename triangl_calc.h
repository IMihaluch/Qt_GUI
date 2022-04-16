#ifndef TRIANGL_CALC_H
#define TRIANGL_CALC_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QtCore/qmath.h>

class triangl_calc : public QWidget
{
    Q_OBJECT
public:
    explicit triangl_calc(QWidget *parent = nullptr);

    QGridLayout *mainGrid; 
    QPushButton *button_calc;

    QRadioButton *grad;
    QRadioButton *rad;

    QLineEdit *side_A_edit;
    QLineEdit *side_B_edit;
    QLineEdit *ang_edit;

    QLabel *condition;
    QLabel *answer;
    QLabel *text_side_A;
    QLabel *text_side_B;
    QLabel *text_ang;

    double side_A, side_B, ang, result;
    QString strside_A, strside_B, strang;

signals:

public slots:
    void on_button_calc_clicked();
};

#endif // TRIANGL_CALC_H
