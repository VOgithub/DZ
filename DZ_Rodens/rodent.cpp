#include "rodent.h"

Rodent::Rodent(QString name) // konstruktor
{
    QString qsTemp = "New hamster %1 was born! Weight is %2"  ;
    qDebug()<< qsTemp.arg(name).arg(this->weight);
    this->name=name;
}

Rodent::Rodent() { //void constructor!!
    QString qsTemp = "Void constructor!"  ;
    qDebug()<< qsTemp;}

void Rodent::feed(double food)
{
    weight +=food;
}

void Rodent::toPrint()
{
   QString qsTemp = " Roden's paraneters: Name - %1, weight - %2, age - %3 ";
     qDebug() << qsTemp.arg(name).arg(this->weight).arg(this->age) <<endl;
}


bool Rodent::LifeDay()  // 1 day left
{
   weight-=0.34;
   if(weight<0.0)return false;
   age++;
   qDebug() << " Age Roden ->" << age << "!"<<endl;
   return true;
}

void Rodent::kill()
{
    qDebug() << " Roden, do suicide!"<<endl;
    delete this;
}

Rodent::~Rodent() //destruktor
{
     QString qsTemp = "New roden %1 was die! Weight is %2"  ;
   qDebug()<< qsTemp.arg(name).arg(this->weight)<< endl<<endl;
}

Mouse::Mouse(QString name){  //konstruktor Mouse

    weight =0.75;
    QString qsTemp = "New mouse %1 was born! Weight is %2"  ;
    qDebug()<< qsTemp.arg(name).arg(this->weight);
    this->name=name;
}

void Mouse::addTwoGramms()
{
    qDebug() << "Add 2 gramms!"<<endl;
    weight += 2.0;;
}

bool Mouse::LifeDay()
{
   weight-=0.25;
   if(weight<0.0)return false;
   if(weight>65.0){
       qDebug() << " Mouse to fat,DIE!" <<endl;
       return false;}
   age++;
    qDebug() << " Age Mouse ++!"<<endl;
    return true;
}

void Mouse::SuperMouse()
{
    weight+=2.0;
    qDebug() << " SuperMouse Bonus! Weight++2 = " << weight << "!"<<endl;
}


Hamster::Hamster(QString name){  //konstruktor Hamster

    weight =3.75;
    QString qsTemp = "New hamster %1 was born! Weight is %2"  ;
    qDebug()<< qsTemp.arg(name).arg(this->weight);
    this->name=name;
}

void Hamster::addFourGramms()
{
    qDebug() << "Add 4 gramms!"<<endl;
    weight += 4.0;;
}

bool Hamster::LifeDay()
{
    weight-=1.5;
    if(weight<0.0)return false;
    if(weight>105.0)return false;
     age++;
     qDebug() << " Age Hamster++!"<<endl;
     if (age >120){
         qDebug() << "  Hamster to old, DIE!" <<endl;
         return false;}
     return true;
}

void Hamster::SuperHamster()
{
    age+=2.0;
    qDebug() << " SuperHamster Bonus! Age++2 = " << age << "!"<<endl;
}



