#ifndef ARRAY_H
#define ARRAY_H
/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name:Christina Garcia
*****************************************************/

#include <iostream>
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
template <class T>
void fill(T ar[],int n)
{
  for(int i = 0; i <n; i++)
    {
      cout << "Enter an item:";
      cin >> ar[i];
    }
}

/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
template<class T>
void print(const T ar[],int n)
{
  for (int i = 0; i < n; i++)
  cout << ar[i]<< " ";
}

/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
template<class T>
int getHighest(T ar[], int n)
{
  int hi = 0;
  for (int i = 1; i < n; i++)
    if(ar[i] > ar[hi])
  hi = i;

  return hi;
}

/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
*******************************************/
template<class T>
int  getLowest(T ar[], int n)
{
  int low = 0;
  for (int i = 1; i < n; i++)
    if (ar[i]<ar[low])
      low = i;

  return low;
}

/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
template<class T>
double getAvg(const T ar[],int n)
{
  T total = 0;
  for (int i = 0; i < n; i++)
    total += ar[i];
  return (double)total/n;
}

/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4  
       
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar
*******************************************/
/*
template<class T>
int unique(T ar[], T uniqAr[] , int n)
{

  int count = 0;
  int index = 0;
  // bool found = false;

  for (int i = 0; i < n; i++)
    {
      // int value = ar[i];
      
      // bool found = false;
      
      for (int a = 0; a < count && !found; a++)
	{
	  int u = 0; 
	  if (uniqAr[a] == value)
	  {

	    // found = true;
	    count ++;
	  }
	}
      
      if(a ) 
	{
      uniqAr[count] = value;
      count ++;
	}
    }   
  return count;
}

     
//uniqAr in the caller will be filled with only unique numbers

*/
/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template<class T>
void sort(T array[], int N)
{
  int lrgIndx; //the index of the largest value                                                                                               
  T temp; //temporary variable that holds the largest value                                                                                  

  //last is the last index in unsorted portion                                                                                                 
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest                                                                                      
      //find the largest in unsorted portion ([0..last])                                                                                       
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                                                                           
            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion                                                                            
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}
//*******************************************************
//this code will bubble sort the array by moving from left to right
template<class T>
void bubbleSort(T ar[], int size)
    {
      int n = 0;// number of variables
      T temp = 0;//temporary variable
      bool done = false; // array has not been gone thorugh
      while(done == false)// while array has not been gone through
	{
	  done = true;
	  for(int i = 0; i < size; i++)
	    {
	      
	      if(ar[i] > ar[i +1])// comparison of i with the one after
		{
		  temp = ar[i];
		  ar[i]=ar[i+1];
		  ar[i+1]=temp;//swapping
		}
	    }
	}
    }
	  /*
	  n++;// n goes up
	  if (n == size)//when n is equal to array size we are done
	    {
	      done = true;
	    }
	}
    }
	  */
//*************************************************************************
template <class T1, class T2>
int find (T1 ar[], int s, const T2& k)
{
  int indexOfKey;
  bool found = false;
  
  for (int i = 0; i < s; i++)
    { 
   if (ar[i] == k)
      {
	found = true;
	indexOfKey = i;
	break;
      }
    }
  if (found  == false)
    {  
      indexOfKey = -1;
      // return -1;
    }
  return indexOfKey;
}

template <class T1 , class T2>
bool remove(T1 ar[],int s, T2& element_to_be_removed)
{
  int result = find(ar, s, element_to_be_removed);
  if(result > -1) // if the result is existant
    {
      for(int i = result; i < s - 1; i++)
	{
   
	  ar[i] = ar[i+1];
	}
      return true;
    }
  else 
    return false;
}

#endif
