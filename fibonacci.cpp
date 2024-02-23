#include <iostream>
#include <time.h>

using namespace std;
#include "/cs/slott/cs211/checkInput.h"
int fib1(int pos);
int fib2(int pos);
int main()
{
  int pos;
  clock_t start, end;

  cout << "Enter a position: " ;
pos = getData(0, 46, "Invalid input. Please enter a position between 0 and 46");

start = clock();

int fibNum = fib1(pos);
/*
Call fib1 with pos 
Or
Call fib2 with pos

*/

 end = clock();

 cout << "Elapsed time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;

 cout << "Fibonnaci number at position " << pos << " is " << fibNum << endl;

 return 0;
}

int fib1(int pos)
{
  if (pos<= 1)
    return pos;
  else 
    return fib1(pos - 2) + fib1(pos-1);
}

int fib2(int pos)
{
  int n1 = 0;
  int n2 = 1;
  int n3;
  for (int i = pos; i > 0; i--)
    {
      n3 = n2 + n1;
      n2 = n1;
      n1 = n3;
    }
  return n3;
}
