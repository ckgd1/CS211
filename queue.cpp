#include "queue.h" 
#include <iostream>
#include <cstdlib>

Queue::Queue()
{
  count = 0;
  front = 0;
  rear = -1;
}

bool Queue::isEmpty()
{
  return (count == 0) ? true : false;
}

bool Queue::isFull()
{
  return (count == QUEUE_SIZE) ? true : false;
}

void Queue::add(el_t e)
{
  if (isFull() == true)
    queueError("Overflow");
  else 
    {
      rear = (rear+1) % QUEUE_SIZE;
      el[rear]=e;
      count ++;	
    }
  
}

el_t Queue::remove()
{
  if(isEmpty() == true)
    {
      queueError("Underflow");
      exit(1);
    }
  else 
    {
      el_t temp = el[front];
      front = (front+1) % QUEUE_SIZE;
      count--;
      return temp;
    }
  
}

el_t Queue::getFront()
{
  if(isEmpty() == true)
    queueError("No Elements");
  else 
    return el[front];
}

void Queue::goToBack()
{
  if(isEmpty() == true)
    queueError("Empty");
  else if (QUEUE_SIZE == 1)
    cout << " " << endl;
  else 
    {
      el_t temp = remove();
      add(temp);
    }

}
int Queue::getSize()
{
  int size = count;
  return count;
}

ostream& operator<<(ostream& out, const expr& e)
{
  out << e.oprd1 << " " << e.oprt << " " << e.oprd2;//show 5+8
  return out;
}
 

void Queue::displayAll()
{
  if(isEmpty() == true)
    cout << "[empty]" << endl;
  else 
    for(int i = front; i != rear;i = (i+1)%QUEUE_SIZE)
      {
	cout << "[" << el[i] << "]";
      }
  cout << "[" << el[rear] << "]";
}

void Queue:: queueError(string msg)
{
  cout << "Queue Error" << endl;
  exit(1);
}
