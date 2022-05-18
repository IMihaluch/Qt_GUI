#include "grafedit.h"

graphic_elements::graphic_elements(QWidget *parent)
    : QGraphicsView(parent)
{
    scence = new QGraphicsScene(this);                      
    this->setScene(scence);
    this->setInteractive(true);
    this->setDragMode(QGraphicsView::RubberBandDrag);
    setFixedSize(720, 520);
    int x = 500, y = 700;
    scence->setSceneRect(0,0,y,x);
}  
void graphic_elements::scaleView(int angle)
{
    const ViewportAnchor anchor = this->transformationAnchor();
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    qreal factor = angle > 0 ? 1.1 : 0.9;
    scale(factor, factor);
    setTransformationAnchor(anchor);
}
void graphic_elements::updateView()
{
    scence->update();
    this->update();
}
void graphic_elements::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && this->itemAt(event->pos()) == nullptr) 
{       
        QPoint p = event->pos();
        if(typeFigure == 1) 
{
            Rect *rect = new Rect(&p);
            scence->addItem(rect);
            QObject::connect(rect, &Rect::reDraw, this, &graphic_elements::updateView);
            typeFigure = 2;
        } 
else if(typeFigure == 2) 
{
            Figure *el = new Figure(&p);
            scence->addItem(el);
            QObject::connect(el, &Figure::reDraw, this, &graphic_elements::updateView);
            typeFigure = 1;
        }
}
    if (event->button() == Qt::RightButton && this->itemAt(event->pos()) != nullptr)       
    {
        QGraphicsItem *item = itemAt(event->pos()); 
        delete item;
        updateView();
    }
QGraphicsView::mousePressEvent(event);  

void graphic_elements::wheelEvent(QWheelEvent *event)
{
    int angle = event->angleDelta().y(); 
    scaleView(angle);
    QGraphicsView::wheelEvent(event);
}
void graphic_elements::keyPressEvent(QKeyEvent *event)
{
    int angle = 0;
    if (event->key() == Qt::Key_Minus)
{
        angle = -1;
        scaleView(angle);
    } else if (event->key() == Qt::Key_Plus) {
        angle = 1;
        scaleView(angle);
    }
    QGraphicsView::keyPressEvent(event);
}
