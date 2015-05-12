/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 11, 2015, 11:12 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "FeetInches.h"
int main(int argc, char** argv) {
    FeetInches length1(1,4);
    cout<<"#1:";
    length1.pntLnth();
    FeetInches length2(2,4);
    cout<<"#2:";
    length2.pntLnth();
    if(length1<=length2) cout<<"length1<=length2"<<endl;
    cout<<endl<<"Change length 1 to 3 feet"<<endl;
    length1.setFeet(3);
    if(length1>=length2) cout<<"length1>=length2"<<endl;
    if(length1<=length2) cout<<endl<<"length1==length2"<<endl;
    else cout<<endl<<"They are not equal"<<endl;
    return 0;
}

