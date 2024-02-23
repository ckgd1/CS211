#include "student.h"
#include "array.h"

Student::Student()
{
  fN = "unknown";
  lN = "unknown";
  gen = 'X';
  stuID = -1;
  numClasses = 0;
}


Student::Student(string f, string l, char g, int i)
{
  fN = f;
  lN = l;
  gen = g;
  stuID = i;
  numClasses = 0;
}

int Student:: addCourse(int crn)
{
  int f = find(classes, numClasses, crn);
  // cout << "Numclasse has " ;  
  //cout << numClasses << endl;
   if (numClasses >= MAX)
    {
      //find(int ar[], int s, int crn);
      //if (find == found)
	return -1;
	//cout << "cannot be added.";
      // return false;
    }
 if(f != -1)
   {
    return 0;
   } 
 if(f == -1)
    {
      classes[numClasses++] = crn;
      // find(int ar[], int s, int crn);
      return 1;
    }  

 
  
}

void Student::viewAllCourses()
{
  print(classes, numClasses);
  
}

bool Student:: dropCourse(int crn)
{
  bool r = remove(classes, numClasses, crn);
  if (r == true)
    {
      numClasses--;
      return true;
    }
  else
    return false;
}

string Student::getFirstName() const
{
  return fN;
}

string Student::getLastName() const
{
  return lN;
}

char Student::getGender() const
{
  return gen;
}

int Student::getNumClasses() const
{
  return numClasses;
}

int Student::getStuID() const
{
  return stuID;
}

int Student::getClassOf(int i)const
{
  //find(classes, MAX, i);
  return classes[i];
}

Price Student::getBalance() const
{
  return balance;
}

void Student::addFee(int d, int c)
{
  Price p(d,c);
  balance  = balance + p;
}

void Student:: reduceFee(int d, int c)
{
  Price p(d, c);
  balance  = balance - p;
}
