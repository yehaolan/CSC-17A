/* 
 * File:   AIVector.h
 * Author: admin
 *
 * Created on June 2, 2015, 10:19 PM
 */

#ifndef AIVECTOR_H
#define	AIVECTOR_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

#include "AI.h"

template <class T>
class AIVector {
    private:
        T *aptr;
        int size;
        void memError();  // Handles memory allocation errors
        void subError();  // Handles subscripts out of range
    public:
        // Default constructor
       AIVector() { aptr = 0; size = 0;}
       
       // Constructor declaration
       AIVector(int);
};

#endif	/* AIVECTOR_H */

