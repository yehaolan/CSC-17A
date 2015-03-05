/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 4, 2015, 10:47 PM
 * Purpose:Homework assignment1(Gaddis_8thEd_Chap9_ProgChal2)
 */

//System libraries
#include <iostream>
#include <iomanip>
using namespace std;

//user Libraries

//Global Constants

//Function prototypes
void mrkSrt(int *,int);
void prtArr(int *,int,int);
void average(int *,int);
//Execution begins here
int main(int argc, char** argv) {
    int size;//size of dynamic array
    int num;//number that user input
    int pl=5;//per line
    //Prompt user for size
    do {
        cout<<"How many numbers would you like to input?"<<endl;
        cin>>size;
        if(size<1)
            cout<<"Invalid input"<<endl;
    } while(size<1);
    //declare the dynamic array
    int *arr=new int[size];
    //prompt user for the contents of array
    for(int i=0;i<size;i++) {
        do {
            cout<<"#"<<(i+1)<<": ";
            cin>>num;
            if(num<0)
                cout<<"Invalid input"<<endl;
            else
                *(arr+i)=num;
        }while(num<0);
    }
    cout<<endl;
    //Output the array before sorting
    cout<<"You'd already inputted:"<<endl;
    prtArr(arr,size,pl);
    
    //sorting and output array
    mrkSrt(arr,size);
    cout<<endl<<"After sorting"<<endl;
    prtArr(arr,size,pl);
    average(arr,size);//get the average
    delete [] arr;
    arr=0;
    return 0;
}

//mark sort
void mrkSrt(int *a,int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(*(a+i)>*(a+j)) {
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
}

//print the array(5 numbers per line)
void prtArr(int *a,int n,int pl) {
    for(int i=0;i<n;i++) {
        cout<<setw(4)<<*(a+i);
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl;
}

//calculate the average of numbers 
void average(int *a,int n) {
    //declare ave
    float ave=0;
    //sum them
    for(int i=0;i<n;i++) {
        ave+=*(a+i);
    }
    //get the average
    ave=ave/n;
    cout<<"The average of these number is "<<ave<<endl;
}