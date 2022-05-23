#include "figure.h"

Figure::Figure(QPoint *p, QObject *parent) : Scene(parent)
{
    if(p) {x = p->x();
        y = p->y();
    }
}
void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    QPainterPath figure;
    figure.moveTo(x+70, y);
    figure.lineTo(x+87, y+43);
    figure.lineTo(x+150, y+43);
    figure.lineTo(x+100, y+80);
    figure.lineTo(x+120, y+137);
    figure.lineTo(x+70, y+102);
    figure.lineTo(x+20, y+137);
    figure.lineTo(x+40, y+80);
    figure.lineTo(x, y+43);
    figure.lineTo(x+51, y+43);
    figure.lineTo(x+70, y);
    painter->drawPath(figure);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF Figure::boundingRect() const         
{
   return QRectF(x, y, 150, 137);                
}
