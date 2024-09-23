#ifndef RECT_H
#define RECT_H

#include <QRectF>
#include <QPainter>

class RECT {
public:
    RECT(qreal x, qreal y, qreal width, qreal height);
    virtual ~RECT() = default;

    virtual void draw(QPainter* painter) const = 0;
    QRectF rect() const;

protected:
    QRectF m_rect;
};

class SquaredRect : public RECT {
public:
    SquaredRect(qreal x, qreal y, qreal width, qreal height);
    void draw(QPainter* painter) const override;
};

class RoundedRect : public RECT {
public:
    RoundedRect(qreal x, qreal y, qreal width, qreal height, qreal radius);
    void draw(QPainter* painter) const override;
    void setRadius(qreal radius);
    qreal radius() const;

private:
    qreal m_radius;
};

#endif // RECT_H
