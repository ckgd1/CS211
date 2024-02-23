#include "DLL.h"
#include <iostream>
#include <cstdlib>

using namespace std; 

DLL::DLL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

DLL::~DLL()
{
  while(isEmpty() == false)
    deleteFront();
}

void DLL::addRear(el_t el)
{
  // cout << front << endl;                                                               
  //cout << rear << endl;                                                                                                                                                         
  if(isEmpty())
    {
      rear = front = new node;
      front -> elem = el;
      rear -> prev = rear -> next = NULL;
    }
  else
    {
      //node* p = new node;                                                                   
      rear -> next = new node;
      rear -> next -> prev = rear;
      rear = rear -> next;
      rear -> elem = el;
      rear -> next = NULL;
    }
  count ++;
}
/*
  rear -> next = NULL;
  count ++;
  rear->elem = el;
  //cout << "end of add" <<endl;                                                                                                                      
}
*/
void DLL::displayAll()
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

bool DLL::isEmpty()
{
  return (front == NULL && rear == NULL && count == 0) ? true : false;
}


void DLL::addFront(el_t el)
{
  // node* p;
  //p = new node;
  // p -> elem = el;
  if(isEmpty() == true)
    {
      front = rear = new node;
      rear -> elem = el;
      //rear -> next = NULL;
      front -> prev = front -> next = NULL;
      //front = p;
      //rear = p;
      //  p -> next = NULL;
    }
  else 
    {
      front -> prev = new node;
      front -> prev -> elem = el;
      front -> prev -> next = front;
      front -> prev -> prev = NULL;
      front = front -> prev;
      /*
      node* p;
      p = new node;
      p -> elem = el;
      p -> next = front;
      front = p;
      */   
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




el_t DLL::deleteRear()
{
  if(isEmpty() == true)
    DllError ("Error: list is empty.");
  else if(count == 1)
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
      //node* temp = new node;
      el_t o = rear -> elem;
      rear = rear -> prev;
      //delete rear;
      //for( temp = front; temp -> next != rear; temp = temp -> next)
      //;
      delete rear -> next;
      //node* p = rear -> prev;      
      rear -> next = NULL;     
      count --;
      return o;
    }
      /*      
	      rear = te1mp;
	      re1ar -> next = NULL;
	      count --;
	      return o;
      */
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
DLL::DLL(const DLL& source)
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
void DLL::llError(string msg)
{
  cout << "Queue Error" << endl;
  exit(1);
}
*/


el_t DLL::deleteFront()
{
  if(isEmpty() == true)//if is empty                                           
    DllError ("Error: list is empty.");//cout error message                                            
  else if(count == 1)//if not emoty                                           
    {
      el_t temp = front -> elem;//creating a temporary slot and adding front element to it                                                                     
      el_t e = front -> elem;                                                
      delete front;
      front = rear = NULL;
      count --;
      return e;
    }
  else
    {
      el_t e = front -> elem;
      front = front -> next;
      delete front -> prev;
      front -> prev = NULL;
      count --;
      return e;
    }
}
/*
      node *second;//creating a node called second                                                                                                                                                           
      second = front ->next; //second is the node after first                                                                                                                                               
      secnd -> prev = NULL;
      delete front; //deleting front                                                                                                                                                
      if(second == NULL) //if secind is null                                                                                                                                                                   
        front = rear = second; // front, rear, and secind get the same node                                                                                                                                    
      else //if second is not null                                                                                                                                                                             
	  front = second; //front is set to second                                                                                                                                                             
	  count --; //decrease count                                                                                                                                                                           
	  return temp; // return temp value                                                                                                                                                                   
    }
}
*/

void DLL::DllError(string msg)
{
  cout << msg << endl;
}

bool DLL::search(el_t el)
{
  //int s = 0;
  node* p = front;
  while(p != NULL)
    {
      // s++;
      if(p -> elem == el)
	{
	  return true;
	  
	}
      p = p -> next;
      /*
	cout << s << " nodes checked " << endl;
	cout << "found" << endl;
	return true;
	}
	p = p -> next;
	}
	cout << s << " nodes checked" << endl;
	cout << "not found" << endl;
      */
    }
  return false;
}

void DLL::deleteNode(el_t el)
{
  //node* pre;
  node* del;
  
  if (isEmpty() == true)
    return;
  else if(front -> elem == el)
    deleteFront();
  else if(rear -> elem == el)
    deleteRear();
  else
    {
      for(del = front -> next; del != NULL && del -> elem != el; del = del -> next);
      if(del != NULL)
	{
	  del -> prev -> next = del -> next;
	  del -> next -> prev = del -> prev;
	  delete del;
	  count --;
	}
    }
}
/*
 else if (pre == front || front -> elem == el)
   {
     deleteFront();
    }
  else 
    return;
}
*/
void DLL::addInOrderAscend(el_t el)
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
	  node* nn;
	  while(p -> next != NULL && p -> next -> elem < el)
	    {
	      p = p -> next;
	    }
	  nn = p -> next;
	  n -> next = nn;
	  n -> prev = p;
	  nn -> prev = n;
	  p -> next = n;
	  count++;
	  //p -> next = n;
	}
    }
}
/***********************************************************************
This function is going to print elements from rear to front. 
NOT in a recursive way.
*********************************************************************/

void DLL::printAllReverseDLL()
{
  if(isEmpty() == true)//if it is empty we display empty
    cout << "[empty]" << endl;
  else //if not empty
    {
      node* r = rear; //create a new node 
      while(r != NULL)//while the new node is not null
	{
	  cout << r -> elem << " " ;//display the element in new node
	  r = r -> prev;//move new node to previous node
	}
    }
}
