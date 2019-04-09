#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMinimumHeight(640);
    this->setMinimumWidth(480);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor("#e2e5dd"), Qt::SolidPattern));
 //   ui->graphicsView->setAlignment(Qt::AlignLeft);//|Qt::AlignLeft);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Flag_clicked()
{
      QBrush blueBrush(QColor("#1791ff")); // Задаём кисть
      QBrush blackBrush(QColor("#000000")); // Задаём кисть
      QBrush whiteBrush(QColor("#ffffff")); // Задаём кисть


      scene->addRect(0,-115, 363,77, Qt::NoPen, blueBrush);
      scene->addRect(0,-38, 363,77, Qt::NoPen, blackBrush);
      scene->addRect(0,38, 363,77, Qt::NoPen, whiteBrush);

}

void MainWindow::on_pushButton_Logo_clicked()
{   int x,y;

    QPen DotLinePen(QColor("#1791ff"));
    DotLinePen.setWidth(2);
    DotLinePen.setStyle(Qt::DotLine);
    DotLinePen.setCapStyle(Qt::RoundCap);

    QPen SolidLinePen(QColor("#1791ff"));
    SolidLinePen.setWidth(2);
    SolidLinePen.setStyle(Qt::SolidLine);
    SolidLinePen.setCapStyle(Qt::SquareCap);


    QBrush blueBrush(QColor("#1791ff")); // Задаём кисть //23,145,255
    QBrush whiteBrush(QColor("#ffffff")); // Задаём кисть

  //  qDebug() << "bFlag form Logo= " << bFlag;

    x=534;  //start point for One
    y=-104;
    QPainterPath iOne = QPainterPath(QPointF(x, y)); // One figure
    iOne.lineTo(x,y + 210);
    iOne.lineTo(x-51, y + 210);
    iOne.lineTo(x-51, y + 24);
    iOne.closeSubpath();

    if (bFlag != true){
     scene->addEllipse(QRectF(550.0,7.0,102.0,102.0),SolidLinePen, blueBrush);  //r= 51
     scene->addEllipse(QRectF(550.0,-107.0,102.0,102.0),SolidLinePen , blueBrush);
     scene->addPath(iOne,SolidLinePen, blueBrush);
    }
    else
    {
        scene->addEllipse(QRectF(550.0,7.0,102.0,102.0),DotLinePen, whiteBrush);  //r= 51
        scene->addEllipse(QRectF(550.0,-107.0,102.0,102.0), DotLinePen, whiteBrush);
        scene->addPath(iOne,DotLinePen, whiteBrush);
    }

}

void MainWindow::on_radioButton_clicked()
{
  // qDebug() << "bFlag = " << bFlag;

    if (bFlag == false) bFlag=true;
    else bFlag = false;

  //  qDebug() << "bFlag = " << bFlag;
}
