#ifndef FIGURE_H
#define FIGURE_H
#include "scene.h"

class Figure : public Scene
{
public:
    explicit Figure(QPoint *p = nullptr, QObject *parent = nullptr);


private:
       void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
       QRectF boundingRect() const override;
};

#endif // FIGURE_H
