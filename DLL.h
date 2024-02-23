#ifndef DLL_H
#define DLL_H
#include <string>

using namespace std;
typedef int el_t;

struct node
{
  int elem;
  node* next;
  node* prev;
};

class DLL
{
 private:
  node* front;
  node* rear;
  int count;

 public:
  DLL();
  ~DLL();
  void DllError(string msg);
  void addRear(el_t el);
  el_t deleteFront();
  bool isEmpty();
  void displayAll();
  void addFront(el_t el);
  el_t deleteRear();
  DLL(const DLL& source);

  bool search(el_t el);
  void deleteNode(el_t el);
  //void deleteNodes(el_t el);
  void addInOrderAscend(el_t el);
  //void addInOrderDescend(el_t el);

  void printAllReverseDLL();
};

#endif
