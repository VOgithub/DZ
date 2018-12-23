#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString style = "QMainWindow { background-color:  #004466; }"; // color через Qstring!!
    this->setStyleSheet(style);

    ui->label_LCD->setStyleSheet("color: white;"); //color напрямую объекту
     ui->label_Data->setStyleSheet("color: white;");

    tmr = new QTimer(this); //  объект класса QTimer и адрес> переменной tmr
    tmr->setInterval(500); // Задаем интервал 0.5 sek
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime())); // Подключаем сигнал таймера к слоту
    tmr->start(); // поехали!
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tmr;
}

void MainWindow::updateTime()
{
    QString qsTmp = QTime::currentTime().toString();
    QStringList qslTmpList = qsTmp.split(':');
    ui->label_Data->setText(QDate::currentDate().toString());

   if (qslTmpList[2].toInt()% 2 == 0){
       qsTmp = qsTmp.replace(":"," ");   //     тиканье
       ui->label_LCD->setText(qsTmp); // to LCD
   } else {
    ui->label_LCD->setText(QTime::currentTime().toString()); // to LCD
}
}
