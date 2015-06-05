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
        T *aptr;    //To point to the allocated array
        int usdSize;//used size 
        void memError();  // Handles memory allocation errors
        void subError();  // Handles subscripts out of range
    public:
        // Default constructor
        aVector();
        aVector(int);
        //~aVector();
        T* getAptr() const {return aptr;}
        int size() const {return usdSize;}
        T getElementAt(int);
        void push(T);
        T &operator[](const int &);
        void operator =(const aVector<T>& right);
};

template <class T>
aVector<T>::aVector() {
    aptr=0;usdSize=0;
}

template <class T>
aVector<T>::aVector(int s) {
    usdSize=s;
   // Allocate memory for the array.
   try {
      aptr = new T[usdSize];
   } catch (bad_alloc) {
      memError();
   }
   // Initialize the array.
   for (int i=0;i<usdSize;i++)
      aptr[i]= 0;
}



template <class T>
void aVector<T>::push(T o) {
    //if-else
    T *arr=new T[usdSize+1];
    if(arr==0) memError();
    for(int i=0;i<usdSize;i++) {
        arr[i]=aptr[i];
    }
    arr[usdSize]=o;
    delete []aptr;
    
    usdSize++;
    aptr=arr;
}

template <class T>
T aVector<T>::getElementAt(int n) {
    if (n < 0 || n >= usdSize)
      subError();
   return aptr[n];
}

template <class T>
void aVector<T>::memError() {
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void aVector<T>::subError() {
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
T &aVector<T>::operator[](const int &sub) {
   if (sub < 0 || sub >= usdSize)
      subError();
   return aptr[sub];
}

template <class T>
void aVector<T>::operator =(const aVector<T>& right) {
    usdSize=right.size();
    aptr=right.aptr;
    for(int i=0;i<usdSize;i++) {
        aptr[i]=right.aptr[i];
    }
}

#endif	/* AVECTOR_H */

