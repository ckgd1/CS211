//testMyMath.cpp
#include <iostream>
using namespace std;
#include "myMath.h"//reading code from my math
int main()
{
  int number;
  /* 
 cout << pow(2,3) << endl; //should give us 8

  int ans = pow(5,2);
  cout << ans << endl; // should give us 25
 
 int base,power;
 cout << "Enter base:";
 cin >> base;
 cout << "Enter power:";
 cin >> power;

 cout << pow(base, power) << endl; // calling function
  */
  cout << "Enter a number:";
  cin >> number;

  isPrime(number);
 
}
