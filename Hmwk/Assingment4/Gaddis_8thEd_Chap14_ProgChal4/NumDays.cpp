/* 
 * File:   NumDays.cpp
 * Author: Haolan Ye (Benjamin)
 *
 * Created on May 11, 2015, 10:27 PM
 */
#include <iostream>
using namespace std;
#include "NumDays.h"

NumDays::NumDays(int h) {
    if(h>=0) hours=h;
    else {
        cout<<"Invalid hour! Set it to 0"<<endl;
    }
    calDays();
}

void NumDays::calDays() {
    days=hours/8.0f;
}

void NumDays::setHour(int h) {
    if(h>=0) hours=h;
    else {
        cout<<"Invalid hour! Set it to 0"<<endl;
    }
    calDays();
}

NumDays NumDays::operator +(const NumDays &right) {
    NumDays temp(0);
    temp.hours=hours+right.hours;
    temp.calDays();
    return temp;
}

NumDays NumDays::operator -(const NumDays &right) {
    NumDays temp(0);
    temp.hours=hours-right.hours;
    temp.calDays();
    return temp;
}

NumDays NumDays::operator ++() {
    ++hours;
    calDays();
    return *this;
}

NumDays NumDays::operator --() {
    --hours;
    calDays();
    return *this;
}

NumDays NumDays::operator ++(int) {
    NumDays temp(hours);
    hours++;
    calDays();
    return temp;
}

NumDays NumDays::operator --(int) {
    NumDays temp(hours);
    hours--;
    calDays();
    return temp;
}

void NumDays::pntDays() {
    cout<<"the number of Working day: "<<getDay()<<endl;
}