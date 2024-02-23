#ifndef QUEUE_H
#define QUEUE_H
#include <string>

using namespace std;

enum op {ADD, SUB, MULT, DIVI};
struct expr
{
  int oprd1;
  op oprt;
  int oprd2;
};

typedef expr el_t;
const int QUEUE_SIZE = 10;

class Queue
{
 private:
  el_t el[QUEUE_SIZE];
  int count;
  int front;
  int rear;
  void queueError(string msg);

 public:
  Queue();
  bool isEmpty();
  bool isFull();
  void add(el_t e);
  el_t remove();
  el_t getFront();
  void goToBack();
  int getSize();
  void displayAll();


};


#endif