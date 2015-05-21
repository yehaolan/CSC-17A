/* 
 * File:   Date.cpp
 * Author: Haolan YE(Benjamin)
 * Created on April 30, 2015, 2:48 PM
 * Purpose: Gaddis_8thEd_Chap13_ProgChal 1
 */

#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

Date::Date() {
    this->yr=2000;
    this->mt=1;
    this->dy=1;
}

Date::Date(int yr, int mt, int dy) {
    this->yr=yr;
    this->mt=mt;
    this->dy=dy;
}

void Date::setDay(int dy) {
    bool invalid=false;
    int dyInMth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(dy<1||dy>dyInMth[mt])
            invalid=true;
    if(mt==2&&dy==29&&(yr%400==0||(yr%4==0&&yr%100!=0)))
            invalid=false;
    if(!invalid)
        this->dy=dy;
    else 
        cout<<"Invalid input for day"<<endl;
}

void Date::setMnth(int mt) {
    if(mt>0&&mt<=12)
        this->mt=mt;
    else 
        cout<<"Invalid input for month"<<endl;
}

void Date::setYear(int yr) {
    this->yr=yr;
}

void Date::pntDate() const{
    string month="";
    switch(mt) {
        case 1: month="January"; break;
        case 2: month="February"; break;
        case 3: month="March"; break;
        case 4: month="April"; break;
        case 5: month="May"; break;
        case 6: month="June"; break;
        case 7: month="July"; break;
        case 8: month="August"; break;
        case 9: month="September"; break;
        case 10: month="October"; break;
        case 11: month="November"; break;
        case 12: month="December"; break;
        default:;
    }
    //cout<<endl;
    cout<<"Hire Date: "<<mt<<"/"<<dy<<"/"<<yr<<endl;
    //cout<<month<<" "<<dy<<", "<<yr<<endl;
    //cout<<dy<<" "<<month<<" "<<yr<<endl;
}