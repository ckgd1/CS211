#include "lqueue.h"
#include <iostream>
#include <cstdlib>

LQueue::LQueue()
{
  front = NULL;//setting front to null
  rear = NULL;//setting rear to null
  count = 0;//setting count to 0
}

void LQueue::addRear(el_t el)
{
  // cout << front << endl;
  //cout << rear << endl;
  if(isEmpty())//if is empty is true
    {
      rear = new node;//creating a new node
      front = rear; //setting front to rear
    }
  else//if not empty
    {
      //  node* p = new node;
      rear -> next = new node;//creating a new node
      rear = rear ->next; // rear is now the next node
    }
  rear -> next = NULL; // new node is set to null
  count ++; //adding to count
  rear->elem = el; 
  //cout << "end of add" <<endl;  
}

void LQueue::displayAll()
{
  node *p = front; // creating a new node and setting it to front
  if(isEmpty() == true) // if is emoty
    cout << "[empty]" << endl; // we cout empty
  else // if not emoty
    {
      while(p != NULL) // while our nodes are not null
	{
	  cout << p->elem;//cout the elements
	  p =  p->next; // move to next node
	}
    }
}

bool LQueue::isEmpty()
{
  return (front == NULL && rear == NULL && count == 0) ? true : false;//if front, rear, and count are null the lqueue is empty
}

LQueue::~LQueue()
{
  while(isEmpty() == false)// if not empty
    //if(count == 1)
    deleteFront();//delete frint
  //else if(count > 1
    /*
if (ar != NULL)
  delete [] ar;
    */
}
el_t LQueue::deleteFront()
{
  if(isEmpty() == true)//if is empty
    queueError ("Error: list is empty.");//cout error message
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
void LQueue::queueError(string msg)
{
  cout << "Queue Error" << endl; //error message returned
  exit(1);
}

void LQueue::printAllReverse()
{
  printAllReverse(front);//printing in reverse form from front
}

void LQueue::printAllReverse(node* p)
{
  if(p == NULL)// if p is null
    return;//we return from funtion
  else // if not null
    {
      printAllReverse(p -> next);//we print from p to the next
      cout << p -> elem; // couting the element in each node
    }
}
