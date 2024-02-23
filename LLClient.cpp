#include <iostream>
#include "LL.h"

using namespace std;

int main()
{
  LL l1;
  l1.addFront(1);
  l1.addFront(2);
  l1.addFront(3);
  l1.addRear(4);
  l1.addRear(5);
  l1.displayAll();

  l1.deleteFront();
  l1.deleteRear();
  l1.displayAll();

  l1.deleteFront();
  l1.deleteRear();
  l1.displayAll();

  l1.deleteFront();
  l1.displayAll();

  l1.addRear(10);
  l1.addFront(11);
  l1.displayAll();

  l1.deleteRear();
  l1.deleteRear();
  l1.displayAll();

  LL a;
  a.addFront(1);
  a.addRear(2);
  LL b(a);
  b.displayAll();
  a.deleteFront();
  a.displayAll();
  b.displayAll();
  return 0;
}
