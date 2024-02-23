#include <iostream>
#include "lqueue.h"
#include <string>
#include <cstdlib>

using namespace std; 

void createReverseLL(LQueue& l, const string& s);
void addLLs(LQueue& l1, LQueue& l2, LQueue& total);
//prototypes 
int main()
{
  string n1, n2;//integers user will input
  cout << "Enter the first number: ";
  cin >> n1;
  cout << "Enter the second number: ";
  cin >> n2;

  LQueue l1;//first lque and first #
  createReverseLL(l1, n1);

  LQueue l2;// secind lqueue and second #
  createReverseLL(l2, n2);

  l1.displayAll();//displayig all l1
  cout << " + ";
  l2.displayAll(); //displaying all l2
  cout << " = ";

  LQueue total; //using total to show the first two lls

  addLLs(l1, l2, total); //adding both numers together

  total.displayAll(); //displayig the total
  cout << endl;

  cout << n1 << " + " << n2 << " = "; //showing n1 and n2 without reversing

  total.printAllReverse();
  cout << endl;

  return 0;
}
void createReverseLL(LQueue& l,const string& s)
{
  for (int i = s.size() - 1; i >= 0; i--)
    { 
      int temp = (int)s[i] - 48;
      l.addRear(temp);
    }
}
/*
  node* first = front;
  node* previous = NULL;
  node* next = NULL;

  while(first != NULL)
    {
      next = first -> next;
      first -> next = previous;
      previous = first;
      first = next;
    }
  front = previous;
}
*/
void addLLs(LQueue& l1, LQueue& l2, LQueue& total)
{
  int add;
  int n1;
  int n2; //numbers to be added and total
  int carryon = 0; //carry starts at 0, because there is none
  while(l1.isEmpty() == false || l2.isEmpty() == false)//l1 and l2 are not empty
    {
      if(l1.isEmpty() == true)//l1 is empty
    	n1 = 0;//n1 is equal to 0
      else 
	n1 = l1.deleteFront();//if not empty we deletefront
      if (l2.isEmpty() == true)//l2 is empty
	n2 = 0;//n2 is equal 0
      else 
	{
	  n2 = l2.deleteFront();//if not empty we deletefront
	  add = n1 + n2 + carryon;// we add all 3 variables including carryon
	}
      if (add >= 10)//when adding if more than 10 we add a carryon
	{
	  add = add % 10;//getting the carryon 
	  carryon = 1;
	}
      else 
	{
	  carryon = 0;//if the carryon is 0 we just add everthing
	  total.addRear(add);
	}
      if(carryon >= 1) //if the carryon is greater than one we add it
	total.addRear(carryon);

}
}