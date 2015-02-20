/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 19, 2015, 12:39 PM
 * Purpose:Homework assignment1 (Gaddis_7thEd_Chap5_ProgChal11)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User libraries

//Global Constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    short size;//size of the population
    short dPoInc;//daily population increase(in percentage)
    short day;//number of day will multiply
    //Prompt user for original size of pop
    do {
        cout<<"Input the original population"<<endl;
        cin>>size;
        if(size<2)
            cout<<"Invalid input"<<endl;
    }while(size<2);
    //Prompt user for population increase percent
    do {
        cout<<"Input the average daily population increase (as a percentage)"<<endl;
        cin>>dPoInc;
        if(dPoInc<0)
            cout<<"Invalid input"<<endl;
    }while(dPoInc<0);
    //Prompt user for number of day
    do {
        cout<<"Input the number of day that will multiply"<<endl;
        cin>>day;
        if(day<1)
            cout<<"Invalid input"<<endl;
    }while(day<1);
    //Print out the results
    cout<<"  Day  "<<"Population"<<endl;
    for(int i=1;i<=day;i++) {
        size=size*(100+dPoInc)/100;
        cout<<setw(4)<<i<<setw(10)<<size<<endl;
    }
    //Exit stage right
    return 0;
}

