#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream> 

using namespace std;

template<class T>
class myVector
{
private: 
  T* ar; //pointer to an array 
  int num; //the number of elements in the array pointed to by ar 
public: 
  myVector(); 
  ~myVector(); 
  void push_back(const T& e); 
  int size() const; 
  T& operator[](int index) const; 
  void erase(int index); 
  void insert(int index, const T& e); //the new element, e, will sit at index 
}; 
template <class T>  //above each function of this class, you need this. 
myVector<T>::myVector() //use T even if you are not using T in this function. 
{ 
  //initialize ar and num 
  ar = NULL; 
  num = 0; 
} 

template <class T> 
myVector<T>::~myVector() //destructor – we will talk more about it in the upcoming lectures 
{
  //The destructor is called automatically when an object of the class goes out of scope 
  //The destructor cannot be called by the programmer.  
  //Don’t forget to delete the array in heap! 
  if(ar != NULL)    
    delete [] ar; //if ar points to an array, delete it 
}

template <class T> 
void myVector<T>::push_back(const T& e)//e could be big. Use pass by reference with const 
{  
  //adds a new element at the end
  //ar[num] = e;
  T* a = new T[num+1];
  for(int i = 0; i < num; i++)
    {    
      *(a+i) = *(ar+i);
      //num++; 
    }
  a[num++] = e;
  if(ar != NULL)
    delete [] ar;
  ar = a;
  
} 

template <class T>
int myVector<T>::size() const
{
  return num;
}


template<class T>
T& myVector<T>::operator [] (int index) const
{
  return *(ar+index);
  // for(int i =0; i < index; i++)
  
  // return vecObj;
}
/*
template<class T>
void print(myVector<T>& v);

int main()
{
  myVector<int> v;
  
  //test your functions
  v.push_back(12);
  v.push_back(15);
  v.push_back(23);
  //v.size();
  cout << v.size() << endl;
  //v[2];
  cout << v[2] << endl;
  print(v);
}

template<class T>
void print(myVector<T>& v)
{ 
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
}
*/
template<class T>
void myVector<T>::erase(int index)
{
  if (index > (num - 1))
    cout << "Index is not valid." << endl;
  else 
    {
      T* arr = new T[num];
      for (int i = 0; i < index; i++)
	{
	  *(arr + i) = *(ar + i);
	}
      for (int i = index; i < (num +1); i++)
	{
	  *(arr + i) = *(ar+ (i + 1));
	}
      if (ar != NULL)
	{
	  delete [] ar;
	  ar = arr;
	  num --;
	}
    }
}
    /*
  int numb = *(ar + index);
  if(num == index)
    index--;   
    */


template<class T>
void myVector<T>::insert (int index, const T& e)
{
  if( index > num)
    cout << "Index is not valid." << endl;
  else 
    {
      T* arr = new T[num + 1];
      for (int i = 0; i < num; i++)
	{
	*(arr + i) = *(ar + i);
	}
      num++;
      T temp = *(arr + index);
      for(int i = index; i < num; i++)
	{
	  T tempp = *(arr + (i+1));
	  *(arr + (i + 1)) = temp;
	  temp = tempp;
	}
      *(ar + index) = e;
      if( ar != NULL)
	{
	delete [] ar;
      ar = arr;
	}
    }
}

  /*
  int numb = *(ar + index);
  if(numb == index)
    new_element ++;
  */
 

#endif