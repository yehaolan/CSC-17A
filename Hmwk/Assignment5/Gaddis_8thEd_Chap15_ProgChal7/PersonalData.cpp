/* 
 * File:   PersonalData.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on May 22, 2015, 9:22 AM
 * Purpose: Base class PersonalData
 */

#include <iostream>
using namespace std;
#include "PersonalData.h"


//Constructor
PersonalData::PersonalData(string ln,string fn,string a,string c,string s,string z,string p) {
    lastNm=ln;
    firstNm=fn;
    address=a;
    city=c;
    state=s;
    phone=p;
    zip=z;
}

//print out information
void PersonalData::pntInfo() const {
    cout<<"Personal Information: "<<endl;
    cout<<"Last name: "<<lastNm<<endl;
    cout<<"First name: "<<firstNm<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"City: "<<city<<endl;
    cout<<"State: "<<state<<endl;
    cout<<"ZIP: "<<zip<<endl;
    cout<<"Phone: "<<phone<<endl;
}