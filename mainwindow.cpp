#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    mainGrid = new QGridLayout(this);

    push_button_1 = new QPushButton(this);
    push_button_2 = new QPushButton(this);
    push_button_3 = new QPushButton(this);

    push_button_1->setText("Task 1");
    push_button_2->setText("Task 2");
    push_button_3->setText("Task 3");
    mainGrid->addWidget(push_button_1, 1, 1, 1, 1);
    mainGrid->addWidget(push_button_2, 3,1,1,1);
    mainGrid->addWidget(push_button_3, 5, 1, 1, 1);

    connect(push_button_1, SIGNAL(clicked()), this, SLOT(push_button_1_clicked()));
    connect(push_button_2, SIGNAL(clicked()), this, SLOT(push_button_2_clicked()));
    connect(push_button_3, SIGNAL(clicked()), this, SLOT(push_button_3_clicked()));

    this->setLayout(mainGrid);

    specchar = new special_char_insert(this);
    specchar->setWindowFlags(Qt::Window);
    proglanguage = new prog_language(this);
    proglanguage->setWindowFlags(Qt::Window);
    ListID = new ListID_PC(this);
    ListID->setWindowFlags(Qt::Window);
}

void MainWindow::push_button_1_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Task 1);
    msgBox.exec();
    specchar->show();
}

void MainWindow::push_button_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Task 2");
    msgBox.exec();
    proglanguage->show();
}

void MainWindow::push_button_3_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Task 3");
    msgBox.exec();
    ListID->show();
}

