#include <iostream>
#include "stack.h"
using namespace std;

bool isOperand(char ch);
int charToInt(char ch);
bool isOperator(char ch);
int doMath(int opr1, char opt, int opr2);
//prototypes

int main()
{
  Stack s; //naming a stack
  string expr;
  cin >> expr;  
  bool Error = false; // if error is true program will stop
  for(int i = 0; i < expr.length() && !Error; i++)//for loop for program to continue until condition is not met
    {
      if (isOperand(expr[i])) // if operand is expression
	{
	  if(!s.isFull())// checking is stack is not full
	    {
	      int x = charToInt(expr[i]); // if stack is not full we push  
	      s.push(x);
	    }
	  else 
	    {
	      Error = true; // if error is true we brak out of loop and display  error message
	      cout << "Error: Expression is too long." << endl;
	    }
	}
      else if (isOperator(expr[i]))// if espression is operator
	{
	  if (!s.isEmpty()) // checking if stack is not empty
	    {
	      int n1 = s.pop(); // first pop
	      if(!s.isEmpty()) // checking is stack is not empty again
		{
		  int n2 = s.pop(); // second pop
		  int ans = doMath(n2, expr[i], n1); // doing the math expression with two pops
		  if(!s.isFull())// checking is stack is not full
		    s.push(ans); // pushing is stack is not full
		  else 
		    {
		      Error = true; // if stack is empty  we display error message
		      cout << "Error: Not enough operands." <<  endl;
		    }	
		  
		}
	      else // if stack is full we display error message
		{ 
		  Error = true;
		  cout << "Error: Too many operands." << endl;
		}
	      /*
	      else 
		{
		  Error = true;
		  cout << "Error";
		}
	      */
	    }
	  else 
	    {
	      Error = true; // if operand or operator are not valid we display error message
	      cout << "Error: Invalid item was found." << endl;
	    }
	}
    }
  /*
  cout << expr <<  endl;//cout the expression given
  if(expr != true)
    cout << isOperand(expr[i]) << isOperator(expr[i]) << endl;
  else 
    cout << "Error" << endl;
  */
  return 0;
  
}

// if char is between 0 and 9 true will be returned
bool isOperand(char ch)
{
  if(ch >= '0' && ch <= '9')
    return true;
  else 
    return false;
}

//we are converting a character into an integer
int charToInt(char ch)
{
  return  ch -'0';
}

// we are checking if the the charcter is +,-,*, or /, if it is one of these we will return true
bool isOperator(char ch)
{
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return true;
  else 
    return false;
}

// we are using a switch statement to do the math of the operators we were given
int doMath(int opr1, char opt, int opr2)
{
  switch (opt)
    {
    case '+': return opr1 + opr2;
    case '-': return opr1 - opr2;
    case '*': return opr1 * opr2;
    case '/': return opr1 / opr2; 
    }
}

