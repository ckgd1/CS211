#include "LL.h"
#include "utility.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
typedef string el_t;
 
/***************************************************************
this function will build a linked list which is going to be sorted in alphabetical order and there should be no duplicates

 *************************************************************/
void buildLL(LL& l)
{
  while (l.isEmpty() == false)//we will begin by checking if our linked list is empty
    {
      l.deleteFront();//if not empty we will delete everything it has
    }
  ifstream fin; 
  fin.open("essay.txt");//openeing our input file
  el_t w; 
  fin >> w; //getting words from our input file
  string temp; 
  temp = w; //setting temp with w
  string wd; 
  //getline(fin, s);
  while(fin)//while input file is open
    {
      if(l.search(w) == true)//we are going to search thruough each word
	l.deleteNode(w); //if search is true we delete the duplicate
      //if(l.search(w) == false)
      else //if no duplicate	
	{
	  wd = ""; //empty string
	  for(int i = 0; i < temp.length(); i++)//going through each charcater in out temp
	    {
	      if(isLetter(temp[i]))//if the current charcater is a letter
		{
		  wd += myToLower(temp[i]); // we add and check to make them all lowercase
		  // l.addFront(w);
		}
	    }
	}
      w = wd;//w is set to wd	   
      
      l.addInOrderAscend(w); //add the words in alphabetical order to LL
      /*
	if(w < temp)
	l.addFront(w);
	else
	l.addRear(w);
      */
      fin>> w;      //get a new word
      temp = w; // set new word to temp
      //fin >> w;
    }
  fin.close(); //close input file
}
/*************************************************
this function will remove bad words from the link list
*********************************************/

void removeBadWords(LL& l)
{
  ifstream fin;
  string badw;
  fin.open("bad.txt");// opening the bad words input
  fin >> badw; //getting the bad words
  while(fin)//while input file is open
    {
      if(l.search(badw) == true) //if badwords are found
	l.deleteNode(badw); //delete badword node
    }
  fin.close();
}

/**********************************************************
this function is going to output the words i n the link list and separate them in alphabetical order
********************************************************/
/*
ostream& outputToFile(ostream& fout, string s)
{
  string wd;//word 1
  string wd2;// word 2
  ifstream fin; //input file
  string filename = "./dictionary/?.txt"; //name we will be giving whe  the fil opens
  filename[13] = toMyUpper(s[0]);//makeing uppercase letter
  while(wd[0] = wd2[0]) //if word 1 first letter is equal to word 2 first letter
    {  
      fout.open(filename.c_str());//open the txt file
  //buildLL();
    }
}
****/
int main()
{
  LL l1;
  string s;
  buildLL(l1);
  removeBadWords(l1);
  l1.displayAll();
  return 0;
}
