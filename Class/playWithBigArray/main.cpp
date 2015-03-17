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
void filAray(int *,const int);
void prntAry(int *,int,int);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=100;
    int array[SIZE]={};
    //declare dynamic array
    filAray(array,SIZE);
    cout<<array[SIZE-1]<<endl;
    
    //Exit stage right
    return 0;
}

void filAray(int *a,const int n) {
    //fill the array with random 2-digit number
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
    }
}

void prntAry(int *a,int n,int pl) {
    //loop and print
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl;
}