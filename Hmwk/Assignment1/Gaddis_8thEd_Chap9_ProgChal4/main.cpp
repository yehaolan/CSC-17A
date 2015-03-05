/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 5, 2015, 08:11 AM
 * Purpose:Homework assignment1(Gaddis_8thEd_Chap9_ProgChal4)
 */

//System libraries
#include <iostream>
#include <iomanip>
using namespace std;

//user Libraries

//Global Constants

//Function prototypes
void mrkSrt(int *,string *,int);
void prtArr(int *,string *,int,int);
void average(int *,int);

//Execution begins here
int main(int argc, char** argv) {
    int size;//size of dynamic array
    int num;//number that user input
    int pl=5;//per line
    string name;
    //Prompt user for size
    do {
        cout<<"How many numbers would you like to input?"<<endl;
        cin>>size;
        if(size<1)
            cout<<"Invalid input"<<endl;
    } while(size<1);
    //declare the dynamic array
    int *arr=new int[size];
    string *str=new string[size];
    //prompt user for the contents of array
    cout<<"First input score,then input last name"<<endl;
    for(int i=0;i<size;i++) {
        do {
            cout<<"#"<<(i+1)<<": ";
            cin>>num>>name;
            if(num<0) {
                cout<<"Invalid input"<<endl;
            } else {
                *(arr+i)=num;
                *(str+i)=name;
            }
        }while(num<0);
    }
    cout<<endl;
    //Output the array before sorting
    cout<<"You'd already inputted:"<<endl;
    prtArr(arr,str,size,pl);
    
    //sorting and output array
    mrkSrt(arr,str,size);
    cout<<endl<<"After sorting"<<endl;
    prtArr(arr,str,size,pl);
    average(arr,size);//get the average
    delete [] arr;
    delete [] str;
    str=0;
    arr=0;
    return 0;
}

//mark sort both score and name
void mrkSrt(int *a,string *s,int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(*(a+i)>*(a+j)) {
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
                string tem=*(s+i);
                *(s+i)=*(s+j);
                *(s+j)=tem;
            }
        }
    }
}

//print the array(5 numbers per line)
void prtArr(int *a,string *s,int n,int pl) {
    for(int i=0;i<n;i++) {
        cout<<setw(4)<<*(a+i)<<" "<<*(s+i)<<endl;
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
    cout<<setprecision(2)<<fixed;
    cout<<"The average of these scores is "<<ave<<endl;
}