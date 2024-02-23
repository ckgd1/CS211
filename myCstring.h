#include <iostream>
#include <string>

using namespace std;


int myStrlen(const char* cstr)
{
  int i;
  for(i = 0; cstr[i] != '\0'; i++)
    ;
  return i;
}

void myStrcpy(char* dest, const char* source)
{
  int i;
  for(i = 0; source[i] != '\0'; i++)
    dest[i] = source[i];
  dest[i] = '\0';
}

void myStrcat(char* dest, const char* source)
{
  int d;
  int i;
  for(d = 0; dest[d] != '\0'; d++)//Move d to the end of dest ('\0')           
    ;
  //copy each character from source to dest                                   
  for(i = 0; source[i] != '\0'; i++)
    dest[d++] = source[i];
  dest[d] = '\0'; //place '\0' at the end of dest                             
}

int myStrcmp(const char* cstr1, const char* cstr2) 
{ 
  for(int i = 0; cstr1[i] != '\0' || cstr2[i] != '\0'; i++) 
    {                
      if(cstr1[i] != cstr2[i])          
        return cstr1[i] - cstr2[i]; 
    } 
  return 0;    
} 

int binarySearch(const char** ar, int size, char* key)
{
  int l = 0;
  int r = size - 1;
  int m;
  int s;
  while(l <= r)
    {
      m = (l + r)/2;
      s = myStrcmp(ar[m], key);
      if(s == 0)
	return m;
      else if(s < 0)
	l = m + 1;
      else if(s > 0)
	r = m -1;
    }
  return -1;
}
