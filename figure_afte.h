#ifndef FIGURE_AFTE_H
#define FIGURE_AFTE_H

#include "scene.h"

class Figure_afte : public Scene
{
public:
    explicit Figure_afte(QPoint *p = nullptr, QObject *parent = nullptr);


private:
       void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
       QRectF boundingRect() const override;
};

#endif // FIGURE_AFTE_H
