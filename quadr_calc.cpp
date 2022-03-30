#include "quadr_calc.h"

quadr_calc::quadr_calc(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    button_calc = new QPushButton(this);
    button_calc->setText("Calculate");
    button_Cls = new QPushButton(this);
    button_Cls->setText("Clear");

    num_A = new QLineEdit(this);
    num_B = new QLineEdit(this);
    num_C = new QLineEdit(this);

    condition = new QLabel(this);
    condition->setText("Specify the coefficients A, B and C the quadratic equation Ax^2 + Bx + C = 0");
    answer = new QLabel(this);
    text_x2 = new QLabel(this);
    text_x2->setText("x^2 + ");
    text_x = new QLabel(this);
    text_x->setText(" x + ");
    text_equally = new QLabel(this);
    text_equally->setText(" = 0");

    mainGrid->addWidget(condition, 0, 0, 1, 6);
    mainGrid->addWidget(num_A, 2, 0, 1, 1);
    mainGrid->addWidget(text_x2, 2, 1, 1, 1);
    mainGrid->addWidget(num_b, 2, 2, 1, 1);
    mainGrid->addWidget(text_x, 2, 3, 1, 1);
    mainGrid->addWidget(num_C, 2, 4, 1, 1);
    mainGrid->addWidget(text_equally, 2, 5, 1, 1);
    mainGrid->addWidget(button_Cls, 4, 0, 1, 2);
    mainGrid->addWidget(button_сalc, 4, 3, 1, 2);
    mainGrid->addWidget(answer, 5, 3, 2, 3);

    connect(button_сalc, SIGNAL(clicked()), this, SLOT(on_button_calc_clicked()));
    connect(button_Cls, SIGNAL(clicked()), this, SLOT(on_button_Cls_clicked()));

    this->setLayout(mainGrid);

    this->setWindowTitle("Calculation of the quadratic equation");
}


void quadr_calc::on_button_calc_clicked(){
    numA_txt = numA->text();
    numB_txt = numB->text();
    numC_txt = numC->text();
    //проверка на пустой ввод
    if( numA_txt == "" && numB_txt == "" && numC_txt == ""){
        QMessageBox msgBox;
        msgBox.setText("The data for the calculation is not entered!");
        msgBox.exec();
    }
    
    numA_txt.replace(",",".");
    numB_txt.replace(",",".");
    numC_txt.replace(",",".");
    numA = numA_txt.toDouble();
    numB = numB_txt.toDouble();
    numC = numC_txt.toDouble();
    //заполнение edit значениями 
    num_A->setText(QString::number(numA));
    num_B->setText(QString::number(numB));
    num_C->setText(QString::number(numC));

    numD = qPow(numB, 2) - 4 * numA * numC;
    if(!qFuzzyCompare(numA,0.0) && numD >= 0){
        result_x1 = ((-1 * numB) + qSqrt(numD))/(2*numA);
        result_x2 = ((-1 * numB) - qSqrt(numD))/(2*numA);
    } else if(qFuzzyCompare(numA, 0.0)) {
        result_x1 = result_x2 = (-1 * numC)/numB;
        numD = 0;
    }

    if(numD > 0){
        answer->setText("Result: D = " + QString::number(numD) +
                        "\n x1 = " + QString::number(result_x1) +
                        "\n x2 = " +QString::number(result_x2));
    } else if (numD < 0){
        numD *= -1;
        answer->setText("Result: D = " + QString::number(numD * (-1)) +
                        "\n x1 = " + QString::number((-1 * numB)/(2*numA)) + "+" + QString::number(qSqrt(numD)/(2*numA)) + "j" +
                        "\n x2 = " +QString::number((-1 * numB)/(2*numA)) + "-" + QString::number(qSqrt(numD)/(2*numA)) + "j" );
    } else {
        answer->setText("Result: D = " + QString::number(numD) +
                        "\n x = " + QString::number(result_x1));
    }

}

void quadr_calc::on_button_Cls_clicked(){
    num_A->setText("");
    num_B->setText("");
    num_C->setText("");
}
