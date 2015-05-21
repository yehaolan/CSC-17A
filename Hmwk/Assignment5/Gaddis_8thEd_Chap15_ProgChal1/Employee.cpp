/* 
 * File:   Employee.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on May 19, 2015, 3:07 PM
 * Purpose: Employee problem
 */
#include <iostream>
using namespace std;
#include "Employee.h"
#include "Date.h"
Employee::Employee() {
    name="";
    num="";
    dt=Date(2000,1,1);
}

Employee::Employee(string n, string numb,Date d) {
    name=n;
    num=numb;
    dt=d;
}

Employee::Employee(string n, string numb,int y,int m,int d) {
    name=n;
    num=numb;
    dt=Date(y,m,d);
}

void Employee::setDate(Date d) {
    dt=d;
}

void Employee::setName(string n) {
    name=n;
}

void Employee::setNum(string numb) {
    num=numb;
}

void Employee::pntInfo() const {
    cout<<"Name: "<<getName()<<endl;
    cout<<"Number: #"<<getNum()<<endl;
    dt.pntDate();
}