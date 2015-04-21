/* 
 * File:   Array.h
 * Author: Benjamin
 * Created on April 20, 2015, 1:04 PM
 * purpose: our first array class
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
#include "Array.h"

//fills array with random number
void Array::fillArray() {
    data =new int[size];
    for(int i=0;i<size;i++) {
        data[i]=rand()%90+10;
    }    
}

//constructor
Array::Array(int n) {
    if(n>1) {
        size=n;
        fillArray();
    } else {
        size=0;
        data=NULL;
    }
}

//destructor
Array::~Array() {
    if(size!=0) delete []data;
}
       
//Retrieve array information
int Array::getVal(int indx) {
    if(indx>=0&&indx<size) return data[indx];
    if(size==0) return -1;
    
}

//Mutate a value in the array
void Array::setVal(int indx,int val) {
    if(indx>=0&&indx<size) data[indx]=val;
    
}


void Array::reFill() {
    if(size>0) {
        delete []data;
        fillArray();
    }
}


void Array::sort() {
    for(int i=0;i<size-1;i++) {
        for(int j=i+1;j<size;j++) {
            if(data[i]>data[j]) {
                //swap with e
                data[i]=data[i]^data[j];
                data[j]=data[i]^data[j];
                data[i]=data[i]^data[j];
            }
        }
    }
}
    
void Array::prntArray() {
    for(int i=0;i<size;i++) {
        cout<<data[i]<<" ";
        if(i%10==9) cout<<endl;
    }
    cout<<endl;
}
    



