#include <iostream>
#include <string>
#include "myCstring.h"

using namespace std;

const char* badAr[4] = {"funky", "idiot", "stinky", "stupid"};
char wd[10];
char longestWd[10] = "";
char shortestWd[10] = "abcdefghv";
char all[111] = "";
//variables
void showResult();
//prototype
int main()
{
  int word;//counter for each time we add a word
  do//beginning a do while loop to run while word is != 10
    {
      cout << "Enter a word: ";//aking user to input word
      cin >> wd;//getting word
      word ++;//incrementing word count
      if(binarySearch(badAr, 4, wd) == -1)//binary search for badwords 
	{
	  //len = myStrlen(wd); 
	  if(myStrlen(wd) > myStrlen(longestWd))//comparing word with longest word
	    myStrcpy(longestWd, wd);//copying longest word into longestWd variable
	  if(myStrlen(wd) < myStrlen(shortestWd))//comparing wd with shortestwd
	    myStrcpy(shortestWd, wd);//copying shortest word intoshortestWd variable 
	  myStrcat(all, wd);//adding all non badwords into all to display only goodwords
     	}
    }
  while (word != 10);//ending while loop  
  showResult();//showing result
  
  return 0;
}

void showResult()
{
  cout << "The longest word: ";
  cout << longestWd << endl;  //displaying longest word
  
  cout << "The shortest word: ";
  cout << shortestWd << endl;//displaying shortest word

  cout << "All words minus bad words: ";
  cout <<  all; //displaying all nonbadwords

/*
  myStrlen();
  if(myStrlen(wd) > myStrlen(longestWd))
    longestWd = wd;
  myStrcpy(longestWd, wd);
  */
}
