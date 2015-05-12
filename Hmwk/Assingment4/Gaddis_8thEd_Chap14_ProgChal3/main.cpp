/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 11, 2015, 9:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#include "DayOfYr.h"
int main(int argc, char** argv) {
    cout<<"Initial a day to Dec 31st"<<endl;
    DayOfYr dd("December",31);
    DayOfYr::print();
    cout<<endl<<"After using postfix ++"<<endl;
    dd++;
    DayOfYr::print();
    cout<<endl<<"After using prefix ++"<<endl;
    ++dd;
    DayOfYr::print();
    cout<<endl<<"After using postfix --"<<endl;
    dd--;
    DayOfYr::print();
    cout<<endl<<"After using prefix --"<<endl;
    --dd;
    DayOfYr::print();
    return 0;
}

