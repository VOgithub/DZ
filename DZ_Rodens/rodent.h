#ifndef RODENT_H
#define RODENT_H
#include <QDebug>
#include <QString>


class Rodent
{  //private !!!
     int maxLifeSpan = 1000; //
protected:  //доступ только сам или наследники
    QString name;
    double weight= 1.0; //gramm  макс 250 грамм!!  DZ!!
    int age=0;  //vozrast v dnjah

public:  //public для всех!!!
    Rodent();//default constructor
    Rodent(QString name); // constructor user!
    void feed(double food);
    QString getName(){return name;}
    void setName(QString newName){name = newName;}  // setter

    double getWeight(){ return weight;}
    double getAge(){ return age;}
    void toPrint();
    void kill();
    bool LifeDay();  //spend 1 day, return False if die
    ~Rodent();  //destructor
};

class Mouse:public Rodent{ //max 65
public:
 //   Mouse(); //pustoy !!
    Mouse(QString name); //Constructor
    void addTwoGramms();
    bool LifeDay();
    void SuperMouse();
 //   void kill();

};

class Hamster:public Rodent{ //max 105
public:
    Hamster(QString name); //construktor
    void addFourGramms();
    bool LifeDay();
    void SuperHamster();

};



#endif // RODENT_H
