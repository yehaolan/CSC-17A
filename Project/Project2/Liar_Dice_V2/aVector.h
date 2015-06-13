/* 
 * File:   aVector.h
 * Author: Haolan Ye (Benjamin)
 * Created on June 5, 2015, 11:59 AM
 * Purpose: template class
 */

#ifndef AVECTOR_H
#define	AVECTOR_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class aVector {
    private:
       T *aptr;          // To point to the allocated array
       int actSize;      // Actual Size of the array
       int usdSize;      // Number of elements in the array
       void memError();  // Handles memory allocation errors
       void subError();  // Handles subscripts out of range
       
    public:
       // Default constructor
       aVector() { 
           actSize = 1;
           usdSize = 0;
           aptr=new T[actSize];
       }
       T *getPtr() const {return aptr;}
       // Constructor declaration
       aVector(int);
       
       // Copy constructor declaration
       aVector(const aVector &);

       // Destructor declaration
       ~aVector();

       // Accessor to return the array size
       int size() const  { return usdSize; }

       // Accessor to return a specific element
       T getElementAt(int position);

       // Overloaded [] operator declaration
       T &operator[](const int &);
       void push(T);
       void pop_back();
       //aVector<T>& operator =(aVector<T>&);
};


// Constructor with size argument
template <class T>
aVector<T>::aVector(int s) {
   usdSize = s;
   actSize = 2*s;
   // Allocate memory for the array.
   try {
      aptr = new T[actSize];
   } catch (bad_alloc) {
      memError();
   }
   
   // Initialize the array.
   for (int count=0;count<actSize;count++)
      *(aptr + count) = 0;
}


// Copy Constructor for aVector class. 
template <class T>
aVector<T>::aVector(const aVector &obj) {
   // Copy the array size.
   actSize=obj.actSize;
   
   // Allocate memory for the array.
   aptr = new T[actSize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of object's array.
   for(int count = 0; count < usdSize; count++)
      *(aptr + count) = *(obj.aptr + count);
   for(int i=usdSize;i<actSize;i++)
       *(aptr+i)=0;
}   

// Destructor
template <class T>
aVector<T>::~aVector() {
}

//push function
template <class T>
void aVector<T>::push(T o) {
    if(usdSize>=actSize) {
        actSize*=2;
        T *arr=new T[actSize];
        if(arr==0) memError();
        for(int i=0;i<usdSize;i++) {
            arr[i]=aptr[i];
        }
        for(int i=usdSize;i<actSize;i++) {
            arr[i]=0;
        }
        arr[usdSize]=o;
        usdSize++;
        delete []aptr;
        aptr=arr;
    } else {
       aptr[usdSize]=o;
       usdSize++;
    }
}

template <class T>
void aVector<T>::pop_back() {
    if(usdSize==0) {
        subError();
    } else {
        T* arr=new T[actSize];
        if(arr==0) memError();
        for(int i=0;i<usdSize-1;i++) {
            arr[i]=aptr[i];
        }
        for(int i=usdSize-1;i<actSize;i++) {
            arr[i]=0;
        }
        usdSize--;
        delete []aptr;
        aptr=arr;
    }
}

// memError function. Displays an error message and    
// terminates the program when memory allocation fails. 
template <class T>
void aVector<T>::memError() {
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

// subError function. Displays an error message and         
// terminates the program when a subscript is out of range. 
template <class T>
void aVector<T>::subError() {
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

// getElementAt function. The argument is a subscript.  
// This function returns the value stored at the subscript   
// in the array.                                  
template <class T>
T aVector<T>::getElementAt(int sub) {
   if (sub < 0 || sub >= usdSize)
      subError();
   return aptr[sub];
}


// Overloaded [] operator. The argument is an integer
// This function returns a reference to the element     
// in the array indexed by the integer.
template <class T>
T &aVector<T>::operator[](const int &sub) {
   if (sub < 0 || sub >= usdSize)
      subError();
   return aptr[sub];
}

/*
template <class T>
aVector<T>& aVector<T>::operator =(aVector<T>& right) {
    
    delete []aptr;
    aptr=new T[right.size()];
    for(int i=0;i<right.size();i++) {
        aptr[i]=right.getElementAt(i);
    }
    
    cout<<"aaaa"<<endl;
    delete []aptr;
    usdSize=right.size();
    aptr=new T[usdSize];
    for(int i=0;i<right.size();i++) {
        this->aptr[i]=right.getElementAt(i);
        
    }
    return *this;
}
*/

#endif