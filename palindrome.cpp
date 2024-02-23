#include <iostream> 
//#include "LL.h"
#include <string>
#include <fstream>
#include "LL_T.h"

using namespace std;

void createLL(LL<int>& l1, string s);
bool palindrome(LL<int>& p);
bool isLetter(char c);
char myToLower (char c);
//prototypes
int main()
{
  ifstream fin;//input file
  fin.open("palindrome.dat");//opening the palindrome.dat
  
  if(!fin)//if palindrome.dat doesn't open
    cout << "Invalid input file." << endl;
  else//if palindrome opens correctly
    {
      string s; //string name
      LL<int> l;//LL name
      while(!fin.eof())//while we have not gone through all of the file
	{
	  getline(fin, s);//getting the sentence
	  createLL(l, s); //creating the sentence in a LL
	  l.displayAll(); //disaplying the sentence
	  if(palindrome(l) == true) //if the palindrome is true
	    cout << "\"" <<  s <<  "\"" << " is a palindrome." << endl; 
	  else //if the palindrome is false
	    cout << "\"" << s << "\"" << " is NOT a palindrome." << endl;
	}
    }
  fin.close(); //closing the inut file
  /*
    cout << "Enter a sentence: ";
    getline(cin, s);
    
    createLL(l, s);
    l.displayAll(l, s);
    if(palindrome(l) == true)
    cout << "\"" << s << "\"" << "is a palindrome." << endl;
    else 
    cout << "\"" << s << "\"" << "is not a palindrome." << endl;
  */
  return 0;
}

void createLL(LL<int>& l1, string s)
{
  while(l1.isEmpty() == false)//if l1 is not empty
    {
      l1.deleteFront();//we delete front
    }
  for(int i = 0; i < s.length(); i++)//going through the sentence
    {
      if(isLetter(s[i]))//checking that the sentence has only characters
	{
	  char c = myToLower(s[i]);//changing all uppercase letters to lowercase
	  l1.addFront(c);//adding c to front
	}
    }
}

bool isLetter(char c)
{
  if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')//checking to see if it is a letter either lower case or uppercase
    return true; // retrurning true if it is a letter
  else 
    return false;//returning false if it is not a letter
}

char myToLower(char c)
{
  if(c >= 'A' && c <= 'Z')//checking to see if the character is uppercase
    c = c + ('a' -'A'); //if uppercase we arre subtracting to tuen into lowercase
  return c; //returning the charcter in lowercase
}

bool palindrome(LL<int>& p)
{
  char front;//first character
  char last;//last character
  while(p.isEmpty() == false)//while is not empty
    {
      front = p.deleteFront();
      last = front;
      if(p.isEmpty() == false)//checking if is is not empty
	last = p.deleteRear(); //setting last to p.deleteRear()
      if(front != last)// if front and last are not equal
	return false;
    }
  return true;
}

