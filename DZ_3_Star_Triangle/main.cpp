//* 1TARvg  Orlov Vladislav
// Домашняя работа: Пирамида из строк-*


#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <iostream> // iostream для ввода и вывода на консоль

using namespace std ; //определить пространство имен std namespace на всю программу


//Предварительно объявим функции, значений они не возвращают - void

void printMSpaseAndLStars(int M,int L); //Строка из М пробелов и L звезд

void printTriangle(int N); //Вывод вызовом printMSpaseAndLStars N раз

// main program
int main()
{
    cout << "Hello user !\n";

    cout << "Enter a height of triangle : ";

    int height = 0;
    cin >> height;   //получили высоту пирамиды

    if (height == 0)
    {              // если введен 0
            cout << "Wrong number! Void strings will be printed! " << endl;

            }

    qDebug() << "Start, shall print triangle with"<< height << "rows" << endl << endl ;

    printTriangle(height); // Вызов printTriangle с аргументом height

    qDebug() << "End";
    return 0;
}

void printMSpaseAndLStars(int M,int L) //Function body, M spases and L stars counts
{
    QString qsOneRow = "     ";  // сдвинем чуть от края
    int Temp = M;                //локальные переменные Temp и STemp
    QString STemp = qsOneRow;

    for (int i=0; i<M; i++) qsOneRow+=' '; // += this is adding one char to end of string
    for (int i=0; i<L; i++) qsOneRow+='*'; // += can be use and to concatinate 2 and more strings together
    for (int i=0; i<Temp; i++) qsOneRow+=' ';

    qsOneRow = qsOneRow += STemp;          //выровняем строки для вывода с кавычками

    qDebug() << qsOneRow;                        // Now  show string borders

    //О, оказывается можно и без кавычек!
    //qDebug() << qsOneRow.toLocal8Bit().data(); //don't show string borders
}

void printTriangle(int height) //Function body
{

 //   qDebug() << "Hello from function printTriangle" << endl;
    for (int i=0; i<height; i++)    {

        // формируем строки, уменьшая в циклах пробелы и увеличивая количество *
        printMSpaseAndLStars((height-1)-i, (i*2)+1);
    }
    qDebug() << endl ;
}
