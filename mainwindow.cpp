#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    mainGrid = new QGridLayout (this);
    push_button_1 = new QPushButton (this);
    image_loader = new Imageloader (this);
    image_loader->setWindowFlag(Qt::Window);
    push_button_1->setText("Задание 1");
    mainGrid->addWidget(push_button_1, 1, 1, 1, 1);

    connect(push_button_1, SIGNAL(clicked()), this, SLOT(buttonOne_clicked()));

  
    this->setLayout(mainGrid);
}

void MainWindow::push_button_1_clicked()
{
   image_loader->resize(QSize(500, 100));
   image_loader->show();
}
