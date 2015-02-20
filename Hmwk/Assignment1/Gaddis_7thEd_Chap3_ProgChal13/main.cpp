/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 19, 2015, 12:01 PM
 * Purpose: Homework assignment1 (Gaddis_7thEd_Chap3_ProgChal13)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const char CONVPT=100;//Convert to percent
const char ASESPT=60;//Assessment value in percent
const char PPTAX=64;//Property tax in cents

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float acVal;//actual value of a piece of property
    float asVal;//assessment value of property
    float tax;//property taxes
    //Prompt user for actual value
    do {
        cout<<"Input the actual value of a piece of property(in dollar)"<<endl;
        cin>>acVal;
        if(acVal<0)
            cout<<"Invalid input"<<endl;
    } while(acVal<0);
    //Calculate the results
    asVal=acVal*ASESPT/CONVPT;
    tax=asVal*PPTAX/CONVPT/CONVPT;
    //Print the results
    cout<<setprecision(2)<<fixed;
    cout<<"The assessment value is $"<<asVal<<endl;
    cout<<"The property tax   is   $"<<tax<<endl;
    //Exit stage right
    return 0;
}

