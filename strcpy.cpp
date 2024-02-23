#include <iostream> 

using namespace std;

void myStrcpy(char* dest, const char* source);

int main()
{
  char str1[20] = "hello cs211";
  cout << str1 << endl;
  myStrcpy(str1, "Oh PHYS302");
  cout << str1 << endl;
  myStrcpy(str1, "what a great world");
  cout << str1 << endl;

  return 0;
}

void myStrcpy(char* dest, const char* source)
{
  int i;
  for(i = 0; source[i] != '\0'; i++)
    dest[i] = source[i];
  dest[i] = '\0';
}
