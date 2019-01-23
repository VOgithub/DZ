#include <QCoreApplication>
#include <QString>
#include <QDebug>


//DZ + доработать класс - онраничить макс вес, max LifeTime, и toPrint function !! getInfo(QString allInfo) + new class Hamster

#include "rodent.h" //oma class with ""

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
{  // время жизни обьекта Ham
    Rodent hamster("Ham"); //konstruktor
    qDebug()<< hamster.getName();  // pokaji name
    qDebug()<< "new Ham weight: " << hamster.getWeight();
    hamster.LifeDay();
    qDebug()<< "new Ham weight: " << hamster.getWeight();
    hamster.LifeDay();
    qDebug()<< "new Ham weight: " << hamster.getWeight();
    hamster.LifeDay();
    qDebug()<< "new Ham weight: " << hamster.getWeight()<<endl;
    hamster.toPrint();
 // hamster.weight=152;
 // qDebug()<< "new Ham weight: " << hamster.weight;
 }  // время жизни обьекта Ham, destructor  sam !!


    qDebug() << endl;

    Mouse m1("Mouse1");
    Hamster h2("Hamster2");
    m1.toPrint();
    h2.toPrint();
    bool m1Li;
    bool h2Li;

    for (int i=0;i<10;i++){
        m1.feed(0.5);
        h2.feed(4.0);
        m1Li = m1.LifeDay();
        h2Li = h2.LifeDay();

        if (!m1Li){m1.kill();}
        else { m1.SuperMouse();  }

        if (!h2Li){ h2.kill();} else {
            h2.SuperHamster();}

        m1.toPrint();
        h2.toPrint();




 //      m1.SuperMouse();
 //      h2.SuperHamster();


    }


  //  Rodent mouse ("Mous");
  //  qDebug()<< mouse.getName();


 /*   {
    Mouse m1("Mouse1");
    qDebug()<< m1.getName();

   m1.addTwoGramms();
    qDebug()<< "new Ham weight: " << m1.getWeight()<< ", age :" << m1.getAge();
   m1.LifeDay();
    qDebug()<< "new Ham weight: " << m1.getWeight()<< ", age :" << m1.getAge();
   m1.LifeDay();
   qDebug()<< "new Ham weight: " << m1.getWeight()<< ", age :" << m1.getAge();
   m1.LifeDay();
   qDebug()<< "new Ham weight: " << m1.getWeight()<< ", age :" << m1.getAge();
   m1.LifeDay();
   qDebug()<< "new Ham weight: " << m1.getWeight()<< ", age :" << m1.getAge();
   m1.LifeDay();
   m1.toPrint();
   m1.SuperMouse();
    m1.toPrint();
   qDebug()<< "new Ham weight: " << m1.getWeight()<< ", age :" << m1.getAge();
   m1.LifeDay();
   qDebug()<< "new Ham weight: " << m1.getWeight()<< ", age :" << m1.getAge()<<endl;
 //  m1.addTwoGramms();
}

 */

/* {   qDebug()<< "try to create new Hamster2 ";
    Hamster h2("Hamster2");
    qDebug()<<" Name - "<< h2.getName();
    qDebug()<< "new Hamster weight: " << h2.getWeight()<< ", age :" << h2.getAge();
    h2.LifeDay();
    qDebug()<< "new Hamster weight: " << h2.getWeight()<< ", age :" << h2.getAge();
     h2.LifeDay();
     qDebug()<< "new Hamster weight: " << h2.getWeight()<< ", age :" << h2.getAge(); //uze minus!!!
      h2.LifeDay();
      h2.toPrint();
      for (int i=0;i<4;i++) h2.SuperHamster();
      h2.toPrint();
      h2.LifeDay();
      qDebug()<< "new Hamster weight: " << h2.getWeight()<< ", age :" << h2.getAge(); }
*/


 //    qDebug()<< "try to create new Hamster ";
//     Hamster *H1 = new Hamster("Hamster1");
//     qDebug()<< H1->getName();
//     qDebug()<< "new Hamster weight: " << H1->getWeight();
//    qDebug()<< "try to kill last Hamster ";
    //H1.delete();
//    delete H1;
//    qDebug()<< "RIP Hamster ";


 //  qDebug()<< "try to kill last Hamster ";
 //  h2.kill();
   //H1.delete();
   //delete H1;
//   qDebug()<< "RIP Hamster 2 ";

//     Rodent *pRodent; //создаем указатель на класс  A1
//     pRodent =new Rodent ("LabRat"); // через указатель, не потерять и не перенаправлять

//    for (int i=0; i<3; i++){  //область видимости - только внутри цикла!!! Деструктор по умолчанию срабатывает после }}}
//        QString qsTemp = "Mouse %1";
   //    pRodent = new Rodent(qsTemp.arg(i)); // A1
//        Rodent labRat(qsTemp.arg(i));
 //      qDebug() << "Create new rodent, number "<< i; //destructor auto !!

//    }

//   delete pRodent; //через указатель убили A1

    return a.exec();
}
