#include <iostream>
//#include <stdexcept>
#include <string>

using namespace std;

int cstr_i(char* cstr)
{
  string m = "not an integer";//error msg
  int s = 0;//setting the first to 0
  //int i;
  for(int i = 0; cstr[i] != '\0'; i++)//while the loop doesn't reach \0
    {
      if (cstr[i] <= '9' && cstr[i] >= '0')//if the cstring isn't between 0 and 9
	s = s * 10 + ((cstr[i]) - '0');//convert into int
      else 
	throw m;//throw error msg
    }
  return s;//returning our number
}



int main()
{
  char choice[10];//cstring with 9 characters and the last being '\0'
  bool bad;
  int num;

  do 
    {
      bad = false;//initiating bool to false
      cout << "Enter an integer number: ";//getting user input
      cin >> choice;//taking in the users input

      try 
	{
	  num = cstr_i(choice); //using our function to convert choice into int
	}
      catch(string m) 
	{
	  cout << m << endl;//couting our error message
	  bad = true;//setting bad to true 
	}
    } while (bad == true);//while bad is equal to true we keep asking user for input
  cout << "After catch " << endl;
  cout << "num = " << num << endl;//showing our int 
 
  return 0;
}
