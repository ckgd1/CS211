/***************************************************************
CS211
Template prepared by Kazumi Slott
1-28-2020

This program tests array.h
**************************************************************/

#include "array.h"


int main()
{
   //declare const called SZ_I set to 7
  const int SZ_I = 7;
   //declare const called SZ_D set to 3
  const int SZ_D = 3;
  //declare const called SZ_C set to 5
  const int SZ_C = 5;

  //create an integer array that has SZ_I slots
  int ar[SZ_I];
  //create a double array that has SZ_D slots
  double a[SZ_D];
  //create a character array that has SZ_C slots
  char c[SZ_C];

  //call fill with the integer array
  cout << "----- Filling the integer array -----" << endl;  
  fill(ar,SZ_I);
  //call fill with the double array
  cout << "----- Filling the double array -----" << endl;  
  fill(a,SZ_D);
  //call fill with the character array
  cout << "----- Filling the character array -----" << endl;  
  fill(c,SZ_C);
  
  //call print (with 2 parameters) with the integer array
   print(ar,SZ_I);
   cout << endl;
  //call print with the double array
   print (a, SZ_D);
   cout << endl;
  //call print with the character array
   print (c, SZ_C);
   cout << endl;
  
  //call getHighest with the character array and show the highest value along with its location
  cout << "The highest is " <<c[getHighest(c,SZ_C)] << " at " << getHighest(c, SZ_C) << endl;
  //call getLowest with the duoble and show the lowest value along with its location
  cout << "The lowest is " << a[getLowest(a, SZ_D)] << " at " << getLowest(a, SZ_D) << endl;
  //call getAvg with the integer array and show the returend value
  cout << "The average is " << getAvg(ar,SZ_I) << endl;

  //call unique with integer array and show unique array and the number of unique numbers
  int uniquei[0];
 
  int count =  unique(ar,uniquei,SZ_I);
 cout << "The total number of unique integers is " << count  <<endl; //ar[unique(ar,SZ_I)] << endl;
 print (uniquei, count);
  
  //call unique with character array and show unique array and the number of unique numbers


  //sort the double array and print it
   sort(a, SZ_D);
  print (a,SZ_D);
  cout << endl;
  //sort the character array and print it
  sort(c, SZ_C);
  print (c, SZ_C);
  cout << endl;

  cout << "----- Bubble sorting integer array -----"<< endl;
  bubbleSort(ar, SZ_I);
  print (ar, SZ_I);
  cout << endl;

  cout << "----- Bubble sorting double array -----" << endl;
  bubbleSort(a, SZ_D);
  print (a, SZ_D);
  cout << endl;

  cout << "----- Bubble sorting charcater array -----" << endl;
  bubbleSort(c, SZ_C);
  print (c, SZ_C);
  cout << endl;
  
  cout << "testing find" << endl;
  cout << find(c, SZ_C, 'k') << endl;
    
  return 0;
}
