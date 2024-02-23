/*********************************************************
Template provided by Kazumi Slott

Name:Christina Garcia
This client tests the queue class memeber functions.
********************************************************/
#include <iostream>
#include "queue.h"
using namespace std;
//?????????

void showMenu();

int main()
{
  Queue q;
  cout << q.getSize();
  q.add('A');
  q.displayAll();
  q.add('B');
  q.add('C');
  q.add('D');
  q.add('E');
  q.displayAll();
  cout << q.getSize();
  //q.add('X');
  cout << q.remove();
  cout << q.remove();
  q.add('F');
  q.displayAll();
  q.remove();
  q.remove();
  q.remove();
  q.displayAll();
  cout << q.getSize();
  q.add('G');
  q.add('H');
  q.displayAll();
  q.goToBack();
  q.displayAll();
  q.remove();
  q.displayAll();
  q.remove();
  q.remove();
  q.remove();
  q.displayAll();
  cout << q.getSize();
  /*
  do{
    



  }while(???????);
  */
  return 0;
}


void showMenu()
{
  cout << "1: add a new element" << endl; //(testing add(), isFull())
  cout << "2: remove an element" << endl; // (testing remove(), isEmpty())
  cout << "3: check the front element" << endl; //(testing getFront(), isEmpty())
  cout << "4: go back to the rear" << endl; //(testing goToBack())
  cout << "5: get the number of elements in the queue" << endl; //(testing getSize()) 
  cout << "6: display all the elements in the queue" << endl; //(testing displayAll()) 
  cout << "7: quit program" << endl;
}
