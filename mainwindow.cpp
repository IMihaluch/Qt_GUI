#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    mainGrid = new QGridLayout(this);
    Files_Viewer = new System_viewer(this);
    push_button_1 = new QPushButton(this);
    push_button_1->setText("File system");
    mainGrid->addWidget(push_button_1, 1, 1, 1, 1);

    connect(push_button_1, &QPushButton::clicked, this, &MainWindow::push_button_1_clicked);

    Files_Viewer->setWindowFlags(Qt::Window);
    this->setLayout(mainGrid);
}

void MainWindow::push_button_1_clicked()
{
   Files_Viewer->show();
}
