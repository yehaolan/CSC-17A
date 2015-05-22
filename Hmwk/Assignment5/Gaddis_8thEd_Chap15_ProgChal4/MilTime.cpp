/* 
 * File:   MilTime.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on May 21, 2015, 3:49 PM
 * Purpose: About time
 */

#include <iostream>
using namespace std;
#include "MilTime.h"

//Default constructor
MilTime::MilTime() {
    milSec=milHour=0;
    hour=min=sec=0;
}

//constructor
MilTime::MilTime(int mh, int ms) {
    milHour=mh;
    milSec=ms;
    cvtToSt(mh,ms);
}

//set the time
void MilTime::setTime(int mh,int ms) {
    milHour=mh;
    milSec=ms;
    cvtToSt(mh,ms);
}

//get standard hours
string MilTime::getStandHr() const {
    return to_string(milHour/100)+":"+to_string(milHour%100)+":"+to_string(milSec);
}

//convert military time to standard
void MilTime::cvtToSt(int mh,int ms) {
    hour=mh/100;
    min=mh%100;
    sec=ms;
}