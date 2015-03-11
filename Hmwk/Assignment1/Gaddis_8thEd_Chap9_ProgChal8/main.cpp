/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 10, 2015, 09:50 AM
 * Purpose:Homework assignment1 (Gaddis_8thEd_Chap9_ProgChal8)
 */

//System libraries
#include <iostream>
using namespace std;

//User libraries

//Global Constants

//Function prototypes
void mode(int *,int,int*);//get the mode from the array

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
    int *modeArr=new int[size];//In this array, first element is number of mode
    //second is frequency of mode, the rest is the mode number
    
    //Prompt user to input the number for the array
    cout<<"Input the numbers for the array"<<endl;
    for(int i=0;i<size;i++) {
        cout<<"#"<<(i+1)<<": ";
        cin>>*(numArr+i);
    }
    //Get the mode
    mode(numArr,size,modeArr);
    
    delete [] numArr;
    delete [] modeArr;
    numArr=0;
    modeArr=0;
    //Exit stage right
    return 0;
}

void mode(int *a,int size,int *m) {
    //declare variables
    int num=*a;//initialize num to first number in array
    int count=0;//count the frequence
    *m=*a;
    *(m+1)=0;
    //mark sort with dynamic array
    for(int i=0;i<size-1;i++) {
        for(int j=i+1;j<size;j++) {
            if(*(a+i)>*(a+j)) {
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
    //Output the sorted array
    for(int i=0;i<size;i++) {
        cout<<*(a+i)<<" ";
    }
    cout<<endl<<endl;
    //compare the numbers in the array
    for(int i=0;i<=size;i++) {
        //when this number equal to previous number
        if(*(a+i)==num&&i!=size) {
            count++;
        } else {
            //if not equal to previous number
            if(count>*(m+1)) { //if count > the previous largest frequency
                *m=1; //the number of mode is 1
                *(m+1)=count;//Frequency is count
                *(m+2)=*(a+i-1);//Save this number to third element of dynamic array
            } else if(count==*(m+1)) { //if count == the previous largest frequency
                *m+=1;//The number of mode +1
                *(m+(*m)+1)=*(a+i-1);//Save this number
            }
            num=*(a+i);//Get the temp number
            count=1;//count assigned to 1
        }
    }
    //Output the results
    if(*(m+1)==1) { //when the frequency of mode is 1, means no mode
        cout<<"No mode in these numbers"<<endl;
    } else {
        cout<<"Number of mode in the array: "<<*m<<endl;
        cout<<"Mode: ";
        for(int i=1;i<=*m;i++) {
            cout<<*(m+i+1)<<" ";
        }
        cout<<endl;
        cout<<"Frequency of mode: "<<*(m+1)<<endl;
    }
}