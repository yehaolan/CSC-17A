/* 
 * File:   Array.h
 * Author: Benjamin
 * Created on April 20, 2015, 1:04 PM
 * purpose: our first array class
 */

//System libraries
#include <iostream>
using namespace std;

//user libraries
#include "Array.h"

//global constants

//function prototypes

//execution begins here
int main(int argc, char** argv) {
    //declare variables
    int n=100;
    Array a(n);
    //print the initial result
    cout<<"the original array: "<<endl;
    a.prntArray();
    //refill the array
    a.reFill();
    //print
    cout<<"the refilled array: "<<endl;
    a.prntArray();
    //change a value in the array
    a.setVal(n-1,100);
    //print
    a.prntArray();
    //sort
    a.sort();
    a.prntArray();
    
    
    //retrieve a property and  a data point
    cout<<"The size of the array: "<<a.getSize()<<endl;
    cout<<"The last value of the array: "<<a.getVal(n-1)<<endl;
    
    return 0;
}

