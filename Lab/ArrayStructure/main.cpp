/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Modify by: Haolan Ye(Benjamin)
 * Created on March 25, 2015, 12:55 PM
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes
Array *flArray(int);
void prntAry(const Array *,int);
void destroy(Array *);
void copy(Array &,const Array *);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    Array *vec=flArray(100);
    cout<<"This is a bad copy"<<endl;
    Array vec1=*vec;
    //print the array
    cout<<"Show the original with the bad copy"<<endl;
    prntAry(vec,10);
    prntAry(&vec1,10);
    
    //show the data is the same but not this size
    vec1.data[0]=0;
    vec1.size=50;
    cout<<endl<<"Change the copy and it changes the original data"<<endl;
    cout<<"but not the size"<<endl;
    //print the array
    prntAry(vec,10);
    prntAry(&vec1,10);
    
    //Perform a proper copy
    cout<<endl<<"Make a proper copy"<<endl;
    Array vec2;
    
    copy(vec2,vec);
    vec2.data[0]=100;
    cout<<"Copy changed the original remains the same"<<endl;
    prntAry(vec,10);
    prntAry(&vec2,10);
    //destroy the array
    cout<<"Exit"<<endl;
    destroy(vec);
    return 0;
}

void  copy(Array &b,const Array *a) {
    //perform copy
    b.size=a->size;
    for(int i=0;i<a->size;i++){
        b.data[i]=a->data[i];
    }   
}

Array *flArray(int n) {
    //create pointer to structure
    Array *arr=new Array;
    //Allocate memory for the array
    arr->data=new int[n];
    arr->size=n;
    //fill the array with 2-digit integers
    for(int i=0;i<n;i++) {
        arr->data[i]=rand()%90+10;
    }
    //Exit stage right
    return arr;
    
}

void prntAry(const Array *arr,int pl) {
    cout<<endl;
    //print the array with 2-digit integers
    for(int i=0;i<arr->size;i++) {
        //cout<<arr->data[i]<<" ";
        //cout<<(*arr).data[i]<<" ";
        cout<<*((*arr).data+i)<<" ";
        
        if(i%pl==(pl-1)) cout<<endl;
    }
    //Exit stage right
}

void destroy(Array *arr) {
    delete []arr->data;
    delete arr;
}