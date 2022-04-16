#ifndef SPECIAL_CHAR_INSERT_H
#define SPECIAL_CHAR_INSERT_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "speccharparser.h"

class  special_char_insert : public QWidget
{
    Q_OBJECT
public:
    explicit  special_char_insert(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; 

    QPlainTextEdit *plane1;
    QLabel *condition;
    speccharParser *speccharParser;
signals:

public slots:
    void on_plainTextEdit_textAssig(); 
};

#endif // SPECIAL_CHAR_INSERT_H
