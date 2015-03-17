/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 16, 2015, 01:10 PM
 * Purpose:DB Sort
 */

//System libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User libraries

//Global Constants

//Function prototypes
int *filAray(int);
void prntAry(int *,int,int);
void prntAry(int *,int *,int,int);
int *mrkSort(int *,int);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    int size=100;
    
    //declare dynamic array
    int *array=filAray(size);
    //print array
    cout<<"Original array before sorting"<<endl;
    prntAry(array,size,10);
    //sort the array
    int *indx=mrkSort(array,size);
    //print original array then sorted array
    cout<<"Original array after sorting"<<endl;
    prntAry(array,size,10);
    cout<<"Index array after sorting"<<endl;
    prntAry(array,indx,size,10);
    
    //deallocate memory
    delete [] array;
    array=0;
    //Exit stage right
    return 0;
}

int *filAray(int n) {
    //declare and allocate the array
    int *a=new int[n];
    //fill the array with random 2-digit number
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
    }
    return a;
}

void prntAry(int *a,int n,int pl) {
    //loop and print
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *a,int *indx,int n,int pl) {
    cout<<"The index array"<<endl;
    for(int i=0;i<n;i++) {
        cout<<indx[i]<<" ";
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl;
    
     //loop and print
    cout<<"The sorted array"<<endl;
    for(int i=0;i<n;i++) {
        cout<<a[indx[i]]<<" ";
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl;
}

int *mrkSort(int *a,int n) {
    //allocate array
    int *indx=new int[n];
    //initialize index
    for(int i=0;i<n;i++) {
        indx[i]=i;
    }
    //sort the array
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[indx[i]]>a[indx[j]]) {
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
            }
        }
    }
    return indx;
}