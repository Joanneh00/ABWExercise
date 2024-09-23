#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ABWImage.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>

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
    //manage image viewer
    void on_loadBtn_clicked();
    void on_displayBtn_clicked();
    void on_prevBtn_clicked();
    void on_nextBtn_clicked();
    void on_unloadBtn_clicked();

    //manage table
    void on_selectImgsBtn_clicked();

private:
    Ui::MainWindow *ui;
    QVector<ABWImage*> myImages;
    int displayIndex;
    QGraphicsScene *scene;
    QGraphicsView *view;

    //manage image viewer
    void setupView();
    void displayImages();

    //manage table
    void updateTable();
};
#endif // MAINWINDOW_H
