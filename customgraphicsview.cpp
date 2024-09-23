#include "CustomGraphicsView.h"

CustomGraphicsView::CustomGraphicsView(QGraphicsScene *scene, QWidget *parent)
    : QGraphicsView(scene, parent), drawing(false), rectItem(nullptr)
{
}

void CustomGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPointF scenePos = mapToScene(event->pos());
        drawing = true;

        if (rectItem) {
            scene()->removeItem(rectItem);
        }

        rectItem = new QGraphicsRectItem(QRectF(scenePos, scenePos));
        rectItem->setPen(QPen(Qt::red, 2));
        scene()->addItem(rectItem);
    }
}

void CustomGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (drawing && rectItem) {
        QPointF scenePos = mapToScene(event->pos());
        QRectF rect = rectItem->rect();
        rect.setBottomRight(scenePos);
        rectItem->setRect(rect);
    }
}

void CustomGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        drawing = false;
        if (rectItem) {
            emit rectangleDrawn(rectItem->rect());//this is the point
        }
    }
}
