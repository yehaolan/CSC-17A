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
    indx =new int[size];
    for(int i=0;i<size;i++) {
        data[i]=rand()%90+10;
        indx[i]=i;
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
    if(size!=0) {
        delete []indx;
        delete []data;
    }
}
       
//Retrieve array information
int Array::getVal(int idx) {
    if(idx>=0&&idx<size) return data[indx[idx]];
    if(size==0) return -1;
    
}

//Mutate a value in the array
void Array::setVal(int idx,int val) {
    if(idx>=0&&idx<size) data[indx[idx]]=val;
    
}


void Array::reFill() {
    if(size>0) {
        delete []indx;
        delete []data;
        fillArray();
    }
}


void Array::sort() {
    for(int i=0;i<size-1;i++) {
        for(int j=i+1;j<size;j++) {
            if(data[indx[i]]>data[indx[j]]) {
                //swap with e
                indx[i]=indx[i]^indx[j];
                indx[j]=indx[i]^indx[j];
                indx[i]=indx[i]^indx[j];
            }
        }
    }
}
    
void Array::prntArray() {
    for(int i=0;i<size;i++) {
        cout<<data[indx[i]]<<" ";
        if(i%10==9) cout<<endl;
    }
    cout<<endl;
}
    



