
/* 
 * File:   FeetInches.cpp
 * Author: Haolan Ye(Benjamin)
 *
 * Created on May 11, 2015, 11:12 PM
 */
#include <cstdlib>
#include <iostream>
using namespace std;
#include "FeetInches.h"

//Constructor
FeetInches::FeetInches(int f,int i) {
    if(f>=0)
        feet=f;
    if(i>0)
        inches=i;
    simp();
}

//simplify
void FeetInches::simp() {
    if(inches>=12) {
        feet+=(inches/12);
        inches%=12;
    } else if(inches<0) {
        feet-=((abs(inches) / 12) + 1);
        inches=12-(abs(inches) % 12);
    }
}

void FeetInches::setFeet(int f) {
    if(f>=0) feet=f;
    simp();
}

void FeetInches::setInch(int i) {
    if(i>=0) inches=i;
    simp();
}

//overload <=
bool FeetInches::operator <= (const FeetInches &right) {
    bool status;
    if (feet < right.feet) status = true;
    else if (feet==right.feet&&inches==right.inches) status = true;
    else status=false;
    return status; 
}

//overload >=
bool FeetInches::operator >= (const FeetInches &right) {
    bool status;
    if (feet > right.feet) status = true;
    else if (feet==right.feet&&inches==right.inches) status = true;
    else status=false;
    return status; 
}

//overload ==
bool FeetInches::operator == (const FeetInches &right) {
    bool status;
    if (feet==right.feet&&inches==right.inches) status = true;
    else status=false;
    return status; 
}

//print the length
void FeetInches::pntLnth() {
    cout<<"The length is "<<feet<<" feet "<<inches<<" inches"<<endl;
}