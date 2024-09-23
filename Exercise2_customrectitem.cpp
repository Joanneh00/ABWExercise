#include "customrectitem.h"

CustomRectItem::CustomRectItem(RECT* rect) : m_rect(rect) {}

QRectF CustomRectItem::boundingRect() const {
    return m_rect->rect();
}

void CustomRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    m_rect->draw(painter);
}
