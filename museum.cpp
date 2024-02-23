#include <iostream>
#include <fstream>
#include "array.h"
#include "/cs/slott/cs211/checkInput.h" 
//template <class O>

int showMenu();
void getVisitorInfo(string c[], int a[], double h[], int& v);
bool checkPassword(int password);
void showStatistic (string c[], int a[], double h[], int& v);
//prototypes
int main ()
{
  
  string country[100]; //array of string for countries
  int age[100]; // array of int for age
  double hours[100]; //array of double for hours
  int visitornum = 0; // # of visitors
  int choice = showMenu(); // show menu depending on choice
  int pw = 0;  // password is set to 0 at first
  string date; 
  while(choice == 1)//if choice one is chosen we will ask visitors for info
    {
      getVisitorInfo(country,age,hours,visitornum);
      choice = showMenu(); // show main menu again
    }  
  if (choice == 2)//while choice 2 is chosen we will check password 
    {
      // pw = false;
      checkPassword(pw);

             
      if (true)// if password is correct we will show statistic
	{
	  showStatistic(country,age,hours,visitornum); //statistic
	  // cout << "Do you want to close museum? Y or N: "; 
	  // getYN("Invalid Answer. Enter Y or N: ");
	  if('Y')//if yes is chosen we will ask for date 
	    //didn't work for me
	    {
	      cout << "Enter today's date: ";
	      cin >> date;
	    }  	 
	  else //if N is chosen we will show menu again
	    choice = showMenu();
	  // // if (a == 'N')
	  // // choice = showMenu();
	  // // checkPassword(pw);
	  // // choice = showMenu();
	  //checkPassword(pw);
	}
      else 
	{ 
	  while(false)// if password is incorrect we will show menu again
	    {
	      choice = showMenu();
	      checkPassword(pw);
	    }
	}
      /*
	  if (pw == true)
	    showStatistic(country,age,hours,visitornum);	  
	  cout << endl;
	  cout << endl;
	}

  // else(pw == true);
	    {
	    showStatistic(country,age,hours,visitornum);   
	    }
      */
    }
  
  return 0;
}
int showMenu() 
{
  //we will be showing the user the menu and they can decide if they are a visitor or museum staff  
  cout << "==================" << endl;
  cout << "1. Visitor" << endl;
  cout << "2. Museum Staff" << endl;
  cout << "Enter your choice: " ;
  int choice = getData(1,2, "Invalid Choice. Enter 1 or 2: ");//if user doesnt choose 1 or 2 an error message will display 
  
  //cin >> choice;

  return choice;
}

void getVisitorInfo(string c[], int a[], double h[], int& v)//asking visitors for their info and storing it into arrays
{
  // int choice;// = getData(1,2, "Invalid Choice. Enter 1 or 2: ");
  //if (choice == 1)
  //{
  // int visitors = 0;
      cout << "Enter your country: ";
      cin >> c[v];
      
      cout << "Enter your age: ";
      // cin >> a[v];
      a[v] = getData(0,200, "The age has to be between 0 and 200. Enter again: ");   //using getData to get an adecuate age

      cout << "Enter the number of hours you explored: ";
      //cin>> h[v];       
      h[v] = getData(0.0, 10.0, "The number of hours has to be between 0 and 10.0. Enter again: "); //using getData to get correct number of hours
      v++; // }
}

bool checkPassword(int password)//checking if password is correct of not
{ 
  // int choice;
  // if(choice == 2)
  cout <<  "Enter the password: ";
  cin >> password;
  if(password != 5678)
    {   
      cout << "Password is wrong." << endl;
      return false;
    }  
  else 
    return true;
}

//template<class O>
void showStatistic(string c[], int a[], double h[], int& v)//displaying the statistics 
{
  ofstream fout;
  string date;
  string filename;
  char ans;
  cout << "The total number of visitors is " << v  << endl;
  cout << " ----- The names of the countries of visitors ----- " << endl;
  sort(c, v+1);
  print(c,v+1);
  cout << endl;
  cout << endl;  
  cout << "The age of the youngest visitor: " <<a[getLowest(a, v)] << endl;
  cout << "The age of the oldest visitor: " << a[getHighest(a,v)] << endl;
  cout << "The average age of the visitors: " << getAvg(a,v) << endl;
  cout << endl;
  cout << "The shortest visit: " <<h[getLowest(h,v)] << endl;
  cout << "The longest visit: " << h[getHighest(h,v)] << endl;
  cout << "The average visit: " << getAvg(h,v) << endl;
  cout << endl;

  cout << "Do you want to close museum? Y or N: ";
  getYN("Invalid Answer. Enter Y or N: ");
  // cin >> answer;

  /*
  // cout << "Enter today's date: ";
      cin >> date;
      filename = date + ".txt";
      fout.open(filename.c_str());
      fout.close();
  */
}



