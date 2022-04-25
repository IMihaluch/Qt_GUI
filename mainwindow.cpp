#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    push_button_1 = new QPushButton(this);

    FSV = new System_viewer(this);

    push_button_1->setText("File system");

    mainGrid->addWidget(push_button_1, 1, 1, 1, 1);

    connect(push_button_1, &QPushButton::clicked, this, &MainWindow::push_button_1_clicked);

    FSV->setWindowFlags(Qt::Window);
    this->setLayout(mainGrid);
}

void MainWindow::push_button_1_clicked()
{
    FSV->show();
}

void MainWindow::push_button_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Task 2");
    msgBox.exec();
}

void MainWindow::push_button_3_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Task 3");
    msgBox.exec();
}

