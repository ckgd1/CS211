#ifndef LL_H
#define LL_H
#include <string>

using namespace std;
typedef int el_t;

struct node
{
  el_t elem;
  node* next;
};

class LL
{
 private:
  node* front;
  node* rear;
  int count;

 public:
  LL();
  ~LL();
  void llError(string msg);
  void addRear(el_t el);
  el_t deleteFront();
  bool isEmpty();
  void displayAll();
  void addFront(el_t el);
  el_t deleteRear();
  LL(const LL& source);

  bool search(el_t el);
  void deleteNode(el_t el);
  //void deleteNodes(el_t el);
  void addInOrderAscend(el_t el);
  //void addInOrderDescend(el_t el);
};

#endif
