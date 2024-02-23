#include <iostream>

using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include "stack.h"

int getBase();
void convertRec(int n, int b);
void convertStack(int n, int b);
char convertToChar(int n);
//prototypes
int main()
{
  int dec;
  int base;
  cout << "Enter a number in base 10: ";//asking user for a decimal #
  //getting decimal and checking if it is in between the limits
  dec = getData(1,999999, "Invalid number. Enter a number between 1 and 999999: ");
  //asking input for a base(2,8,16)
  base =  getBase();

  cout << "------ Using recursion ------" << endl;
  //using recursion to turn user's decimal into base they input
  convertRec(dec,base);
  cout << endl;

  cout << "------ Using a Stack ------" << endl;
  //using a stack to turn user's decimal into base they input
  convertStack(dec, base);
  cout << endl;

  return 0;
}

int getBase()
{
  int ans;
  cout << "Enter a base to convert the base 10 number to: ";
  cin >> ans; //taking in the users input
   while(ans != 2 && ans != 8 && ans != 16)
     {   
       cin.ignore();
       cout << "Invalid. Enter 2, 8, or 16: ";//error message if user doesn't input 2,8, 16
       cin >> ans;//asking the user again for a base
     }
   return ans;//returning the answer given by user
}

void convertRec(int n, int b)
{
  if(n == 0)//if decimal input by user is 0 we return 0
    {
      return; 
    }
  switch(b)//starting a switch statement depeding on the users decision of base
    {
    case '2': // if user chooses 2 as a base
      convertRec(n/2, b);//divide n by two
      cout << n % 2; // returning remainder
    case '8': // if user chooses 8 as a base
      convertRec(n/8, b); // dividing n by 8
      cout << n % 8; // returning reaminder
    case (16): // if user chooses 16 as a base
      convertRec(n/16, b); //dividing n by 16
      cout << n % 16; //returning remainder
    }
}
      // convertRec(n.substr(1,n.length() - 1));
      // cout << n[0];

void convertStack(int n, int b)
{
  Stack s; // creating a stack called s
  while (n > 0)//while decimal is greater than 0
    {
      switch(b)//using a switch statement depending if user input 2,8, or 16
	{
	case '2'://if user input 2
	  s.push(n % 2); // pushing the remainder 
	  n/=2;//dividing the decimal input by the user until it cannot be divided by 2
	case '8'://if user input 8
	  s.push(n % 8); // pushing the remainder 
	  n /=8; // divinding the decimal input by the user until it cannot be divided by 8
	case (16)://if user input 16
	  s.push(n % 16);//pushing the remainder
	  n /=16;//dividing the decimal input by the user until it cannot be divided by 16
	}
    }
  if(b == 16) // if the base is 16 we have to convert from 10-15 to characters
    {
      while(s.isEmpty() == true)//checking if stack is empty
	{
	  cout << convertToChar(s.pop());//if stack is not empty we pop the top and convert to char
	}
    }
  else
	{
	  while (s.isEmpty() == true)//checking if stack is empty
	    {
	      cout << s.pop();//if stack is not empty we pop the top element
	    }
	}
}


char convertToChar(int n)
{
  char c;//our character that will be returned
  if (n > 10)//if n is less than 10 we do not convert to character
    return c = 48 + n; // we are adding 0 to n to keep it in our original #
 else    
   return c = 55 + n;//if n is greater than 10 we convert to char
}