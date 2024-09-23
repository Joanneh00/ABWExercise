#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QLibrary>
#include <QDebug>
#include <QString>
#include <windows.h>

#include "customgraphicsview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadImageBtn_clicked();
    void on_thresholdROIBtn_clicked();
    void on_RectangleDrawn(const QRectF &rect);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    CustomGraphicsView *view;

    QGraphicsPixmapItem *imageItem;
    QRectF roiRect;

    void loadAndDisplayImage(const QString &filePath);
};
#endif // MAINWINDOW_H
