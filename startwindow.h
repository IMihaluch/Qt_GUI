#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QtWidget>

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    startWindow(QWidget *parent = nullptr);
    ~StartWindow();
};
#endif // STARTWINDOW_H
