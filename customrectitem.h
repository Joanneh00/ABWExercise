#ifndef CUSTOMRECTITEM_H
#define CUSTOMRECTITEM_H

#include <QGraphicsItem>
#include "rect.h"

class CustomRectItem : public QGraphicsItem {
public:
    CustomRectItem(RECT* rect);
     QRectF boundingRect() const override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    RECT* m_rect;
};

#endif // CUSTOMRECTITEM_H
