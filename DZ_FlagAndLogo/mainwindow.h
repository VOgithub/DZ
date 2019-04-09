#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Flag_clicked();

    void on_pushButton_Logo_clicked();

    void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
  //  QGraphicsRectItem *rec;
  //  QGraphicsLineItem *line;
 //   QGraphicsTextItem *text;
    bool bFlag=false; // modify colors and line


};

#endif // MAINWINDOW_H
