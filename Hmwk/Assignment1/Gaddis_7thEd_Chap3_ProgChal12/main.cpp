/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 18, 2015, 1:20 PM
 * Purpose:Homework assignment1 (Gaddis_7thEd_Chap3_ProgChal12)
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const char CONVPT=100;//Convert to Percent
const char SALETAX=4;//State Sales Tax(Percent)
const char CONTTAX=2;//County Sales Tax(Percent)

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {
    //declare variables
    string month;//Month
    float tc;//Total Collected
    float sales;//Sales
    float cst;//County Sales Tax
    float sst;//State Sales Tax
    float tst;//Total Sales Tax
    //Prompt user for month
    do {
        cout<<"Month: ";
        cin>>month;
        if(month!="January"&&month!="February"&&month!="March"&&month!="April"&&
           month!="May"&&month!="June"&&month!="July"&&month!="August"&&
           month!="September"&&month!="October"&&month!="November"&&month!="December")
            cout<<"Invalid input"<<endl;
    } while(month!="January"&&month!="February"&&month!="March"&&month!="April"&&
           month!="May"&&month!="June"&&month!="July"&&month!="August"&&
           month!="September"&&month!="October"&&month!="November"&&month!="December");        
    cout<<"--------------------------"<<endl;
    //Prompt user for Total Collected
    do {
        cout<<"Total Collected:     $";
        cin>>tc;
        if(tc<0)
            cout<<"Invalid input"<<endl;
    } while(tc<0);
    //Calculate the results
    sales=tc/(static_cast<float>(100+SALETAX+CONTTAX)/CONVPT);
    cst=static_cast<float>(sales)*CONTTAX/CONVPT;
    sst=static_cast<float>(sales)*SALETAX/CONVPT;
    tst=cst+sst;
    cout<<setprecision(2)<<fixed;
    cout<<"Sales:               $"<<sales<<endl;
    cout<<"County Sales Tax:    $"<<cst<<endl;
    cout<<"State Sales Tax:     $"<<sst<<endl;
    cout<<"Total Sales Tax:     $"<<tst<<endl;
    //Exit stage right
    return 0;
}

