#include "figure_afte.h"

Ellips::Figure_afte(QPoint *p, QObject *parent) : Scene(parent)
{
    if(p) {x = p->x();
        y = p->y();
    }
}

void Figure_afte::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    painter->drawEllipse(x, y, 300, 150);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF Figure_afte::boundingRect() const         
{
   return QRectF(x, y, 300, 150);
}
