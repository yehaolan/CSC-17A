/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 2, 2015, 3:36 PM
 */

#include <iostream>
using namespace std;

#include "info.h"

int main(int argc, char** argv) {
    info me("Benjamin Ye","12345 15th st","6335245424",17);
    info uncle("Kelvin","54326 16th st","124165943",26);
    info cousin("Nick","1044 14th st","752824452",20);
    me.pntInfo();
    me.setAge(18);
    cout<<"Change the age to 18..."<<endl;
    me.pntInfo();
    cousin.pntInfo();
    cout<<"Change the address..."<<endl;
    cousin.setAddr("1044 Spruce St");
    cousin.pntInfo();
    uncle.pntInfo();
    cout<<"Change the number..."<<endl;
    uncle.setNum("6262559824");
    uncle.pntInfo();
    return 0;
}

