
/*******************
Weitten by Kazumi Slott
For CS211
10-16-2020

This program shows how clock() works and how to wait for a few seconds.
*******************/
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
  char ch;
  clock_t endWait;
  clock_t current;

  cout << CLOCKS_PER_SEC << endl;
  endWait = clock() + CLOCKS_PER_SEC * 3;
  cout << " endwait = " << endWait << endl;
  cout<< "Hit enter to go =======>";
  cin.get(ch);

  while(clock() <= endWait)
    cout << ".";

  cout << "\nEND at " << clock() << endl;

  return 0;
}
