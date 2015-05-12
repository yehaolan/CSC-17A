/* 
 * File:   DayOfYr.cpp
 * Author: Haolan Ye(Benjamin)
 *
 * Created on May 10, 2015, 1:17 PM
 */

#include <iostream>
using namespace std;
#include "DayOfYr.h"

string DayOfYr::result="";

DayOfYr::DayOfYr(int d) {
    if(d>0&&d<=365) {
        day=d;
        translt(day);
    } else {
        cout<<"Invalid day"<<endl;
    }
}

DayOfYr::DayOfYr(string m,int d) {
    string months[13]={" ","January","February","March","April","May","June",
    "July","August","September","October","November","December"};
    int daysPMt[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int mt=0;
    for(int i=1;i<13;i++) {
        if(m==months[i]) mt=i;
    }
    if(mt==0) {
        cout<<"Invalid month input and end the program..."<<endl;
        exit(EXIT_FAILURE);
    } else {
        if(d<1||d>daysPMt[mt]) {
            cout<<"Invalid day input and end the program..."<<endl;
            exit(EXIT_FAILURE);
        }
    }
    switch(mt) {
        case 1: day=d; break;
        case 2: day=31+d; break;
        case 3: day=31+28+d; break;
        case 4: day=31*2+28+d; break;
        case 5: day=31*2+30+28+d; break;
        case 6: day=31*3+30+28+d; break;
        case 7: day=31*3+30*2+28+d; break;
        case 8: day=31*4+30*2+28+d; break;
        case 9: day=31*5+30*2+28+d; break;
        case 10: day=31*5+30*3+28+d; break;
        case 11: day=31*6+30*3+28+d; break;
        case 12: day=31*6+30*4+28+d; break;
    }
    translt(day);
}

void DayOfYr::print() {
    cout<<"This day would be "<<result<<endl;
}

void DayOfYr::translt(int day) {
    string months[13]={" ","January","February","March","April","May","June",
    "July","August","September","October","November","December"};
    int date;
    result="";
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

//prefix ++
DayOfYr DayOfYr::operator++() {
    ++day;
    if(day>365) day%=365;
    translt(day);
    return *this;
}

//postfix ++
DayOfYr DayOfYr::operator++(int) {
    DayOfYr temp(day);
    day++;
    if(day>365) day%=365;
    translt(day);
    return temp;
}

//prefix --
DayOfYr DayOfYr::operator--() {
    --day;
    if(day<1) day+=365;
    translt(day);
    return *this;
}

//postfix --
DayOfYr DayOfYr::operator--(int) {
    DayOfYr temp(day);
    day--;
    if(day<1) day+=365;
    translt(day);
    return temp;
}