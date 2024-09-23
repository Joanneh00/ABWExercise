#include "rect.h"

// RECT implementations
RECT::RECT(qreal x, qreal y, qreal width, qreal height)
    : m_rect(x, y, width, height) {}

QRectF RECT::rect() const {
    return m_rect;
}

// SquaredRect implementations
SquaredRect::SquaredRect(qreal x, qreal y, qreal width, qreal height)
    : RECT(x, y, width, height) {}

void SquaredRect::draw(QPainter* painter) const {
    painter->drawRect(m_rect);
}

// RoundedRect implementations
RoundedRect::RoundedRect(qreal x, qreal y, qreal width, qreal height, qreal radius)
    : RECT(x, y, width, height), m_radius(radius) {}

void RoundedRect::draw(QPainter* painter) const {
    painter->drawRoundedRect(m_rect, m_radius, m_radius);
}

void RoundedRect::setRadius(qreal radius) {
    m_radius = radius;
}

qreal RoundedRect::radius() const {
    return m_radius;
}
