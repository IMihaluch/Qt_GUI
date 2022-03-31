#ifndef PLANTEXT_H
#define PLANTEXT_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

class planText : public QWidget
{
    Q_OBJECT
public:
    explicit planText(QWidget *parent = nullptr);

    QGridLayout *mainGrid; 
    QPushButton *button_text_to_sec;
    QPushButton *button_replace_text_one;
    QPushButton *button_append_Html_text_sec;

    QPlainTextEdit *plane1;
    QPlainTextEdit *plane2;

    QLabel *condition;
    QLabel *one_text;
    QLabel *sec_text;
signals:

public slots:
    void on_button_text_to_2_clicked();
    void on_button_replace_text_1_clicked();
    void on_button_append_Html_text_2_clicked();
};

#endif // PLANTEXT_H
