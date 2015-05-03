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
info::info(char *nm,char *adr,char *num,int a) {
    //allocate memory
    name=new char[strlen(nm)+1];
    address=new char[strlen(adr)+1];
    number=new char[strlen(num)+1];
    //copy
    strcpy(name,nm);
    strcpy(address,adr);
    strcpy(number,num);
    age=a;
}

//Destructor
info::~info() {
    delete []name;
    delete []address;
    delete []number;
}

//set the name
void info::setName(char *name) {
    delete []this->name;//deallocate memory
    this->name=new char[strlen(name)+1];//allocate memory
    strcpy(this->name,name);//copy to private variable
}

//set the address
void info::setAddr(char *address) {
    delete []this->address;
    this->address=new char[strlen(address)+1];
    strcpy(this->address,address);
}

//set the number
void info::setNum(char *number) {
    delete []this->number;
    this->number=new char[strlen(number)+1];
    strcpy(this->number,number);
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




