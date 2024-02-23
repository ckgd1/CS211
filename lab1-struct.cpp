
/*******************************************
Christina Garcia 
CS211 Slott 
lab1
1-21-2020

In this lab we will be creating an input file and filling in the ???.  Description of this program
*******************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
//???????? need more header files?
using namespace std;


//???????? Where do the prototypes go?

struct Student // Declare the struct called student
{
  int id;
  string fname;
  string lname;
  int age;
};

int getStuData(Student students[]);
//int getStuData(Student []);
int findID(Student students[], int size, int key);
//int findID(Student [], int s, int key);
void displayAllStu(const Student ar[], int s);
//void displayAllStu(const Student [], int s);
void displayStu(Student s);
int findYoungOld(Student students[], int& s, int& k, int nums);
//int findYoungOld(Student ar[], int& s, int& k);
  
  const int MAX = 20; // ? Decare a constant called MAX and set it to 20. //The maximum number of students the array can hold

int main()
{
  ifstream fin;
  ofstream fout;

  fin.open("student.dat");
  int total = 0;
  int count = 0;
  // Student data;
  

  Student stu;
  stu.id = 1000;
  stu.fname = "Lucy";
  stu.lname = "Smith";
  stu.age = 20; //  create a student called stu and set 1000, Lucy, Smith, 20 to it
  
  displayStu(stu); //?????????? display stu by calling displayStu                                                                                                 
   
  Student students[MAX]; //?????????? Create an array of students using MAX

  int num; //it holds the number of students or -1 if the input file didn't exist

  num = getStuData(students); //?????????? call the getStuData function to fill the array with students' information
  //getStuData returns the number of students or -1 if the file doesn't exist
    

  if(num == -1) //????????? 
    { 
      cout << "The file didn't exist." << endl;
    }
  //?????????
  else 
    {
      if (num == 0)
	{ 
	  cout << "There are no students in the input file." << endl; //The file existed but it was empty  
	}
      else
	{ 
    
	  //?????? //The input file had at least one student 
    
	  displayAllStu(students, MAX); //??????  show all the students' info by calling displayAllStu 
     
	  int look; //The id the user is looking for
	  cout << "\nEnter the id you are looking for: ";
	  cin >> look;

      //Find a student with the id you are looking for and display the information about that student. If no student has the id, show an appropriate message.
	  bool found = true;	  
	  if (look == found)
	    {	 
	    findID(students,MAX,look);  //?????????????  Call findID  
       //The id the user was looking for was found
	  displayStu(students[look]);
	    }
           //display the info on the student with that id by calling displayStu
	  else  //else
	    {	   
	      cout << "No student with id " << look << " was found" << endl;
	    }
      
      //find the youngest and oldest students by calling findYoungOld
	  int yngInd; //index of the yougest student
	  int oldInd; //index of the oldest student
	  findYoungOld(students, yngInd, oldInd, MAX);//??????????? call findYoundOld

	  cout<< "\nThe youngest Student -----" << endl;
	  displayStu(students[yngInd]); //??????????? call displayStu to show the youngest student's info

	  cout<< "\nThe oldest Student -----" << endl;
	  displayStu(students[oldInd]); //?????????? call displayStu to show the oldest student's info
	}
    }
  
  cout << endl;
   
  return 0;
}
 
//This function loads students' data into the array and returns the number of students;
  int  getStuData(Student students[])
  {
    ifstream fin;
   
  // numstudents = 0;
    string filename;
    Student s;
    int i = 0;
    // ifstream fin;
  cout << "Enter the input file name that has the students' info: ";
  cin >> filename; 
  fin.open(filename.c_str());
  if (!fin)
    return -1;
 
  fin >>s.id;
  fin >> s.fname;
  fin >> s.lname;
  fin >> s.age;
 
  while (fin)
    {
    students[i++] = s;
  
     fin >>s.id;
     fin >> s.fname;
     fin >> s.lname;
     fin >> s.age;
    }
// cout << "The total number of students is " << numstudents << "." << endl; 
return i;
}

/* This function searches through the array to find the student with the id the user is looking for.
      The user is asked to enter the id she is looking for in the main.
      Return the index where the student with the id was found or -1 if not found. */

int findID(Student students[], int size, int key)
{
  for (int i = 0; i < size; i ++)
    if (students[i].id == key)
      {
      return i;
      }
  return -1;
}


/*Pass the student array and call displayStu to show each student */

void displayAllStu(const Student ar[], int s)
{
  for (int i = 0; i < s; i++)
    displayStu(ar[i]);

   //call displayStu to show each student;

}

  /*One student struct is passed to this function and display all the information (id, fName, lName and age) about that student.*/

void displayStu(Student s)
{
  cout << left;
  cout << setw(10) << "ID";
  cout << setw(20) << "FIRST NAME";
  cout << setw(20) << "LAST NAME";
  cout << setw(15) << "AGE";
  cout << "-------------------------------------------"<< endl;
  cout << s.id;
  cout << s.fname;
  cout << s.lname;
  cout << s.age << endl;

}


/*This function will pass back the *indices* of the youngest and oldest students */

int findYoungOld(Student students[], int& s, int& k, int nums)
{

   s = 0;
  for (int i = 1; i <nums;i++)
    if(students[i].age < students[s].age)
      s  = i;

  //return ar[youngest];
  

   k  = 0;
   for(int i = 1; i < nums;i++)
     if(students[i].age>students[k].age)
       k = i;

   // return ar[oldest];

}

