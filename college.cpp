#include <iostream>
#include <fstream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include "array.h"
#include "student.h"


const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

void addStu(Student ar[], int& n, int& i);
void showStuInfo(Student& s);
void allStuInfo(Student ar[], const int n);
bool operator==(const Student& s, int stuID);
void addStuFromFile(Student ar[], int& n, int& id);
bool removeStu(Student ar[], int& n);
int showMenu();
int showAdmMenu();
int showStuMenu();
void addCourse(Student& s);
void dropCourse(Student& s);
void makePayment(Student& s);
bool checkPassword();
int findStu(Student ar[], int n);
void viewStuInfo( Student ar[], int& n, int id);

int main()
{
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating
  Student ar[SIZE];//array of students  
  int ch;
  int choice;
  int id;
  int selec;
  //int pw = id % (PRIME1 * PRIME2);
  do //beginning my do while
    {
      ch = showMenu(); //setting showmenu to an int for choice
      switch (ch) //switching cases
	{
	case 1: 
	  // int password = 123;
	  if (checkPassword() == true)//if password is equal to true	  
	    do //another do while loop
	      {
		choice =  showAdmMenu();//setting showadmmenu to an int for choice
		//choice = showAdmMenu();
		if(choice == 1) //if choice is 1
		  addStu(ar, count, curID);//we add a student
		else if(choice == 2)//if choice is 2
		  addStuFromFile(ar, count, curID);//we add a student from a file
		else if (choice == 3)//if choice is 3 
		  removeStu(ar, count);//we remove a student
		else if(choice == 4)//if choice is 4
		  {
		  cout << "Enter the student id: ";
		  cin >> id;
		  int f = find(ar,count, id); // searching for id
		  if(f == -1) //if id is not found we display error message
		    cout << "The student ID doesn't exist." << endl;
		  else
		    showStuInfo(ar[f]); //if found we show student information
		  }
		else if (choice == 5) //if choice is 5
		  allStuInfo(ar, count); // we show all student info
	      }
	    while (choice != 6); //we do showadmmenu whie choice is not 6
	  /*	  
		  else
	    showMenu();
	  	  
	  else
	    ch = showMenu();
	  */	  
	  break;
	case 2: 
	  //int stuid;
	  int found;
	  int pasw;
	  int stuid;
	  int stuid2;
	  cout << "Enter the student id: ";
	  cin >> id;//asking for student id
	  //findStu(ar, count);
	  found = find(ar, count, id);//setting find to found for an easier 
	  if(found == -1)//if not found we display error message
	    cout << "Student ID doesn't exist." << endl;
	  else
	    {
	      //int pw = stuid % (PRIME1 * PRIME2);
	      cout << "Enter the password: ";//asking for password
	      cin >> pasw;
	      stuid2 = ar[found].getStuID(); //setting stuid to to the id of the found
	      stuid2 = stuid2 % (PRIME1 * PRIME2);//setting stuid2 to the pasword we want
	      if(pasw != stuid2)//if pasw is not equal to stuid2
		{
		  cout << "The password is wrong." << endl;//error message
		}	     
	      else 
		{
		  cout << "Welcome " << ar[found].getFirstName() << endl;//welcoming the persin
		  cout << endl;
		  do//starting a do while loop for the showstumenu
		    {
		      selec = showStuMenu();//setting student menu to an int
		      if(selec == 1) //if choice is 1
			addCourse(ar[found]);//adding course to student
		      else if(selec == 2)//if choice is 2
			dropCourse(ar[found]);//dropping course
		      else if (selec == 3)//if choice is 3
			makePayment(ar[found]);//making a paynent in student account
		      else if (selec == 4)//if choice is 4
			showStuInfo(ar[found]);//showing students info
		    }
		  while(selec != 5);//ending the showstumenu loop
		  break;
		}	
	    }
	}
      /*  
	  else
	  cout << "The student ID doesn't exist." << endl;
	  //showStuMenu(); 
	  */
    }
  
  while (ch != 3);//ending the first do while loop, the loop will keep going while main menu choice is not three      
/*
	cin >> c;
  if(c == 1)
    checkPassword(123);
  showAdmMenu();
 
      else
      showStuMenu();
  */
  /*
  cout << "-------- adding the first student --------" << endl;
  addStu(ar, count, curID);
  cout << "-------- showing the first student --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 111 to a student --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 222 to a student --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 222 again to a student ==> error --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- removing 222 --------" << endl;
  dropCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- removing 333 ==> error --------" << endl;
  dropCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
 
  
  cout << "########################################################################################" << endl;
  cout << "If you didn't work on bonus feature, enter 20 0. If you did, enter 20" << endl;
  cout << "########################################################################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "########################################################################################" << endl;
  cout << "If you didn't work on bonus feature, enter 10 14. If you did, enter 10.14" << endl;
  cout << "########################################################################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "########################################################################################" << endl;
  cout << "Did you work on the bonus feature where you reject an over payment? Enter Y or N:";
  char ans;
  cin >> ans;
  if(ans == 'Y' || ans == 'y')
    {
      cout << "-------- For bonus, making an overpayment ==> show error and won't be processed --------" << endl;
      makePayment(ar[0]);
      cout << "-------- showing the info --------" << endl;
      showStuInfo(ar[0]);
    }
  else
    cout << "You didn't work on the bonus feather for overpayment" << endl;
 /*  
Student stua("Christina", "Garcia", 'f');  
  addCourse(st, 112);
  showStuInfo(ar[0]);   

  addStu(ar, curID, count);//adding one student
  showStuInfo(ar[0]);//showing the first student in the array info
  addStu(ar, curID, count); // adding another stu
  addStu(ar, curID, count); //adding anther student
  addStu(ar, curID, count);//adding another student
  allStuInfo(ar, SIZE);  //showing all students info
  
  cout << "-------- adding the first student --------" << endl;
  addStu(ar,count, curID);
  cout << "-------- showing the first student --------" << endl;
  showStuInfo(ar[0]);  //pass the first student
  cout << "-------- adding student 2, 3, and 4 --------" << endl;
  addStu(ar, count, curID);
  addStu(ar, count, curID);
  addStu(ar, count, curID);
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(ar, count);
  cout << "-------- removing stu 2 --------" << endl;
  removeStu(ar, count); //remove the second stu
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(ar,count);
  cout << "-------- removing the last student --------" << endl;
  removeStu(ar,count); //remove the last stu
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(ar, count);
  cout << "-------- adding from file --------" << endl;
  addStuFromFile(ar, count, curID);
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(ar,SIZE);
  */
return 0;
}



// ************************  PHASE 1  ****************************
//this function will ask input to add their information, will add it to the array, and set an id to user
void addStu(Student ar[], int& n, int& i)
{
  //case 1 of admission
  if(n == SIZE)//if the array is full we cout an error message
    cout << "Full" << endl;
  else//if array is not full we ask for user input
    {
      string FN;
      string LN;
      char gend;
      cout << "Enter first name: ";
      cin >> FN;
      cout << "Enter last name: ";
      cin >> LN;
      cout << "Enter your gender: ";
      cin >> gend;
      //create a student object. The first student created is given a stu id, 100000 (coming from const START).
      Student s(FN,LN, gend, i++); //created one student with stu id
      //The second student gets 100001, the third student gets 100002, etc (notice curID in main).
      
      //copy the info from the stu obj into the array at the appropriate slot
      ar[n++] = s;//copying array info
      //n++;
      //i++;//updating stuid
    }
}

void showStuInfo(Student& s)                                                                                       
{                                                                                                                                             
  //*********************************************************************
  //DO NOT send the entire array to this function. BIG deduction if you do.
  //SEND only ONE student object as a parameter. If you don't know how, check
  //lab1-struct.cpp.
  //********************************************************************** 
  
  cout << "--------------------" << endl;                                                         
  
  cout << "first name: " <<  s.getFirstName()  << endl;                                                                                                 
  
  cout << "last name: " << s.getLastName()  << endl;                                                                                                  
  
  cout << "gender: " << s.getGender() << endl;                                                                                                      
  
  cout << "stu id: " << s.getStuID() << endl;                                                                                                      
  
  cout << "num classes: " << s.getNumClasses()  << endl;                                                                                                  
  
  
  cout << "Courses: ";                                                                                                                        
  
  for(int i = 0; i < s.getNumClasses() ; i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?      
    cout << s.getClassOf(i)  << ", ";                                                                                                                 
  
  
  cout << "\nAmount owed $" << s.getBalance()  << endl;  //You have an operator overloading function to show a price object at once                   
  
  cout << endl;                                                                                                                               
  
}


void allStuInfo(Student ar[], const int n)
{
  //Case 5 of Admission and case 4 of student
  //Call showStuInfo()
  //******************************************
  //YOU MUST call showStuInfo() to show each student.
  //*******************************************
  if (n == 0)//of the array size is 0 there are no students
    cout << "No students enrolled." << endl;
  else
    {
      for(int i = 0; i < n; i++)//for each sstudent in the array we will show their info
	showStuInfo(ar[i]);
    }
}


bool operator==(const Student& s, int id) 
{

  if(s.getStuID() == id)//if get stuid is equal to id we return true
    return true;
  else 
    return false;
}


bool removeStu(Student ar[], int& n)
{
  //Case 3 of Admission
  int id;
  //2 different messages

  cout << "Enter student id: ";
  cin >> id;
  int f = find(ar, n, id);//using find to find id
  //Student s;
  if(f == -1)//if id was not found
    cout << "student with id " << id << " doesn't exist" << endl;
  else // if id was founf
    {
      string fn = ar[f].getFirstName();
      string ln = ar[f].getLastName();
      bool r = remove(ar, n, id);
      if(!r)
	cout << "student with is " << id << " doesn not exist." << endl;
	else 
	  {
	    n--;
	    cout << fn<< " " << ln << " has been removed." << endl;	    
// getFirstName() << " " << getLastName() << " has been removed." << endl;
	  }      
    }
}

void addStuFromFile(Student ar[], int& n, int& id)
{
  //Case 2 of admission
  string filename;
  string fst;
  string lst;
  char gende;
  ifstream fin;
  //int i = 0; 
  cout << "Enter the input file name that has student's info: ";//asking user to input filename
  cin >> filename;
  fin.open(filename.c_str());//opening filename
    if(!fin)//if we cannot open filename
      cout << "cannot open file." << endl;
    else
      {
	fin >> fst >> lst >> gende;
	while(fin && n < SIZE)//if filename is open
	  {
	    Student s(fst, lst, gende, id++);
	    ar[n++] = s;//update array
	  //cout << "Enter first name: ";
	  fin >> fst >> lst >> gende;
	  }
	fin.close();
	//cout << "Enter last name: ";
	//cout << "Enter your gender: ";
	//cout << "Student ID: ";
      }
}






//*******************  PHASE 2 ****************************


void addCourse(Student& s)
{
  int crn;
  //case 1 of student
  //FYI, I am passing one student to this function not the array. 
  //int crn;
  cout << "Enter a crn: ";
  cin >> crn;//getting user input
  int i = s.addCourse(crn);//setting addcourse to an easier object
//3 different messages to show
  if(i == 1)//crn can be added
    {
      cout << crn << " has been added successfully" << endl;
      // while(i == 1)      
      s.addFee(50, 14);//adding fee each time a crn is added
    }
  else if(i == 0)//crn cannot be added because it already exists
    cout << crn << " was not added because you have " << crn << " already." <<  endl;
  else if(i == -1)  //if crn cannot be added because array is full
    cout << crn <<" was not added because your schedule is full." <<  endl;


}

void dropCourse(Student& s)
{
  int crn;
//case 2 of admission
//FYI, I am passing one student to this function not the array. 
  cout << "Enter a crn: " ; //asking user to enter crn
  cin >> crn;//getting crn from user
  bool scrn = s.dropCourse(crn);//setting dropcourse into an easier object
//2 different messages
  if(scrn != true)//if course was not found
    cout << crn <<" wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist" << endl;
  else
    {
      cout << crn << " has been dropped successfully." << endl;//course has been removed
      s.reduceFee(50, 14);//subtracting fee
    }
}


void makePayment(Student& s)
{
  int d;
  int c;
  //case 3 of student
  //FYI, I am passing one student to this function not the array.  
  //cin >> s.getBalance();
  cout << "You owe $" << s.getBalance() << endl;//showing how much they owe
  cout << "Enter your payment: ";  
  cin >> d >> c;//getting the user input
  s.reduceFee(d, c);//subtracting the users input from balance
  /*
  if(s.addFee(d, c) > s.getBalance())
    {
      cout << "Error, cannot make payment" << endl;
    }
  */
}





//******************** PHASE 3 ****************************

bool checkPassword()
{
//I am using this function to check a password for both the admission's office and student
//FYI, I am passing the correct password as a parameter and returning true/false.
  int pw;
  cout << "Enter the password: ";
  cin >> pw; 
  if(pw != PASSWORD)
    {    
      cout << "The password is wrong." << endl;
      return false;
    }
  //pw = 123;
  else 
    return true;
  //pw = 
  //The correct password for a student is  student_id % (PRIME1 * PRIME2)
}


int findStu(Student ar[], int n)
{
//Small function. You may choose not to use this function. That is OK.
  int id;
  //Ask for the student id
  cout << "Enter your student id: ";
  cin >> id;
  //int f =
  return find(ar, n, id);
  //call find() to find the student id
  //if(s.id == ar[f].id)
  //return f;
  //return what find() returned which is index where it was found or -1
}


void viewStuInfo(Student ar[], int& n, int id)
{
  // int id;
//Case 4 of admission
//Ask for the student id
  //cout << "Enter Student id: ";
  //cin >> id;
  int f = findStu(ar, n);
//If the student doesn't exist, show an error message.
  if(f == -1)
    cout << "Student does not exist. " << endl;
//If it exists, call showStuInfo to show the student
  else 
    showStuInfo(ar[f]);
}

/*
int verifyStu(Student ar[], int n)
{
//You may decide not to use this function. If so, that is OK.
  int id;
//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
  cout << "Enter the student id: ";
  cin >> id;
  int f = find(ar,n ,id);
  if(f == -1)
    cout << " 
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
}

*/

int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}


int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}



