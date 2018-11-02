#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <iostream>

using namespace std;   //определить простанство имен std namespace на всю программу

int joinSortedArray(int arrA[],int arrA_size1, int arrB[],int arrB_size1, int arrC[]);

int main()
{
    #define sizeA 10
    #define sizeB 15

    int arrA[sizeA]={1,3,4,9,10,13,15,16,17,21};
    int arrB[sizeB]={1,2,5,8,11,12,14,15,18,19,22,23,25,26,33};
    int arrC[sizeB+sizeA] = {0};   //массив для совмещения, надо инициализировать хотя бы 1 элемент!!

    cout << "\n Array A  have elements are:";
    for (int i=0; i<sizeA; i++)   cout << " " <<arrA[i];
    cout << endl;

    cout << "\n Array B  have elements are:";
    for (int i=0; i<sizeB; i++)   cout << " " <<arrB[i];
    cout << endl;

 //   cout << "\n Array C  have elements are:";
 //   for (int i=0; i<(sizeB+sizeA); i++)   cout << " " <<arrC[i];
 //   cout << endl;

    joinSortedArray (arrA, sizeA, arrB, sizeB, arrC);
    return 0;
}

int joinSortedArray(int arrA[],int arrA_size1, int arrB[],int arrB_size1, int arrC[])
{
  int Counter = arrB_size1*2;
  int iTemp,j;

  if (arrA_size1 > arrB_size1)  //по размеру наименьшего массива
  {
      iTemp = arrB_size1;
  }
  else
  {
      iTemp = arrA_size1;
  }

  for (int i=0; i<iTemp; i++)   //  присваиваем элементы массиву С
      {
        if ( arrA[i] < arrB[i] )
       {
           arrC[(i*2)] = arrA[i];
           arrC[((i*2)+1)] =  arrB[i];

       } else
          {
               arrC[i*2] = arrB[i];
               arrC[(i*2)+1] =  arrA[i];
           }
       j=i;
   }

  while (j<arrB_size1-1)   //дописываем остатки в С
  {
      arrC[j+ arrA_size1+1]=arrB[j+1];
      j++;
      Counter=j+ arrA_size1+1; // =сколько всего в С
  }

  cout << "\n Array C  have elements are: ";
  for (int i=0; i<Counter; i++)       cout << arrC[i] << " ";
  cout << endl;
return 0;

}





