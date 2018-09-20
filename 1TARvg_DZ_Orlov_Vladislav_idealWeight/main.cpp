/* 1TARvg  Orlov Vladislav
 *
 * расчет идеального веса на основе пола, и роста
 * запросить реальный вес, и вывести заключение, вес ниже / выше или идеальный
 *
 * Идеальный вес для женщин = Рост * Рост * 0.00222
 * Идеальный вес для мужчин = Рост * Рост * 0.00227
 *
 * толерантность веса - 10%
 * */


// подключаем библиотеки
#include "iostream" // iostream для ввода и вывода на консоль
#include "string"   // string для работы со строчками букв

// определяем значение TOLERANTS
#define  TOLERANTS 0.10

using namespace std; //определить простанство имен std namespace на всю программу

// main - главная функция
int main() //исходная функция не получает вводных аргументов
{
    // вывод на консоль
    cout << "Hello! \n";                            // диалог с юзером
    cout << "Please insert your height in sm:  " << endl; //строку с консоли заканчиваем "endl" (стандартный С++ std метод)

    unsigned short int height = 0;   //определяем короткое беззнаковое целое height
    cin >> height;                   //читаем его с консоли

    cout << "What is your weight in kg? " << endl;
    float realWeight;                // инициализируем переменную realWeight
    cin >> realWeight;               // читаем его с консоли

    cout << "What is your sex? (m/w): " << endl;
    char Sex;                       // определяем символьную переменную Sex
    cin >> Sex;                     // читаем еe с консоли

     unsigned short int idealWeight = 0; //определяем короткое беззнаковое целое idealWeight = 0



    if (Sex == 'm') {                          // если (m)an, то
        idealWeight = height *  height * 0.00227 ;  // идеальный вес = Рост * Рост * 0.00227
       // cout <<  "DEBUG: " << idealWeight << " for M \n";


    }

    if (Sex == 'w') {                          // если (w)oman, то
        idealWeight = height *  height * 0.00222 ;  // идеальный вес = Рост * Рост * 0.00222
       // cout <<  "DEBUG: " << idealWeight << " for W \n";
    }

    unsigned short int minWeight = idealWeight * (1.0 - TOLERANTS) ;
    unsigned short int maxWeight = idealWeight * (1.0 + TOLERANTS );

    if ((Sex != 'm') and (Sex != 'w')) {              // если не выбран пол
        cout << "Wrong key selected! Exit programm! " << endl;

    }

    if ((Sex == 'm') or (Sex == 'w')) {
        cout << "Your ideal weight shall be between " << minWeight << " and "<< maxWeight <<" kg\n ";

        if (realWeight < minWeight) {                  // если вес меньше мин, то
            cout << "You under ideal weight, sorry" << endl;  //
        }
        if ( ( maxWeight >= realWeight) and (realWeight>= minWeight)) {  // если вес в норме, то
             cout << "You have ideal weight!" << endl;  //
        }
        if (realWeight > maxWeight) {                  // если вес больше макс, то
             cout << "You above ideal weight, sorry" << endl; //
        }


    }

    return 0; // главная функция возвращает 0.

}
