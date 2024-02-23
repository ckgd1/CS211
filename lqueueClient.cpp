#include "lqueue.h"
#include <iostream>

using namespace std;

int main()
{
  LQueue q;
  if(q.isEmpty() == true);
  cout << "The queue is empty" << endl;
  q.displayAll();
  q.addRear(1);
  q.displayAll();
  cout << endl;
  q.addRear(2);
  q.addRear(3);
  q.addRear(4);
  q.displayAll();
  cout << endl;
  cout << q.deleteFront();
  cout << q.deleteFront();
  cout << q.deleteFront() << endl;
  q.displayAll();
  cout << endl;
  if(q.isEmpty() == false)
    cout << "The queue is not empty." << endl;
  q.deleteFront();
  if(q.isEmpty() == true)
    cout << "The queue is empty." << endl;
  q.displayAll();
  return 0;
}
