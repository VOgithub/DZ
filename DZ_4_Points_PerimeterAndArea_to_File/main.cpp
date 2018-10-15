//1TARvg17  Orlov Vladislav
// HomeWork #4
// вычисление площади  и периметра четырехугольника, запись в файл результата

// подключаем библиотеки
#include <QCoreApplication>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>

using namespace std; //определить простанство имен std namespace на всю программу

struct Point {    //описали Структуру Point, глобальная
    int x;
    int y;
    char Name;  //имя точки
};

float Distance(Point A, Point B); // функция вычисления дистанции между точками
float Perimeter(Point Array[4]);  //  функция вычисления всего периметра
float Area (Point Array[4]);      //функция вычисления площади по Гауссу

void writeFile (Point Array[], float &per, float &area);  //функция записи в файл
QString printQuad(Point Arr[4]);  //функция вывода координат четырехугольника

int main()
{
    float fPerim, fArea; //переменные для периметра и площади

    QFile resFile ("result.txt"); //если файл существует - удаляем!
    resFile.remove();

    Point pQuadOne[4]; // задаем координаты точек

        pQuadOne[0].Name='A';
        pQuadOne[0].x=0.0;
        pQuadOne[0].y=0.0;

        pQuadOne[1].Name='B';
        pQuadOne[1].x=3.0;
        pQuadOne[1].y=7.0;

        pQuadOne[2].Name='C';
        pQuadOne[2].x=7.0;
        pQuadOne[2].y=7.0;

        pQuadOne[3].Name='D';
        pQuadOne[3].x=7.0;
        pQuadOne[3].y=0.0;

 cout << "Hello! \n";

 qDebug() << printQuad(pQuadOne); //вывели полученные точки
 cout<< endl;
 fPerim = Perimeter(pQuadOne);
 fArea = Area(pQuadOne);
 cout << "The perimeter of the tetragon is " << fPerim <<" and area of the tatragon is " << fArea << ";" << endl;

 cout<< "Start write in file...";
writeFile (pQuadOne, fPerim, fArea);
cout<< "Done!"<< endl;

return 0;
}

void writeFile (Point pArray[], float &per, float &area){
    QFile resFile ("result.txt");
        if (resFile.open(QFile::WriteOnly |QFile::Append )){
            QTextStream out(&resFile);
            out<<"Points coordinates : \r\n";
            for (int i=0; i<4; i++){
                out<<"Point #"<< i+1<< " - '"<< pArray[i].Name <<"': ["<<pArray[i].x<<";"<<pArray[i].y<<"]\r\n";
            }
            out << "The perimeter of the tetragon is "<< per << ";\r\n";
            out << "The total area of the tetragon is " << area << ";\r\n";
            out<<"\r\n";
}   }

float Area(Point Array[4]){  //функция вычисления площади по Гауссу ( формула шнурования)
//    qDebug() << printQuad(Array);

    float fArea = abs
            (0.5*(Array[0].x*Array[1].y+Array[1].x*Array[2].y +Array[2].x*Array[3].y
            +Array[3].x*Array[0].y-Array[1].x*Array[0].y-Array[2].x*Array[1].y-
            Array[3].x*Array[2].y-Array[0].x*Array[3].y));

//    cout << "The total area of the tatragon is " << fArea << ";" << endl;
    cout<< endl;
    return fArea;

}

float Distance (Point a, Point b)
{
   float A;
   A= sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
 //   cout << "Distance between point " << a.Name << " and point "<< b.Name << " is - "<< A << endl;
   return A;
}

float Perimeter(Point Array[4]){
    float per=0;
 //   qDebug() << printQuad(Array);
    for(int i=0;i<4;++i){
 //        cout << "i in Perimeter="<< i << ", Array[i]=" << Array[i].x << ":"<<Array[i].y << endl;
        if ((i+1)==4){
            per = per +Distance(Array[i], Array[0]);

        } else {
        per = per + Distance(Array[i], Array[i+1]);
        }
     }
//     cout<<"The perimeter of all the tetragon is " << per << ";" << endl;
    cout<< endl;
    return per;
}
QString printQuad(Point Arr[4])  //функция вывода координат четырехугольника
{
    QString qsRetVal = "Quadrilateral with points: ";
    QString qsTemp;
 //   Point curPoint;
    for (int i=0; i<4; i++){
        qsTemp = "%1[%2;%3] ";
//        curPoint = Arr[i];
        qsTemp=qsTemp.arg(Arr[i].Name).arg(Arr[i].x).arg(Arr[i].y);
        qsRetVal.append(qsTemp);  //добавляем в строку
    }
    return qsRetVal;
}


