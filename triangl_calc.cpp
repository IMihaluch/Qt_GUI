#include "triangl_calc.h"

calculatorTriangle::calculatorTriangle(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    button_calc = new QPushButton(this);
    button_calc->setText("Calculate");

    side_A_edit = new QLineEdit(this);
    side_B_edit = new QLineEdit(this);
    ang_edit = new QLineEdit(this);

    grad = new QRadioButton(this);
    grad->setText("Angle in degrees");
    grad->setChecked(true);
    rad = new QRadioButton(this);
    rad->setText("Angle in radians");

    condition = new QLabel(this);
    condition->setText("Specify the sides of the triangle A, B and the angle between them to calculate the third side of the triangle.");
    answer = new QLabel(this);
    text_side_A = new QLabel(this);
    text_side_A->setText("Side А ");
    text_side_B = new QLabel(this);
    text_side_B->setText("Side В ");
    text_ang = new QLabel(this);
    text_ang->setText("Corner ");

    mainGrid->addWidget(condition, 0, 0, 1, 6);
    mainGrid->addWidget(text_side_A, 2, 0, 1, 1);
    mainGrid->addWidget(side_A_edit, 2, 1, 1, 1);
    mainGrid->addWidget(text_side_B, 2, 2, 1, 1);
    mainGrid->addWidget(side_B_edit, 2, 3, 1, 1);
    mainGrid->addWidget(text_ang, 2, 4, 1, 1);
    mainGrid->addWidget(ang_edit, 2, 5, 1, 1);
    mainGrid->addWidget(grad, 3, 4, 1, 2);
    mainGrid->addWidget(rad, 4, 4, 1, 2);
    mainGrid->addWidget(button_calc, 5, 3, 1, 2);
    mainGrid->addWidget(answer, 6, 3, 1, 3);

    connect(button_calc, SIGNAL(clicked()), this, SLOT(on_button_calc_clicked()));

    this->setLayout(mainGrid);
    this->setWindowTitle("Calculating the side of a polygon");
}

void triangl_calc::on_button_calc_clicked(){
    strsideA = sideAEdit->text();
    strsideB = sideBEdit->text();
    strang = ang_edit->text();
    strside_A.replace(",",".");
    strside_B.replace(",",".");
    strang.replace(",",".");
    if(strside_A == "" || strside_B == "" || strang == "") {
        QMessageBox msgBox;
        msgBox.setText("The data for the calculation is not entered correctly!");
        msgBox.exec();
    }
    side_A = strside_A.toDouble();
    side_B = strside_B.toDouble();
    ang = strang.toDouble();
    //заполнение edit  
    side_A_edit->setText(QString::number(side_A));
    side_B_edit->setText(QString::number(side_B));
    ang_edit->setText(QString::number(ang));

    if(grad->isChecked()) ang /= ( 180 / M_PI );

    result = qSqrt(qPow(side_A,2) + qPow(side_B,2) - 2*side_A*side_B*qCos(ang));
    answer->setText("The length of the third side is: " + QString::number(result));

}
