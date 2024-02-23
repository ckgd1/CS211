#include <iostream>
#include <string>
#include "LL.h"
using namespace std;

class Person
{
protected:
  static int num; // (the total number of people created) 
  static int current_id; //(initialize it to 1000) 
  const int ID; //(everybody at school has a unique ID such as a student id, employee id, faulty id. ID should be set to current_id.) 
  string fn; //(default value = unknown) 
  string ln; // (default value = unknown) 
  string SSN; //= "unknown"; //(111-222-3333) (default value = 000-00-0000) 
  string email; // = "unkown"; // (default value = unknown) 

public:
  Person(string f = "unknown", string l = "unknown", string mail = "unknown", string s = "000-00-0000");
  void printInfo();
  int getNum();
  int getID();
};

int Person::num = 0;
int Person::current_id = 1000;

/**********************************************************************
                            VIRTUAL
*****************************************/
virtual void printInfo(){}
//virtual void node<T*> :: getFront(){}

//virtual void LL<T> :: getNext(node<T>*){}

//virtual void node<T>* :: getRear(){}

Person::Person(string f, string l, string mail, string s):ID(current_id)
{
  fn = f;
  ln = l;
  email = mail;
  SSN = s;
  current_id ++;
  num++;
}

void Person::printInfo()
{
  cout << "First Name: " << fn << "\n" << "Last Name: " << ln << "\n" << "Email: " << email << "\n" << "SSN: " << SSN << "\n" << "ID: " << ID << endl;
}

int Person::getNum()
{
  return num;
}

int Person::getID()
{
  return current_id;
}

class Faculty : public Person
{
private:
  int departid;
  int yrs;
  
public:
  Faculty(string f = "unknown", string l = "unknown", string mail = "unkown", string s = "unknown", int d = -1, int y = -1): Person(f, l, mail, s)
  {
    departid = d;
    yrs = y;
  }
  void printInfo()
  {
    Person::printInfo();
    cout << "Department ID: " << departid << "\n" << "Years at School: " << yrs << endl;
  }
};


class Student : public Person
{
private:
  string major;
  float gpa;
  char grade;

public:
  Student(string f = "unknown", string l = "unknown", string mail = "unknown", string s = "unknown", string m = "unknown", float gp = -1.00, char g = '?'):Person(f, l, mail, s)
  {
    major = m;
    gpa = gp;
    grade = g;
  }
  void printInfo()
  {
    Person::printInfo();
    cout << "Major: " << major << "\n" << "GPA: " << gpa << "\n" << "Grade: " << grade <<endl;
  }
};

void readData

void sort(int ar[], int n)
{
  int lrgIndx;
  int temp;
  for(int last = n-1; last >= 1; last --)
    {
      lrgIndex = 0;
      for (int i = 1; i <= last; i++)
	{
	  if (ar[i] > ar[lrgIndx])
	    lrgIndex = i;
	}
      temp = ar[lrgIndx];
      ar[lrgIndx] = ar[last];
      ar[last] = temp;
    }
}

int main()
{
  ifstream fin;
  fin.open("campus.dat");

  cout << "Printing everyone in the list --------" << endl;

  /*
    Faculty f("Kathy", "Ross", "222-33-4444", "kathy@csusm.edu", 100, 2);
  f.printInfo();
  Student s("Tom", "Lopez", "333-44-5555", "tom@csusm.edu", "CS", 3.33, 'J');
  s.printInfo();
  */  
  return 0; 
}
