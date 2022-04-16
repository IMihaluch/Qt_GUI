#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "special_char_insert.h"
#include "prog_language.h"
#include "ListID_PC.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; 
    QPushButton *push_button_1;
    QPushButton *push_button_2;
    QPushButton *push_button_3;

    special_char_insert *specchar;
    prog_language *proglanguage;
    ListID_PC *ListID;

 public slots:

    void push_button_1_clicked();
    void push_button_2_clicked();
    void push_button_3_clicked();
};
#endif // MAINWINDOW_H
