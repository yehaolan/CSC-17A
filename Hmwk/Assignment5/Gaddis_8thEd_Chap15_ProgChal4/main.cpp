/* 
 * File:   main.cpp
 * Author: Haolan Ye
 * Created on May 21, 2015, 1:40 PM
 * Purpose: Time
 */

#include <string>
#include <iostream>
using namespace std;

#include "MilTime.h"
int main(int argc, char** argv) {
    int mh,ms;
    //get the military time to be changed
    cout<<"Time in military:"<<endl;
    do {
        cout<<"MilHour: ";
        cin>>mh;
        if(mh<0||mh>2359) cout<<"Invalid milHour"<<endl;
    }while(mh<0||mh>2359);
    do {
        cout<<"MilSecond: ";
        cin>>ms;
        if(ms<0||ms>59) cout<<"Invalid milSecond"<<endl;
    }while(ms<0||ms>59);
    
    //Test
    MilTime mt(mh,ms);
    //Output standard hours
    cout<<mt.getStandHr()<<endl;
    mt.setTime(1234,56);//set the hours
    //output again
    cout<<mt.getStandHr()<<endl;
    return 0;
}

