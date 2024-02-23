#ifndef LL_T_H
#define LL_T_H

//#include "LL.h"
#include <iostream>
#include <cstdlib>
#include <string>

//using namespace std; 
using namespace std;
//typedef int el_t;

template <class T>
struct node
{
  T elem;
  node<T>* next;
};

template <class T>
class LL
{
 private:
  node<T>* front;
  node<T>* rear;
  int count;

 public:
  LL();
  ~LL();
  void llError(string msg);
  void addRear(const T& el);
  T deleteFront();
  bool isEmpty();
  void displayAll();
  void addFront(T el);
  T deleteRear();
  LL(const LL& source);
  void getFront();
  void getRear();
  void getNext();
  class OutofBoundary{};
  bool search(T el);
  void deleteNode(T el);
  //void deleteNodes(el_t el);                                             
  void addInOrderAscend(T el);
  //void addInOrderDescend(el_t el);                                                                                                                
};



template <class T>
LL<T>::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}
template <class T>
LL<T>::~LL()
{
  while(isEmpty() == false)
    deleteFront();
}

template <class T>
void LL<T>::addRear(const T& el)
{
  // cout << front << endl;                                                               
  //cout << rear << endl;                                                                                                                                                         
  if(isEmpty())
    {
      rear = new node<T>;
      front = rear;
    }
  else
    {
      //node* p = new node;                                                                   
      rear -> next = new node<T>;
      rear = rear ->next;
    }
  rear -> next = NULL;
  count ++;
  rear->elem = el;
  //cout << "end of add" <<endl;                                                                                                                      
}

template <class T>
void LL<T>::displayAll()
{
  node<T> *p = front;
  //p = front;
  if(isEmpty() == true)
    // llError( "[empty]");
    cout << "[Empty]" << endl;
  else 
    {
      while(p != NULL)
	{
	  cout << p->elem;
	  cout << " ";	  
	  p =  p->next;
	}
    }
  cout << endl;
}

template <class T>
bool LL<T>::isEmpty()
{
  return (front == NULL && rear == NULL && count == 0) ? true : false;
}

template <class T>
void LL<T>::addFront(T el)
{
  // node* p;
  //p = new node;
  // p -> elem = el;
  if(isEmpty() == true)
    {
      front = rear = new node<T>;
      rear -> elem = el;
      rear -> next = NULL;
      //front = p;
      //rear = p;
      //  p -> next = NULL;
    }
  else 
    {
      node<T>* p;
      p = new node<T>;
      p -> elem = el;
      p -> next = front;
      front = p;
    }
  count ++;
}
/*
  front = rear = new node;
  else
  {
  node* p = new node;
  rear -> next = p;
  rear = rear ->next;
  }
  rear -> next = NULL;
  count ++;
  rear->elem = el;
  
  }
*/



template <class T>
T LL<T>::deleteRear()
{
  if(isEmpty() == true)
    llError ("Error: list is empty.");
  else if(count == 1 && front == rear)
    {
      T o = rear -> elem;
      delete rear;
      front = NULL;
      rear = NULL;
      count --;
      return o;
    }
  else
    { 
      node<T>* temp = new node <T>;
      T o = rear -> elem;
      //delete rear;
      for( temp = front; temp -> next != rear; temp = temp -> next)
	;
      delete rear;
      rear = temp;
      rear -> next = NULL;
      count --;
      return o;
      /*      
temp = front;
      while(temp -> next != rear)
    {
      temp = temp -> next;
    }
      delete rear;
      rear = temp;
      rear -> next = NULL;
    }
  count --;
}
  /*      
node *last;
      last = rear;
      delete rear;
      f = second;
    }
  */
    }
}

template <class T>
LL<T>::LL(const LL& source)
{
  this -> front = this -> rear = NULL;
  this -> count = 0;
  node<T>* p = source.front;
  while(p!=NULL)
    {
      this -> addRear(p -> elem);
      p = p -> next;
    }
  /*
  node* temp;
  count = 0;
  front = NULL;
  rear = temp;
  temp = source.front;
  //front = this -> rear = NULL;
  //p = front;
  while(temp != NULL)
    {
      addRear(temp->elem);
      count ++;
      temp = temp -> next;
    }
  */
}
/*
void LL::llError(string msg)
{
  cout << "Queue Error" << endl;
  exit(1);
}
*/


template <class T>
T LL<T>::deleteFront()
{
  if(isEmpty() == true)//if is empty                                           
    llError ("Error: list is empty.");//cout error message                                            
  else//if not emoty                                                           
    {
      T temp = front -> elem;//creating a temporary slot and adding front element to it                                                                                                                     
      node<T>* second;//creating a node called second                                                                                                                                                           
      second = front ->next; //second is the node after first                                                                                                                                                 
      delete front; //deleting front                                                                                                                                                                           
      if(second == NULL) //if secind is null                                                                                                                                                                   
        front = rear = second; // front, rear, and secind get the same node                                                                                                                                    
      else //if second is not null                                                                                                                                                                             
	     
	  front = second; //front is set to second                                                                                                                                                             
	  count --; //decrease count                                                                                                                                                                               
	  return temp; // return temp value                                                                                                                                                                          
    }
}

template <class T>
void LL<T>::llError(string msg)
{
  cout << msg << endl;
}

template <class T>
bool LL<T>::search(T el)
{
  int s = 0;
  node<T>* p = front;
  while(p != NULL)
    {
      s++;
      if(p -> elem == el)
	{
	  //  cout << s << " nodes checked " << endl;
	  //cout << "found" << endl;
	  return true;
	}
      p = p -> next;
    }
  //cout << s << " nodes checked" << endl;
  //cout << "not found" << endl;
  return false;
}

template <class T>
void LL<T>::deleteNode(T el)
{
  node<T>* pre;
  node<T>* del;

  if (isEmpty() == true)
    return;
  else
    for(pre = front, del = front -> next; del != NULL && del -> elem != el; pre = del, del = del -> next);
  if(del != NULL)
    {
      pre -> next = pre -> next -> next;
      delete del;
      count --;
    }
  else if (pre == front || front -> elem == el)
    {
      deleteFront();
    }
  else 
    return;
}

template <class T>
void LL<T>::addInOrderAscend(T el)
{
  node<T>* p = front;
  if(front == NULL && rear == NULL)
    addFront(el);
  else
    {
      if(el < front -> elem)
	addFront(el);
      else if(el > rear -> elem)
	addRear(el);
      else 
	{
	  node<T>* n = new node<T>;
	  n -> elem = el;
	  while(p -> next != NULL && p -> next -> elem < el)
	    {
	      p = p -> next;
	    }
	  n -> next = p -> next;
	  p -> next = n;
	}
    }
}

template <class T>
void LL<T> :: getFront()
{ 
  return front;
}

template <class T>
void LL<T> :: getRear()
{
  return rear;
}

template <class T>
void LL<T> :: getNext()
{
  node<T>* p = p -> next;
  if(p = NULL)
    throw OutofBoundary ();
  else
    return p;
}
#endif