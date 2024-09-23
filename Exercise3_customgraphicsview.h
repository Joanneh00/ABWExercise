#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsRectItem>

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT;

public:
    explicit CustomGraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:
    void rectangleDrawn(const QRectF &rect);  // Signal to inform that a rectangle was drawn

private:
    bool drawing;
    QGraphicsRectItem *rectItem;
};

#endif // CUSTOMGRAPHICSVIEW_H
