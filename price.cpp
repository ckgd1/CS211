#include "price.h"
#include <iostream>

using namespace std;

Price::Price()
{
  dollar = 0;
  cent = 0;
}

Price::Price(int dollar, int cent)
{
  this-> dollar = dollar;
  this->cent = cent;
}

Price Price:: operator+(Price& sprice)
{
  int ndollar;
  int ncent;
  ndollar = this-> dollar + sprice.dollar;
  ncent =this-> cent + sprice.cent;

  if (ncent >= 100)
    {
      ncent -= 100;
      ndollar += 1;
    }
  Price total(ndollar, ncent);
  return total;
}


Price Price::operator-(Price& sprice)
{
  int ndollar;
  int ncent;

  ndollar = this->dollar - sprice.dollar;
  ncent =this-> cent - sprice.cent;
  if (ncent < 0)
    {
      ndollar -= 1;
      ncent = 100 + ncent;
    }
  Price diff(ndollar, ncent);
  return diff;
}

ostream& operator<<(ostream& out, const Price& p)
{ 
  out << p.dollar;
  if(p.cent < 10)
    {
      out << ".0";
    }
  else
    {
      out << ".";
    }
  out << p.cent;
  return out;
}
