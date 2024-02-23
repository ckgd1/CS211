#include "LL.h"
#include <iostream>
#include <cstdlib>

using namespace std; 

LL::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

LL::~LL()
{
  while(isEmpty() == false)
    deleteFront();
}

void LL::addRear(el_t el)
{
  // cout << front << endl;                                                               
  //cout << rear << endl;                                                                                                                                                         
  if(isEmpty())
    {
      rear = new node;
      front = rear;
    }
  else
    {
      //node* p = new node;                                                                   
      rear -> next = new node;
      rear = rear ->next;
    }
  rear -> next = NULL;
  count ++;
  rear->elem = el;
  //cout << "end of add" <<endl;                                                                                                                      
}

void LL::displayAll()
{
  node *p = front;
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

bool LL::isEmpty()
{
  return (front == NULL && rear == NULL && count == 0) ? true : false;
}


void LL::addFront(el_t el)
{
  // node* p;
  //p = new node;
  // p -> elem = el;
  if(isEmpty() == true)
    {
      front = rear = new node;
      rear -> elem = el;
      rear -> next = NULL;
      //front = p;
      //rear = p;
      //  p -> next = NULL;
    }
  else 
    {
      node* p;
      p = new node;
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




el_t LL::deleteRear()
{
  if(isEmpty() == true)
    llError ("Error: list is empty.");
  else if(count == 1 && front == rear)
    {
      el_t o = rear -> elem;
      delete rear;
      front = NULL;
      rear = NULL;
      count --;
      return o;
    }
  else
    { 
      node* temp = new node;
      el_t o = rear -> elem;
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
LL::LL(const LL& source)
{
  this -> front = this -> rear = NULL;
  this -> count = 0;
  node* p = source.front;
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


el_t LL::deleteFront()
{
  if(isEmpty() == true)//if is empty                                           
    llError ("Error: list is empty.");//cout error message                                            
  else//if not emoty                                                           
    {
      el_t temp = front -> elem;//creating a temporary slot and adding front element to it                                                                                                                     
      node *second;//creating a node called second                                                                                                                                                           
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

void LL::llError(string msg)
{
  cout << msg << endl;
}

bool LL::search(el_t el)
{
  int s = 0;
  node* p = front;
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

void LL::deleteNode(el_t el)
{
  node* pre;
  node* del;

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

void LL::addInOrderAscend(el_t el)
{
  node* p = front;
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
	  node* n = new node;
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

