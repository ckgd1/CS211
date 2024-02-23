#include "stack.h"
#include <iostream>

using namespace std;

void addPerson(Stack& e, string name);

int main()
{
  Stack s;
  if(s.isEmpty() == true)
  cout << "The stack is empty." << endl;
  else
    cout << "The stack is not empty" << endl;
  addPerson(s, "Mike");
  addPerson(s, "Kathy");
  cout <<"The top element is " << s.topElem() <<endl;
  addPerson(s, "Dave");
  addPerson(s, "Alice");
  addPerson(s, "Tom");
  if(s.isFull() == true)
   cout << "stack is full" << endl;
 else
   cout << "Stack is not full" << endl;
  s.displayAll();
 addPerson(s, "Meg");
 s.pop();
 cout <<"The top element is " << s.topElem() <<endl;
  
 
  
  return 0;
  
}

void addPerson(Stack& e, string name)
{
  if(!e.isFull())
    e.push(name);
  else 
    cout << "Cannot add " << name << " because stack is full." << endl;
}
