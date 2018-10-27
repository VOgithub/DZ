//  1TARvg17
//  Orlov Vladislav


#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QFile>

#include <iostream>
using namespace std; //пространство имен

struct Point{
    float x;
    float y;
    int Name; // для порядкового i
};

int readFile(Point pArray[], QString ReadFileName);  //читаем из файла  ОК

void writeFile (Point pArray[], float &per, float &quadArea, int &l); // запись в файл   OK

float distancePoint(Point a, Point b);             // расстояние между точками  ОК

float quadPerimeter(Point pArray[], int lenght);       // периметр  OK

float quadArea(Point pArr[], int l);            // площадь  OK


int main()
{
    QString qsFileNameIn = "pointsFile.txt"; // откуда
    QFile qsFileNameOut ("result.txt");  // куда
    qsFileNameOut.remove();

    Point quadOne[10];
    int i =0;

    int len = readFile(quadOne, qsFileNameIn);  //читаем из файла
    cout << "Read from file - " << len << " lines.\r\n "<< endl;
    for (i=0; i<len; i++){
        qDebug() << " X = "<<  quadOne[i].x << " Y = "<< quadOne[i].y ;
    }
     cout << endl;
    float FPerimeter = quadPerimeter(quadOne, len);
    float a = quadArea(quadOne, len);

    writeFile(quadOne, FPerimeter, a, len);
    cout << "For more info please open a result.txt! " << endl;

    return 0;
} // конец фильма! Всем спасибо!


float quadArea(Point pArray[], int l){
    int i = 0;
    float quadArea = 0;

    if  ( l < 3 || l > 10 )
    {
        cout << "Points data is not usable!"<<endl;
    }
    else {
        for (i=0; i<l-1; i++)
        {
            quadArea = quadArea + (pArray[i].x*pArray[i+1].y-pArray[i+1].x*pArray[i].y);
        }
        quadArea = abs(0.5*(quadArea + (pArray[i].x*pArray[0].y-pArray[0].x*pArray[i].y)));
        cout << "The quadArea of the quad is " << quadArea << ";\r\n" << endl;

    }
    return quadArea;
}

float quadPerimeter(Point quadOne[], int l){
    float fPer = 0;
    int i = 0;
    if (l<=1){
        cout<<"Perimeter = 0 OR not enought data!"<<endl;
        fPer = 0;
   }
    if (l==2) {
            cout<<"Perimeter = distance between 2 points"<<endl;
            fPer = fPer + distancePoint(quadOne[0], quadOne[1]);
        } else
     {
        while(i<l-1)   //с нулевой по последнюю точку
        {
            fPer = fPer + distancePoint(quadOne[i], quadOne[i+1]);
             i++;
        }
        fPer = fPer + distancePoint(quadOne[l-1], quadOne[0]);  // и от последней до первой
     }
    cout<<"The perimeter of the " << l << "-line figure is: " << fPer << ";\r\n" << endl;
 return fPer;
}


float distancePoint(Point a, Point b){
    float A = sqrt(pow((b.x-a.x), 2)+pow((b.y-a.y), 2));
    return A;
}


void writeFile (Point pArr[], float &perim, float &quadArea, int &l)
{
    QFile resFile ("result.txt");

   if (resFile.open(QFile::WriteOnly |QFile::Append )){
            QTextStream out(&resFile);

            out<<"For figure with a points coordinates : \r\n"<<endl;
            out << "\r\n"<<endl;
            for (int i=0; i<l; i++){
                out<<"Point "<< i <<": ["<<pArr[i].x<<";"<<pArr[i].y<<"]\r\n" <<endl;
            }
            out << "\r\n"<<endl;
            if (quadArea <=0)
            {
                out <<"The figure have no area!\r "<<endl;
                out << "\r\n"<<endl;
            }
            else {
                out << "The total area of the quad is " << quadArea << "; \r\n"<<endl;
            }
            out << "The perimeter of the quad is "<< perim << ";\r\n"<<endl;
    }
   resFile.close();
    }

int readFile(Point quadOne[], QString FileIn){
    QString message;
    QFile file(FileIn);

    if (!file.exists()){
        message = "Can't find file %1 to read\n";
        message = message.arg(FileIn);
        qDebug() << message;
        return -1;
    }

    if(!file.open(QFile::ReadOnly | QFile::Text))  {
        message = "Can't open the file %1 for reading\n";
        message = message.arg(FileIn);
        qDebug() << message;
        return -1;
    }
//напрямую из файла
    char buf[1024];
    int readCount; //сколько символов считано из строки вместе с EOL
    QString qsBuf;
    QStringList qslPoint;
    float X,Y;
    int i=0;

    while (!file.atEnd()){
        readCount = file.readLine(buf,sizeof(buf));
        buf[readCount-1]=0;     // обнуляем символ конца строки
        qsBuf = buf;
        qslPoint = qsBuf.split(';');

        X = qslPoint.at(0).toFloat();   //to float
        Y = qslPoint.at(1).toFloat();

        quadOne[i].x = X;
        quadOne[i].y = Y;
        quadOne[i].Name = i;

        i++;
    }
    return i;
}

