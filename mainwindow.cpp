#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    push_button_1 = new QPushButton(this);
     GrafEdit = new graphicsEditor(this);
    GrafEdit->setWindowFlags(Qt::Window);


    push_button_1->setText("Task 1");
   
    mainGrid->addWidget(push_button_1, 1, 1, 1, 1);
    

    connect(push_button_1, SIGNAL(clicked()), this, SLOT(push_button_1_clicked()));
  

    this->setLayout(mainGrid);


void MainWindow::push_button_1_clicked()
{
    GrafEdit->show();
}
