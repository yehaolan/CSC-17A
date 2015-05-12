/* 
 * File:   info.cpp
 * Author: admin
 *
 * Created on May 3, 2015, 2:14 AM
 */

//System libraries
#include <iostream>
using namespace std;

//User libraries
#include "info.h"

//Constructor
info::info(string n,string addr,string num,int a) {
    //allocate memory
    name=n;
    address=addr;
    number=num;
    age=a;
}


//set the name
void info::setName(string name) {
    this->name=name;
}

//set the address
void info::setAddr(string address) {
    this->address=address;
}

//set the number
void info::setNum(string number) {
    this->number=number;
}
//set the age
void info::setAge(int age) {
    this->age=age;
}

//print out the information
void info::pntInfo() const {
    cout<<"Name: "<<info::getName()<<"   "<<"Phone number: "<<info::getNum()<<endl;
    cout<<"Address: "<<info::getAddr()<<"   "<<"Age: "<<info::getAge()<<endl<<endl;
}




