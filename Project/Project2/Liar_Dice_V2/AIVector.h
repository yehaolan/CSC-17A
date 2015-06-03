/* 
 * File:   AIVector.h
 * Author: Haolan Ye (Benjamin)
 * Created on June 2, 2015, 10:19 PM
 * Purpose: CSC-17A Project 2 Liar Dice V2 template header file 
 */

#ifndef AIVECTOR_H
#define	AIVECTOR_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;


template <class T,class S>
class AIVector {
    private:
        T **aptr;//dice
        S *ptr;//AI
        int size;
        void memError();  // Handles memory allocation errors
        void subError();  // Handles subscripts out of range
    public:
        // Default constructor
        AIVector() { aptr=ptr = 0; size = 0;}
        
        // Constructor declaration
        AIVector(int);
        // Destructor declaration
        ~AIVector();
        // Accessor to return the array size
        int vecSize() const { return size; }
};

#endif	/* AIVECTOR_H */

