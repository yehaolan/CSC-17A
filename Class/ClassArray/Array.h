/* 
 * File:   Array.h
 * Author: Benjamin
 * Created on April 20, 2015, 1:04 PM
 * purpose: our first array class
 */

#ifndef ARRAY_H
#define	ARRAY_H

class Array {
    private:
        int *data;//array containing data
        int size;//size of array
        void fillArray();//fills array with random number
    public:
        Array(int);//constructor
        ~Array();//destructor
        //Accessors for the size
        int getSize() {return size;}
        int getVal(int);//Retrieve array information
        void setVal(int,int);//Mutate a value in the array
        void reFill();//call fill array again
        void sort();//sort 
        void prntArray();//print the array
    
};

#endif	/* ARRAY_H */

