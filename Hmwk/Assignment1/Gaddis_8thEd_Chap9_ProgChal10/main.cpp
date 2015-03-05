/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 5, 2015, 12:58 PM
 * Purpose:Homework assignment1 (Gaddis_8thEd_Chap9_ProgChal10)
 */

//System libraries
#include <iostream>
using namespace std;

//User libraries

//Global Constants

//Function prototypes
int *Reverse(int *,int);

//Execution begins here
int main(int argc, char** argv) {
    int size;//size of array
    //prompt user for size of array
    do {
        cout<<"Input the size of the array"<<endl;
        cin>>size;
        if(size<1)
            cout<<"Invalid input"<<endl;
    }while(size<1);
    int *arr=new int[size];//a dynamic array
    int *brr=new int[size];//another dynamic array
    //prompt user for contents of array
    for(int i=0;i<size;i++) {
        cout<<"#"<<(i+1)<<": ";
        cin>>*(arr+i);
    }
    //output the inputted array
    cout<<"You'd input:"<<endl;
    for(int i=0;i<size;i++) {
        cout<<*(arr+i)<<" ";
    }
    //Reverse
    brr=Reverse(arr,size);
    //Output the reversed array
    cout<<endl<<"After Reverse..."<<endl;
    for(int i=0;i<size;i++) {
        cout<<*(brr+i)<<" ";
    }
    delete [] arr;
    delete [] brr;
    brr=0;
    arr=0;
    //Exit stage right
    return 0;
}

//Reverse
int *Reverse(int *a,int n) {
    int *b=new int[n];
    for(int i=0;i<n;i++) {
        *(b+i)=*(a+n-i-1);
    }
    return b;
}