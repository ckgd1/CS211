#ifndef LQUEUE_H
#define LQUEUE_H
#include <string>

using namespace std;
typedef int el_t;

struct node
{
  el_t elem;
  node* next;
};

class LQueue
{
 private:
  node* front;
  node* rear;
  int count;
  void printAllReverse(node* p);

 public:
  LQueue();
  ~LQueue();
  void queueError(string msg);
  void addRear(el_t el);
  el_t deleteFront();
  bool isEmpty();
  void displayAll();
  void printAllReverse();
};

#endif
