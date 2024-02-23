/****************************************************
Template written by Kazumi Slott
CS211
selection sort lab

This program has 4 different selection sort functions.
*****************************************************/
// This program will run correctly to display random number from 1 - 100 and we have to sort them in different ways.
#include <iostream>
#include <cstdlib>
#include "array.h" //headers
using namespace std;
//??????? include your array.h

void selectionSort1(int array[], int N);
void selectionSort2(int array[], int N);
void selectionSort3(int array[], int N);
void selectionSort4(int array[], int N); 
int test(int code);
//function calls
int main()
{
 
  cout << "------ testing selectionSort1: Ascending moving largest to end  ------" << endl;
  test(1); //testing Selectionsort1 to make sure it works

  cout << "\n------ testing selectionSort2: Descending moving smallest to end  ------" << endl;
  test(2); // testing selectionSort2 to make sure it is working fine

  cout << "\n------ testing selectionSort3: Ascending moving smallest to beginning  ------" << endl;
  test(3); //testing selectionSort3 to make sure it is working

  cout << "\n------ testing selectionSort4: Descending moving largest to beginning  ------" << endl;
  test(4); //testing selectionSort4 to make sure it is working

  return 0;
}

//This function fills the array with random numbers between 1 and 100
int fill(int ar[], int n)
{
  srand(time(0)); // getting random numbers each time

      for (int i = 0; i < n; i++)
	{
	  ar[i] = rand() % 100 + 1;
	} //function to get numbers between 1 - 100
}
// code = 1 for selectionSort1
//code = 2 for selectionSort2
//code = 3 for selectionSort3
//code = 4 for selectionSort4
											       
int test(int code)
{
  const int SIZE = 10;   //make a constant SIZE set to 10
 
  int ar[SIZE];  //declare an integer array using SIZE  

  fill(ar,SIZE); //fill the array by calling fill()

  print(ar,SIZE); //print the array by calling print() in array.h
  cout << endl;
  /*
  if ( code == 1)
    {
      selectionSort1;
    }
  
  else  (code == 2)
	    selectionSort2;
     
  else  (code == 3)
	     selectionSort3;
     
  else (code ==4)
	 selectionSort4;
   }
  */
 //create a switch statement here to call a different sort function depending on the code.
  //trying to use an if-else statement to run sort function depending on code

 print(ar,SIZE);// print(ar,SIZE); //print the array - hopefully the numbers are sorted correctly




}
//this function sorts the numbers in ascending order by moving the largest to the end: smallest to largest
void selectionSort1(int array[], int N) 
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted part
  for(int last = N-1; last >= 1; last--) 
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted part ([0..last])
      for(int i = 1; i <= last; i++) 
	{
	  if(array[i] > array[lrgIndx]) //The current item is larger 
	    lrgIndx = i;
	}

      //swap the largest with the last item in the unsorted part
      temp = array[lrgIndx]; 
      array[lrgIndx] = array[last]; 
      array[last] = temp;
    } 
}



//Change this function so it sorts the numbers in descending order by moving the smallest to the end: largest to smallest                                                                    
//You can change the variable names to suit their purposes. 
//The structure of this code shouldn't change.
void selectionSort2(int array[], int N)
{
  int smallIndx; //index of smallest value                                                                                                                                       
  int temp; //temporay variable that holds the samllest value
                                                                                                                                  
  //last is the last index in usorted part                                                                                                                                               
  for(int last = N + 1; last < 1; last++)
    {
      smallIndx = 0; //assuming the first item is the smallest
                                                                                                                                      
      //find the small in unsorted part                                                                                                                                     
      for(int i = 0; i < last; i++)
        {
          if(array[i] < array[smallIndx]) //the current item is smaller                                                                                                                          
            smallIndx = i;
        }

      //swap the smallest with the last item in the unsorted part                                                                                                                           
      temp = array[smallIndx];
      array[smallIndx] = array[last];
      array[last] = temp;
    }
}




//Change this function so it sorts the numbers in ascending order by moving the smallest to the beginning: smallest to largest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort3(int array[], int N)
{
  int smallIndex; //index of the smallest value                                                                                                                                                                        
  int temp; //temporary variable that holds the smallest value                                                                                                                                                                     
  //first is the first index in unsorted part                                                                                                                                                    
  for(int first = N-1; first < 1; first++)
    {
      int smallIndx = 0; //assuming the first item is the smallest                                                                                                                                                                   
      //find the small in unsorted part                                                                                                                                                                             
      for(int i = 1; i < first; i++)
        {
          if(array[i] < array[smallIndx]) //current item is smaller                                                                                                                                            
            smallIndx = i;
        }

      //swap the smallest with the first item in the unsorted part                                                                                                                                                                             
      temp = array[smallIndx];
      array[smallIndx] = array[first];
      array[first] = temp;
    }
}



//Change this function so it sorts the numbers in descending order by moving the largest to the beginning: largest to smallest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort4(int array[], int N)
{
  int lrgIndx; //index of largest value                                                                                                                                                                        
  int temp; //temporary variable that holds the largest value                                                                                                                                                                          
  //first is the first index in unsorted part                                                                                                                                                                                 
  for(int first = N-1; first < 1; first++)
    {
      lrgIndx = 0; //assuming the first item is the largest                                                                                                                                                                   
      //finding the largest in unsorted part                                                                                                                                                                             
      for(int i = 1; i <= first; i++)
        {
          if(array[i] > array[lrgIndx]) //current item is larger                                                                                                                                            
            lrgIndx = i;
        }

      //swap the largest with the first item in the unsorted part                                                                                                                                                                               
      temp = array[lrgIndx];
      array[lrgIndx] = array[first];
      array[first] = temp;
    }
}












