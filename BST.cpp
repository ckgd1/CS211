#include <iostream>
#include <cstdlib> //for rand()
//#include "LL.h"
#include <fstream>
//#include "/cs/slott/cs211/bst.dat"

using namespace std;

typedef int el_t;

class Node
{
  friend class BST;
private:
  el_t elem;
  Node* right;
  Node* left;
public:
  Node(el_t e){elem = e; right = NULL; left = NULL;} //implement the constructor inside the class definition
};

class BST
{
private:
  Node* root;
  void insertNode(Node*& p, el_t e);
  void inOrderPrint(Node* p);
  void preOrderPrint(Node* p);
  void postOrderPrint(Node* p);
  void destroy(Node* p);
  int getMaxLength(Node* p);
  bool searchRec(Node* p, el_t e);
  int getNumNodesBetween(Node* p, el_t min, el_t max);
  void printNodesBetween(Node* p, el_t min, el_t max);

public:
  BST();
  ~BST();
  void insertNode(el_t e);
  bool search(el_t e);
  void inOrderPrint();
  void preOrderPrint();
  void postOrderPrint();
  int getMaxLength();
  bool searchRec(el_t e);
  int getNumNodesBetween(el_t min, el_t max);
  void printNodesBetween(el_t min, el_t max);
};

BST::BST()
{
  root = NULL;
}

void BST::insertNode(el_t e)
{
  insertNode(root, e);
}

void BST::insertNode(Node*& p, el_t e)
{
  if(p == NULL)
    p = new Node(e);
  else if(e < p->elem)
    insertNode(p->left, e);
  else
    insertNode(p->right, e);
}
 
bool BST::search(el_t e)
{
  //Don't use recursion. Use a loop.
  //You want to know how many times it loops to find e.
  //declare a counter. 
  Node* p = root;
  el_t count = 0;

  while(p != NULL)
    {
      count ++;
      if(p -> elem == e)
	{
	cout << count << " nodes checked" << endl;
	cout << "found" << endl;
	return true; //display the counter
	}
      else if(p -> elem > e)
	p = p -> left;
      else if ( p -> elem < e)
	p = p -> right;
      
    }

  cout << "not found" << endl;
  return false;
}

void BST::inOrderPrint()
{
  inOrderPrint(root);
}

void BST::inOrderPrint(Node* p)
{
  if(p == NULL)
    return;
  inOrderPrint(p -> left);
  cout << p -> elem << " ";
  inOrderPrint(p -> right);
}

void BST:: preOrderPrint()
{
  preOrderPrint(root);
}

void BST::preOrderPrint(Node* p)
{
  if(p == NULL)
    return;
  //inOrderPrint(root);
  cout << p ->elem << " ";
  inOrderPrint(p -> left);
  // cout << p -> elem<< " ";
  inOrderPrint(p -> right);
}

void BST::postOrderPrint()
{
  postOrderPrint(root);
}

void BST::postOrderPrint(Node* p)
{
  if(p == NULL)
    return;
  inOrderPrint(p -> left);
  inOrderPrint(p -> right);  
  cout << p -> elem << " ";
  
}

BST::~BST()
{
  destroy(root);
}

void BST::destroy(Node* p)
{
  if(p == NULL)
    return;
  destroy(p -> left);
  destroy(p -> right);
  cout << p -> elem << "-->";
  delete p;
}

int BST:: getMaxLength()
{
  return getMaxLength(root);
}

int BST:: getMaxLength(Node* p)
{
  if (p == NULL)
    return 0;
  else
    {
      int num;
      int numtwo;
      num = getMaxLength(p -> left) + 1;
      numtwo = getMaxLength(p -> right) + 1;
      if(num >= numtwo)
	return num;
      if(num <= numtwo)
	return numtwo;
    }
}

bool BST:: searchRec(el_t e)
{
  return searchRec(root, e);
}

bool BST:: searchRec(Node* p, el_t e)
{
  if (p == NULL)
    return false;
  else
    {
      if(p -> elem == e)
	return true;
      else if (e < p -> elem)
	searchRec(p -> left, e);
      else if (e > p -> elem)
	searchRec(p -> right, e);
    }
}

int BST::getNumNodesBetween(el_t min, el_t max)
{
  return getNumNodesBetween(root, min, max);//public function
}

int BST:: getNumNodesBetween(Node* p, el_t min, el_t max)
{
  if(p == NULL) //if p is empty we return 0
    return 0;
  else if(p -> elem > min && p -> elem < max)//if element is in between min and max
    return getNumNodesBetween(p -> left, min, max) + getNumNodesBetween(p -> right, min, max) + 1;// return everything to the left and everything to the right plus 1
  else //if element isn't between min and max
    return getNumNodesBetween(p -> left, min, max) + getNumNodesBetween(p -> right, min, max);// we return everything to the left and everything to the riight
}

void BST:: printNodesBetween(el_t min, el_t max)
{

  return printNodesBetween(root, min, max);//public function
}

void BST::printNodesBetween(Node* p, el_t min, el_t max)
{
  //  Node* p = root;
  if(p == NULL)//if p is empty we return
    return;
  printNodesBetween(p -> left, min, max); //print nodes to the left    
  if(p -> elem > min && p -> elem < max) //if the element is between min and max
    cout << p -> elem << "--->";//print element 
  printNodesBetween(p -> right, min, max);//print elements to the right
}

int main()
{
  BST b;
  ifstream fin;//input file name
  fin.open("bst.dat");//opening input file
  if(!fin)//while input file is not true
    cout << "invalid input file" << endl;//error msg
  else
    {
      int min, max, nums;//setting variable names
      while(!fin.eof())//getting everything from inputfile
	{      
	  fin >> nums;
	  b.insertNode(nums);
	}
      cout << "Enter min: "; //<< endl;
      cin >> min;//getting min from user
      cout << "Enter max: ";
      cin >> max;///getting max from user
      
      
      cout << "The number of nodes between " << min << " and " << max << " is "<< b.getNumNodesBetween(min, max) << endl; //shwoing the amount of nodes between min and max
      cout << endl; 
      cout << "---- The number of nodes between " << min << " and " << max << " found in the tree are ----" << endl; 
      b.printNodesBetween(min, max);//printing nodes in between min and max 
      //while(p -> elem < min && p -> elem > max      
	    // b.deleteNode();  

    }
  fin.close();
  /*
      //    cout <<   
  //Insert 5, 8, 3, 9, 6, 1, 0, 4, 7, 20
  b.insertNode(5);
  b.insertNode(8);
  b.insertNode(3); 
  b.insertNode(9); 
  b.insertNode(6); 
  b.insertNode(1); 
 
  b.insertNode(0); 
  b.insertNode(4); 
  b.insertNode(7); 
  b.insertNode(20);


  cout << "---- Testing getMaxLength ----" << endl;
  cout << b.getMaxLength();
  cout << endl;

  cout << "---- Testing searchRec ----" << endl;
  cout<< b.searchRec(20);
  cout << endl;
  /*  
    cout << "---- Print all elements using the in-order traversal -----" << endl;
    b.inOrderPrint();
    cout << endl;
  cout << "---- Print all elements using the pre-order traversal -----" << endl;  
  b.preOrderPrint();
  cout << endl;
  cout << "---- Print all elements using the post-order traversal -----" << endl;  
  b.postOrderPrint();
  cout << endl;
  cout << "\n--- destructor gets called when b goes out of scope here ---" << endl;  
  return 0;  
 
  srand(time(0)); //you need to include cstdlib
  BST b;
  LL l; //??????????????????
  for(int i = 0; i < 1000; i++)
    {
      int r = rand() % 1000 + 1;
      l.addRear(r);
      b.insertNode(r);
    }
  
  int key;
  cout << "What number do you want to search for? ";
  cin >> key;


  cout << "BST *************************" << endl;
 
  //b.insertNode(key);
  b.search(key);//??????????????????????????
 
  cout << "LL************************" << endl;
  
  l.search(key);// ??????????????????????????
 
  */

  return 0;
}
