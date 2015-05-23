/* 
 * File:   CustomerData.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on May 22, 2015, 9:22 AM
 * Purpose: Derived class CustomerData
 */

#include "CustomerData.h"

void CustomerData::pntInfo() const {
    cout<<endl<<"Personal Information: "<<endl;
    cout<<"Last name: "<<lastNm<<endl;
    cout<<"First name: "<<firstNm<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"City: "<<city<<endl;
    cout<<"State: "<<state<<endl;
    cout<<"ZIP: "<<zip<<endl;
    cout<<"Phone: "<<phone<<endl;
    cout<<"Customer Number: #"<<num<<endl;
    cout<<"Mailing List: "<<mailList<<endl;
}