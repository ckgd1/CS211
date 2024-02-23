#include "rationalNumber.h"
#include "array.h"

// including array.h and rationalNumber.h 
//default constructor: set top to 0 and bottom to 1
rNum::rNum()//setting rNum constructor
{
  top = 0; // top = 0
  bottom = 1; // bottom = 1
}


//non-default constructor: we won't be using it in the client, but we might as well make it.
rNum:: rNum(int top, int bottom)
{
  this->top = top;
  this->bottom = bottom;
}


//Create all operator overloaded functions here. You need to figure out what you need by reading the client. 

//rNum rNum::operator+(rNum& t)
/*
istream& operator>> (istream& cin, rNum & n)
{
 
  // int topnum;
  //int botnum;
  cout << "Enter the top number: "; 
  cin >> n.top;
  // topnum = this-> top + t.top;
  cout << "Enter the bottom number: ";
  cin >>  n.bottom;
  //botnum = this -> bottom + t.bottom - 1;
  // a.bot = a2;
  
  return cin;
  //rNum tot(topnum,botnum);
  //return tot;
}
*/
/*
rNum operator+(const rNum& r1, const rNum& r2)
{

  rNum a;
  a.top = this-> top + r1.top;
  a.bottom = this -> bottom + r2.bottom;
  return a;
}
*/
ostream& operator<<(ostream& out, const rNum& n)
{
  out << n.top;
  out << "/";
  out << n.bottom;
  return out;
}


//This is not an operator overloaded function.. This function will simplify a rational number to the simplest form.
/*
int rNum::simplify(int top, int bottom)
{
 
}
*/
