#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTime>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Input->setPlaceholderText("Print file name here...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Seek_clicked()
{
    ui->textBrowser_Output->clear();
    ui->lineEdit_Input->setFocus();
    SeekLongestRows();
}

QString MainWindow::TakeLongestRow(QVector<QString> &Data)
{   QString qsLongest="1";
    int DeleteRow = 0;
     for (int i=0; i < Data.size(); i++){
        if (Data[i].length() > qsLongest.length()){
            qsLongest=Data.at(i);
            DeleteRow=i;
        }
    }
    Data.remove(DeleteRow);
    return qsLongest;
}

void MainWindow::SeekLongestRows()
{
    QVector<QString> FullDataRows;
    QVector<QString> LongestRows;
    QString qsTemp;
    QString InputFile = ui->lineEdit_Input->text();
 //   InputFile = "TestInput.txt";
    QFile file(InputFile);
    int SelectedRow = 0;

    if(file.size() == 0) {
        ui->textBrowser_Output->setText("Input file is empty");
        return;
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->textBrowser_Output->setText("Can't open input file!");
        return;
    } else {                                 // all rows from input file to QVector
        while (!file.atEnd()) {
            qsTemp = file.readLine();
            FullDataRows.push_back(qsTemp);
         }
        file.close();
     }
    LongestRows.push_back(" ");
    ui->textBrowser_Output->append("5 longest rows in format 'LENGHT : TEXT' is:\n");
    while (SelectedRow < 5){
        qsTemp = TakeLongestRow(FullDataRows);               //вырезаем самую длинную строку
        if (LongestRows.last().length() < qsTemp.length()){
             LongestRows.last() = qsTemp;
        } else {
            LongestRows.push_back(qsTemp);
           }
        QString qsSize= QString::number(LongestRows.last().length());   //int to QString
        ui->textBrowser_Output->append( qsSize +" : "+qsTemp);
        SelectedRow++;
    }
    bool bWtr = writeToFile(LongestRows);                      //записали результат в файл + время
    if (bWtr == true)
    {
        ui->textBrowser_Output->append( " Writed to file! " +QTime::currentTime().toString() );
     }
}

bool MainWindow::writeToFile(QVector<QString> Longest)
{
    QFile outFile("Output.txt");   //открыли файл
       if (!outFile.open(QIODevice::Truncate |QIODevice::Append | QIODevice::Text)){ // truncate = очистить файл!
           return false;
       } else {
           for (QString qsTmp : Longest) {  // vector -> построчно в файл
           outFile.write(qPrintable(qsTmp)); //из QString в char
          }
             outFile.close();
             return true;
          }
}





