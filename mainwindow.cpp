#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene)
{
    ui->setupUi(this);
    view = new CustomGraphicsView(scene,this);
    ui->vLayout->addWidget(view);

    connect(view, &CustomGraphicsView::rectangleDrawn,this,&MainWindow::on_RectangleDrawn);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadImageBtn_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this,"","","*.png *.jpg *.jpeg");
    if(!filepath.isEmpty()){
        loadAndDisplayImage(filepath);
    }
}


void MainWindow::on_thresholdROIBtn_clicked()
{
    if (!roiRect.isNull()) {
        // Extract and process the grayscale ROI for thresholding
        QImage grayscaleImage = imageItem->pixmap().toImage().convertToFormat(QImage::Format_Grayscale8);
        // Convert QRectF to QRect
        QRect roi = roiRect.toRect();
        // Extract the ROI from the image
        QImage roiImage = grayscaleImage.copy(roi);

        // Load the DLL
        QLibrary lib("D:/Qt/1009/release/thresholding.dll");
        if (!lib.load()) {
            qDebug() << "Cannot load DLL:" << lib.errorString();
            return;
        }
        qDebug() << "DLL loaded successfully";

        // Get the function pointer
        typedef void (*ThresholdFunc)(unsigned char*, int, int, int);
        ThresholdFunc thresholdFunc = (ThresholdFunc)lib.resolve("thresholdFunc");

        if (!thresholdFunc) {
            qDebug() << "Cannot find thresholdFunc:" << lib.errorString();
            return;
        }

        // Create a copy of the image data
        QImage binaryImage = roiImage.copy();

        // Call the threshold function
        int threshold =255/2;
        thresholdFunc(binaryImage.bits(), binaryImage.width(), binaryImage.height(), threshold);

        // Create a new QGraphicsScene and QGraphicsView for new window
        QGraphicsScene *roiScene = new QGraphicsScene(this);
        QGraphicsView *roiView = new QGraphicsView(roiScene);

        // Add the binary image to the scene
        roiScene->addPixmap(QPixmap::fromImage(binaryImage));

        // Set up the a new window
        roiView->setWindowTitle("Thresholded ROI Image");
        roiView->show();
    } else {
        QMessageBox::warning(this, "Warning", "Please select an ROI first.");
    }
}


void MainWindow::on_RectangleDrawn(const QRectF &rect)
{
    roiRect = rect;
}

void MainWindow::loadAndDisplayImage(const QString &filePath){
    QPixmap image(filePath);
    if(!image.isNull()){
        scene->clear();
        imageItem = scene->addPixmap(image);
        view->fitInView(imageItem,Qt::KeepAspectRatio);

    }
}
