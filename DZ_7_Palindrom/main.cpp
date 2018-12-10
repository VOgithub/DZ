//  1TARvg17
//  Orlov Vladislav

#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <iostream>

using namespace std; //пространство имен

bool checkPal(QString qsReadBuff);                     // проверка на полиндром ОК
void writeFile (bool flag, QString qsBuff,QString FileNameOut); // запись в файл   OK
QString Literal(QString qsBuff);                               //зачистка

int main()
{
    bool flag= true;

    QFile ReadFile("TestInput.txt");
    QFile FileOut("TestOutput.txt");
    QString qsReadBuff,qsBuff,qsBuff1, qsPalindrom;

    QString FileNameOut="TestOutput.txt";
    QTextStream in(&ReadFile);

    FileOut.remove();

   if (ReadFile.open(QFile::ReadOnly| QFile::Text)) {
        while(!in.atEnd()) {
        qsPalindrom = in.readLine();     //читаем из файла

         qsReadBuff = qsPalindrom;
         qsBuff1 = Literal(qsReadBuff);           //оставляем только буквы

         qsReadBuff=qsBuff1;

         qsReadBuff = qsReadBuff.toLower();      //  только строчные
         qsReadBuff=qsReadBuff.simplified();     // и без мусора

         qsBuff1 = Literal(qsReadBuff);          // контрольный !
         qsReadBuff=qsBuff1;
         flag = checkPal(qsReadBuff);            //  полиндром или нет??
         qDebug()<< " flag is :"<< flag << endl;
         writeFile ( flag, qsPalindrom, FileNameOut);    // пишем отчет
         flag = true;
        }
   ReadFile.close();
   }
    return 0;
} // конец фильма! Всем спасибо!

QString Literal(QString qsBuff){
    QString qsTemp;
    int Ansii;
    int size = qsBuff.length();
    for (int i=0;i<=(size-1);i++){
    Ansii=qsBuff[i].toLatin1();
    if ((65 <= Ansii) && (Ansii <= 90)){ qsTemp[i]=qsBuff[i];} //если Буква

    if ((97 <= Ansii) && (Ansii <= 122)){ qsTemp[i]=qsBuff[i];} //если буква

    if ((48<= Ansii) && (Ansii <= 57)) { qsTemp[i]=qsBuff[i];}  //если цифра
    }
     for (int i=0;i<=(size-1);i++){                        //- пробелы!
           if ((qsTemp[i]==" ")||(qsTemp[i]=="\x0")){
               qsTemp.remove(i,1);
           }
       }
 //     qDebug()<< "qsTemp without spacer -"<< qsTemp;
     qsBuff=qsTemp.simplified();
     return qsBuff;
}

bool checkPal(QString qsReadBuff){
      QString qsReadBuff1="";
      int buff_size;
      bool ok=true;

      buff_size=qsReadBuff.length();
      qsReadBuff=qsReadBuff.simplified();
      for (int i=0;i<buff_size;++i){
            qsReadBuff1[(buff_size)-i]=qsReadBuff[i];
 //           if (qsReadBuff1[(buff_size)-i] !=qsReadBuff[i]) ok=false;  двойная проверка!!
      }
      qsReadBuff1=qsReadBuff1.simplified();
 //     qDebug()<<"buff1 in check="<<qsReadBuff1<< endl;
      for (int i=0;i<buff_size;++i){
        if (qsReadBuff1[i] !=qsReadBuff[i]) ok=false;
      }
     return ok;
}

void writeFile (bool flag, QString qsBuff,QString FileNameOut){
     QFile file(FileNameOut);



     if (file.open(QFile::WriteOnly |QFile::Append )){
         QTextStream out(&file);
       if (flag == true)
         {
             qDebug()<<"yes, it is a palindrome: "<< qsBuff << "\r\n"<<endl;
            out<<"yes, it is a palindrome: "<< qsBuff << "\r\n"<<endl;
         } else {
             qDebug()<<"this is not a palindrome "<< qsBuff << "\r\n"<<endl;
             out<<"this is not a palindrome "<< qsBuff << "\r\n"<<endl;
         }
      }
      file.close();
}


