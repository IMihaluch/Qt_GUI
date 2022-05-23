#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <cmath>
#include <QGraphicsItem>
#include <QContextMenuEvent>
#include <QBrush>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>


class Scene : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
 
public:
        explicit Scene(QObject *parent = nullptr);

signals:
        void reDraw();

private:
       void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;
       QRectF boundingRect() const override = 0;

protected:
       int x, y; 
       QPoint bpoint;
       bool moving; 
       bool rotateFigure; 
       QBrush brush;

       void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
       void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
       void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
