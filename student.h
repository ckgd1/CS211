
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "price.h"
using namespace std;

const int MAX = 6;

class Student
{
 private:
  string fN;
  string lN;
  char gen;
  int stuID;
  int numClasses;
  int classes[MAX];
  Price balance;
 public:
  Student();
  Student(string f, string l, char g, int i);
  int addCourse(int crn);
  void viewAllCourses();
  bool dropCourse(int crn);

  string getFirstName() const;
  string getLastName() const;
  char getGender() const;
  int getNumClasses() const;
  int getStuID() const;
  int getClassOf(int i) const;
  Price getBalance() const;
  void addFee(int d, int c);
  void reduceFee(int d, int c);
  void addStu();
};

#endif 