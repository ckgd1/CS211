#ifndef rationalNumber_H
#define rationalNumber_H
#include <iostream>

using namespace std;

//define the rNum class here. The data members are top and bottom.
class rNum
{
  friend istream& operator >>(istream cin, rNum& n);
  friend ostream& operator<< (ostream& out, const rNum& n);
 private:
  int top;
  int bottom;
 public:
  rNum();
  rNum(int top, int bottom);
  rNum operator+(rNum& t);
  // rNum operator+(const rNum& r1, const rNum& r2);
};











#endif