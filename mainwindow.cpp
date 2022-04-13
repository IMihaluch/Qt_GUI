#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    mainGrid = new QGridLayout(this);

    push_button_1 = new QPushButton(this);
    
    push_button_1->setText("Task 2");
    
    html_pars = new Html_pars(this);
    html_pars->setWindowFlags(Qt::Window);
    
    mainGrid->addWidget(push_button_1, 1, 1, 1, 1);
    
    connect(push_button_1, SIGNAL(clicked()), this, SLOT(push_button_1_clicked()));
    
    this->setLayout(mainGrid);

    }

void MainWindow::push_button_1_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Task 2);
    msgBox.exec();
    html_pars->show();
}


