/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 17, 2015, 09:50 AM
 * Purpose:Homework assignment2 (Gaddis_8thEd_Chap9_ProgChal12)
 * Element shifter
 */

//System libraries
#include <iostream>
using namespace std;

//User libraries

//Global Constants

//Function prototypes
int *elmShft(int*,int);

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    int size;//size of array
    //prompt user for size of array
    do {
        cout<<"Input the size of array"<<endl;
        cin>>size;
        if(size<2)
            cout<<"Invalid input"<<endl;
    }while(size<2);
    //dynamic allocate array
    int *numArr=new int[size];//the array from user
    
    //Prompt user to input the number for the array
    cout<<"Input the numbers for the array"<<endl;
    for(int i=0;i<size;i++) {
        cout<<"#"<<(i+1)<<": ";
        cin>>*(numArr+i);
    }
    //output the input
    cout<<endl<<"The numbers you input:"<<endl;
    for(int i=0;i<size;i++) {
        cout<<numArr[i]<<" ";
    }
    cout<<endl<<endl;
    int *newArr=elmShft(numArr,size);
    //output results
    cout<<"After element shifter, the numbers are: "<<endl;
    for(int i=0;i<=size;i++) {
        cout<<newArr[i]<<" ";
    }
    cout<<endl;
    
    //clear memory
    delete [] numArr;
    delete [] newArr;
    numArr=0;
    newArr=0;
    //Exit stage right
    return 0;
}

//element shifter(shift one element)
int *elmShft(int *a,int size) {
    //allocate dynamic array
    int *n=new int[size+1];
    for(int i=0;i<=size;i++) {
        if(i==0) {
            n[i]=0;
        } else {
            n[i]=a[i-1];
        }    
    }
    return n;
}