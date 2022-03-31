#include "planText.h"

planText::planText(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    button_text_to_sec = new QPushButton(this);
    button_text_to_sec->setText("Add from 1 to 2");
    button_replace_text_one = new QPushButton(this);
    button_replace_text_one->setText("Replace in 1 on 2");
    button_append_Html_text_sec = new QPushButton(this);
    button_append_Html_text_sec->setText("Add in 2 HTML");

    condition = new QLabel(this);
    condition->setWordWrap(true);
    condition->setText("The first button will add text from"
                         "from one text widget to another, the second"
                         " button - replace text in one widget with "
                         "text in another widget. Add a third button,"
                         " which inserts into one of the text widget "
                         "the text of an arbitrary html code");
    one_text = new QLabel(this);
    one_text->setText("Input field №1");
    sec_text = new QLabel(this);
    sec_text->setText("Input field №2");

    plane1 = new QPlainTextEdit(this);
    plane2 = new QPlainTextEdit(this);

    mainGrid->addWidget(condition, 0, 0, 1, 6);
    mainGrid->addWidget(one_text, 2, 0, 1, 3);
    mainGrid->addWidget(sec_text, 2, 3, 1, 3);
    mainGrid->addWidget(plane1, 3, 0, 1, 3);
    mainGrid->addWidget(plane2, 3, 3, 1, 3);
    mainGrid->addWidget(button_text_to_sec, 4, 0, 1, 2);
    mainGrid->addWidget(button_replace_text_one, 4, 2, 1, 2);
    mainGrid->addWidget(button_append_Html_text_sec, 4, 4, 1, 2);

    connect(button_text_to_sec, SIGNAL(clicked()), this, SLOT(on_button_text_to_2_clicked()));
    connect(button_replace_text_one, SIGNAL(clicked()), this, SLOT(on_button_replace_text_1_clicked()));
    connect(button_append_Html_text_sec, SIGNAL(clicked()), this, SLOT(on_button_append_Html_text_2_clicked()));

    this->setLayout(mainGrid);
    this->setWindowTitle("QPlainTextEdit");
}


void planText::on_button_text_to_2_clicked(){
    plane2->appendPlainText(plane1->toPlainText());
}

void planText::on_button_replace_text_1_clicked(){
    plane1->clear();
    plane1->appendPlainText(plane2->toPlainText());
}

void planText::on_button_append_Html_text_2_clicked(){
    plane2->appendHtml("<font color='red'>Hello</font>");
}
