// 1TARvg Orlov Vlad
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <iostream>

using namespace std;   //определить простанство имен std namespace на всю программу

int joinedArray(int A[],int A_size, int B[],int B_size, int C[]);

int main()
{
    #define sizeA 16
    #define sizeB 15

    int arrA[sizeA]={1,3,5,7,9, 11,13,15,17,19, 21,23,25,27,29, 31};
    int arrB[sizeB]={2,4,6,8,10, 12,14,16,18,20, 22,24,26,28,30};
    int arrC[sizeB+sizeA] = {0};   //массив для совмещения, надо инициализировать хотя бы 1 элемент!!

    cout << "\n Array A  have elements are:";
    for (int i=0; i<sizeA; i++)   cout << " " <<arrA[i];
    cout << endl;

    cout << "\n Array B  have elements are:";
    for (int i=0; i<sizeB; i++)   cout << " " <<arrB[i];
    cout << endl; cout << endl;

    joinedArray (arrA, sizeA, arrB, sizeB, arrC);
    return 0;
}

int joinedArray(int A[],int A_size, int B[],int B_size, int C[])
{

    int i=0;
    int j=0;
    int c=0; // для перемещения по массивам &&

    while (i < A_size && j < B_size)
    {
        if (A[i]>B[j])             // если А>В
        {
            C[c]=B[j];
 //           cout <<" _"<< C[c] ; //взяли из В
            c++;
            j++;

        }
        else
            if (A[i]<B[j])         // если А<В
            {
             C[c]=A[i];
//             cout <<" -"<< C[c] ; //взяли из А
             c++;
             i++;

            }
          if (A[i]==B[j])          // если А==В
            {
                C[c]=A[i];
 //               cout <<" ="<< C[c] ; //взяли из А
                c++;
                i++;

                C[c]=B[j];
 //               cout <<" ="<< C[c] ; //взяли из В
                c++;
                j++;
            }
   }

     cout << endl;
    while (i<A_size-1)  //счетчик всегда больше номера элемента! Дописываем остатки
    {
            C[c]=A[i];
            c++;
            i++;
    }
    while (j<B_size-1)
    {        
            C[c]=B[j];
            c++;
            j++;
    }
 //      cout << c << endl;
       cout << "\n Array C now have elements are:";
       for (int i=0; i<c; i++)   cout <<" " << C[i];
       cout << endl;

    return 0;

}



