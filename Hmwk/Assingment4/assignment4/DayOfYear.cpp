/* 
 * File:   DayOfYear.cpp
 * Author: Haolan Ye(Benjamin)
 *
 * Created on May 10, 2015, 1:17 PM
 */

#include <iostream>
using namespace std;
#include "DayOfYear.h"

string DayOfYear::result="";

DayOfYear::DayOfYear(int d) {
    if(d>0&&d<=365) {
        day=d;
        tran(day);
    } else {
        cout<<"Invalid day"<<endl;
    }
}

void DayOfYear::print() {
    cout<<"This day would be "<<result<<endl;
}

//translate the day
void DayOfYear::tran(int day) {
    result="";
    string months[13]={" ","January","February","March","April","May","June",
    "July","August","September","October","November","December"};
    int date;
    if(day<=31) {
        result+=(months[1]+" ");
        date=day;
    } else if(day<=31+28) {
        result+=(months[2]+" ");
        date=day-31;
    }else if(day<=31*2+28) {
        result+=(months[3]+" ");
        date=day-(31+28);
    }else if(day<=31*2+28+30) {
        result+=(months[4]+" ");
        date=day-(31*2+28);
    }else if(day<=31*3+28+30) {
        result+=(months[5]+" ");
        date=day-(31*2+28+30);
    }else if(day<=31*3+28+30*2) {
        result+=(months[6]+" ");
        date=day-(31*3+28+30);
    }else if(day<=31*4+28+30*2) {
        result+=(months[7]+" ");
        date=day-(31*3+28+30*2);
    }else if(day<=31*5+28+30*2) {
        result+=(months[8]+" ");
        date=day-(31*4+28+30*2);
    }else if(day<=31*5+28+30*3) {
        result+=(months[9]+" ");
        date=day-(31*5+28+30*2);
    }else if(day<=31*6+28+30*3) {
        result+=(months[10]+" ");
        date=day-(31*5+28+30*3);
    }else if(day<=31*6+28+30*4) {
        result+=(months[11]+" ");
        date=day-(31*6+28+30*3);
    }else if(day<=31*7+28+30*4) {
        result+=(months[12]+" ");
        date=day-(31*6+28+30*4);
    }
    string dateSt="";
    if(date<10) dateSt+=static_cast<char>(48+date);
    else {
        dateSt+=static_cast<char>(48+date/10);
        dateSt+=static_cast<char>(48+date%10);
    }
    result+=dateSt;
}