#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Seek_clicked();
     QString TakeLongestRow(QVector<QString> &Data );
     void SeekLongestRows();
     bool writeToFile(QVector<QString> Longest);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
