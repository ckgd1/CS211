#include "stack.h"
#include <cstdlib>
#include <iostream>
Stack::Stack()
{
  top = -1;
}

bool Stack::isEmpty()
{
  return (top == -1) ?  true : false;
}

bool Stack:: isFull()
{
  return (top == MAX-1) ? true : false;
}

void Stack::push(el_t e)
{
  if(isFull()== true)
    stackError("Stack Overflow");
  else
    {
      top++;
      el[top]=e;
    }
}

el_t Stack::pop()
{
  if (isEmpty()== true)
    {
      stackError("Stack Underflow");
      exit(1);
    }
  else
    {
      el_t temp = el[top];
      top--; 
      return temp;
    }
}


el_t Stack::topElem()
{
  if (isEmpty()==true)
    stackError("No Elements");
  else 
    return el[top];
}

void Stack::displayAll()
{
  if(isEmpty()== true)
    cout << "[e,pty]" << endl;
  else
    for (int i = top; i >= 0; i--)
      {
	cout << el[i] << endl;
      }
}

void Stack::stackError(string msg)
{
  cout << "Stack Error" << endl;
  exit(1);
}

void clearIt(int top)
{
  top = -1;
}