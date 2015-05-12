/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 11, 2015, 10:26 PM
 */

#include <iostream>
using namespace std;

#include "NumDays.h"
int main(int argc, char** argv) {
    NumDays aa(12);
    cout<<"First worker: "; 
    aa.pntDays();
    
    NumDays bb(20);
    cout<<"Second worker: "; 
    bb.pntDays();
    
    NumDays cc=aa+bb;
    cout<<"Third worker(1st+2nd): ";
    cc.pntDays();
    
    aa++;
    cout<<endl<<"After using postfix++ to 1st worker..."<<endl;
    aa.pntDays();
    
    bb--;
    cout<<endl<<"After using postfix-- to 2nd worker..."<<endl;
    bb.pntDays();
    
    ++aa;
    cout<<endl<<"After using prefix++ to 1st worker..."<<endl;
    aa.pntDays();
    
    --bb;
    cout<<endl<<"After using prefix-- to 2nd worker..."<<endl;
    bb.pntDays();
    
    return 0;
}

