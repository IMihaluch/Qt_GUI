#include "scene.h"

Scene::Scene(QObject *parent) : QObject(parent), QGraphicsItem()
{x, y = 0;
    brush.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
    brush.setStyle(Qt::BrushStyle::SolidPattern); 
    setPos(x,y);
    moving = false;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) {       
       moving = true;                            
       bpoint = event->pos().toPoint();          
       emit reDraw();
   }
   else if (event->button() == Qt::MiddleButton) {       
       rotateFigure = true;                          
       bpoint = event->pos().toPoint();          
       emit reDraw();
   }
   }

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) {
       moving = false;                            
       emit reDraw();
   }
   else if (event->button() == Qt::MiddleButton) {       
       rotateFigure = false;                     
       emit reDraw();
   }
   
   QGraphicsItem::mouseReleaseEvent(event);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
   if (moving) {
       QPoint p = event->pos().toPoint() - bpoint; 
       x += p.x();
       y += p.y();
       bpoint = event->pos().toPoint();           
       emit reDraw();                             
   }
   else if(rotateFigure){
       QPoint p = event->pos().toPoint();
       int angle = 0;
       angle = static_cast<int> ( qRadiansToDegrees(atan2(p.x()-bpoint.x(), p.y()-bpoint.y()) ));

       QTransform t;
       QPointF xlate = boundingRect().center();
       t.translate(xlate.x(), xlate.y());
       t.rotate(angle);
       t.translate(-xlate.x(), -xlate.y());
       setTransform(t);

       emit reDraw();
   }

   QGraphicsItem::mouseMoveEvent(event);
}
