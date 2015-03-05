/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 5, 2015, 12:38 PM
 * Purpose:Homework assignment1 (Gaddis_8thEd_Chap9_ProgChal5)
 */

//System libraries
#include <iostream>
using namespace std;

//User libraries

//Global Constants

//Function prototypes
int doSomething(int *, int *);

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    int num1,num2;//two integer that user input
    int *pt1=&num1;//pointer point to num1
    int *pt2=&num2;//pointer point to num2
    //Prompt user for two numbers
    cout<<"Input two numbers"<<endl;
    cin>>num1>>num2;
    cout<<"After doing something..."<<endl;
    cout<<"The result is "<<doSomething(pt1,pt2)<<endl;
    //Exit stage right
    return 0;
}

//A function
int doSomething(int *x, int *y) {
    int temp = *x; 
    *x = *y * 10;
    *y = temp * 10; 
    return *x + *y;
}