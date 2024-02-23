/***************************************************************************
CS211
Template created by Kazumi Slott
Implement binary search that works on an ascending and descending ordered list.
Your program will abort if the function doesn't return the correct value. 

Your name:Christina Garcia
*****************************************************************************/
#include <iostream>
#include <assert.h>///including assert
using namespace std;

void reverseArray(int a[], int s);
int binarySearchAscend(const int a[], int s, int key);
int binarySearchDescend(const int a[], int s, int key);
//prototypes
int main()
{
  const int SIZE = 10;
  int ar[SIZE] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 90};

  //test binarySearchAscend()
  for(int i = 0; i < SIZE; i++)
    {
      assert(binarySearchAscend(ar, SIZE, ar[i]) == i);  //assert() terminates the program if the condition is false.
      
      assert(binarySearchAscend(ar, SIZE, 100) == 100); 
      
      
      //call reverseArray() to reverse the elements in ar 
      reverseArray(ar, SIZE);
      //test binarySearchDescend() - mimic how you tested binarySearchAscend()
      assert(binarySearchDescend(ar, SIZE, ar[i]) == i);
      
      assert(binarySearchDescend(ar, SIZE, 100) == 100);
    }
  return 0;
}



/****************************************************************************
This functioon reverse the contents of the array. Don't make a second array.
e.g. If ar is [5, 1, 3, 8, 2], this function changes the array to [2, 8, 3, 1, 5]
a is an integer array of any size.
s is the size of the array.
****************************************************************************/
void reverseArray(int a[], int s)
{
  int temp;//temporary
  for(int i = 0; i < s - 1; i++)//for loop to make the swapping
    {   
      temp = a[i]; // temp = to the first element of array
      a[i] = a[s - 1]; // swapping he last element into the first elementsnplace
      a[s - 1] = temp;//temp is set to last element
      //???????
    }
}


/****************************************************************************
This function returns the index where key is found or -1 if key is not found.
a is an integer array of any size sorted in ascending order.
s is the size of the array.
key is the number being searched for.
****************************************************************************/
int binarySearchAscend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index
  int r = s - 1; //right boundary starts at last index
  int m; //middle point between left and right.
  
  //When l and r cross over, search ends. --> key was not found. 
  while(l > r && r < l)
    {
      //calculate the middle point between l and r
      m = (l + r)/2;//??????
      
      if(a[m] == key) //key was found
	return a[m];
      else if(key < a[m]) // key is less than middle
	for(int i = m; i < m; i++)
	  {	  
	    a[i] == a[i+1];
	    r = m - 1; // r decreases
	    m = (l + r)/2; //calculating m again
	    //?????????;
	  }
      else if(a[m] < key) // if key is greater than middle
	for (int i = m; i > m; i--)
	  {
	    a[i] == a[i - 1];
	    
	    l = m + 1;// l increases
	    m = (l + r)/2; //calculating m again
	    //?????????;
	  }
      
      return -1; //key wasn't found
    }
}
  /****************************************************************************                                                             
This function returns the index where key is found or -1 if key is not found.                                                             
a is an integer array of any size sorted in descending order.                                                                                                     
s is the size of the array.                                                                                                               
key is the number being searched for.                                                                                                     
****************************************************************************/
int binarySearchDescend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index                                                                                      
  int r = s - 1; //right boundary starts at last index                                                                                     
  int m; //middle point between left and right.                                                                                           

  //When l and r cross over, search ends. --> key was not found.                                                                          
  while(l > r && r < l)
    {
      //calculate the middle point between l and r                                                                                        
      m = (l + r)/2; //??????
      if(a[m] == key) //key was found                                             
        return a[m];
      else if(key < a[m])
	for (int i = m; i < m; i--)
	  {
	    a[i] == a[i + 1];
	    r = m - 1;
	    m = (r + l)/2;
	  }
      else if(a[m] < key)
        for (int i = m; i > m; i++)
	  {	  
	    a[i] == a[i -1];
	    l = m + 1;
	    m = (r + l)/2;
	  }    
}

  return -1; //key wasn't found                                                                                                      
}
