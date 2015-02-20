/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 20, 2015, 7:42 AM
 * Purpose: Homework assignment1 (Gaddis_7thEd_Chap6_ProgChal7)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
float celsius(int);//convert f to c

//Execution begins here
int main(int argc, char** argv) {
    //formatted Output the results with a table
    cout<<setprecision(1)<<fixed;
    cout<<"Fahrenheit"<<"   "<<"Celsius"<<endl;
    for(int f=0;f<=20;f++) {
        cout<<setw(5)<<f<<setw(13)<<celsius(f)<<endl;
    }
    //Exit stage right
    return 0;
}
//convert f to c
float celsius(int f) {
    return (f-32)*5.0f/9;
}

