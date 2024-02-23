//In this program we will be displaying all prime numbers that are in between 2 and 1000.
#include <iostream>//headers we will be using for this program
#include <iomanip>
using namespace std;
//#include "myMath.h"

int main()
{
unsigned i;
const int MAX = 1000; // max # which is 1000
int primenum[MAX];//array
// int num;
int count = 0;
 int columns;

bool  isPrime(int num)//isPrime function
{
for (int n = 2; n <= num/2; n++)
  {
if(num% n == 0)
  return false;
}
return true;
cout << num;
}
//for (i = 0; index < 1000; i++){

for ( i = 0 ; i < num; i++) { // function to display 10 numbers in a column 
    count ++;
    cout << setw(5) << num[i];
}
    if (count == 10){
      cout << endl;
      count = 0;
    }
}   
     // cout << left << setw(6) << primenum[i];
      // count ++;

/*
      return 0;
    }
}
//coukldn't run program beause there seems to be a problem with my "{"
