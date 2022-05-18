#ifndef GRAFEDIT_H
#define GRAFEDIT_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QtWidgets>
#include <QtGui>
#include <QMainWindow>

#include "figure.h"
#include "figure_afte.h"


class graphicsEditor : public QGraphicsView
{
public:
    graphicsEditor(QWidget *parent = nullptr);

private:
    QGraphicsView *view;
    QGraphicsScene *scence;

    void scaleView(int angle);

    int typeFigure = 1;

public slots:
    void updateView();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GRAFEDIT_H
