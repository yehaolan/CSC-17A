/* 
 * File:   AIVector.h
 * Author: Haolan Ye (Benjamin)
 * Created on June 2, 2015, 10:19 PM
 * Purpose: CSC-17A Project 2 Liar Dice V2 template cpp file 
 */

#include "AIVector.h"

template <class T,class S>
AIVector<T,S>::AIVector(int n) {
    size=n;
    // Allocate memory for the array.
    try {
      ptr = new S[n];
    } catch (bad_alloc) {
      memError();
    }
}

template <class T,class S>
AIVector<T,S>::~AIVector() {
    for(int i=0;i<size;i++){
        
    }
}

template <class T,class S>
void AIVector<T,S>::memError() {
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T,class S>
void AIVector<T,S>::subError() {
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}
