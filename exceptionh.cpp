#include "LL_T_E.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

  // Underflow<int> u;
  LL<int> u;
  int elem;

try 
  {
   u.addRear(1);
   u.deleteFront();
   u.deleteFront();
  }

 catch(LL<int>::Underflow)
   {
     cout << "error"<< endl;
   }
 cout << "After " << endl;
 u.displayAll();
 
 return 0;
}
