#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

typedef int el_t;
const int MAX = 5;

class Stack
{
 private:
  int top;
  el_t el[MAX];
  void stackError(string errorMsg);
  //2 data members go here

  // prototypes of the private function stackError()
 public:
  Stack();
  bool isEmpty();
  bool isFull();
  void push(el_t e);
  el_t pop();
  el_t topElem();
  void displayAll();
  void clearIt(int top);
  
};




#endif
