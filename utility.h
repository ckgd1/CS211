#include <iostream>
#include <cstdlib>
#include <string>

bool isLetter(char c)
{
  if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')//checking to see if it is a \letter either lower case or uppercase             
    return true; //true if it is a letter
  else 
    return false;//false if it is not a letter
}

char myToLower(char c)
{
  if(c >= 'A' && c <= 'Z')
    c = c - 32;
  return c;
}

char toMyUpper(char c)
{
  if (c >= 'a' && c <= 'z')
    c = c + 32;
  return c;
}
