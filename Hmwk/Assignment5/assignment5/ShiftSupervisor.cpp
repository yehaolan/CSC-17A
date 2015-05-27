/* 
 * File:   ProductionWorker.h
 * Author: Haolan Ye(Benjamin)
 * Created on May 19, 2015, 3:07 PM
 * Purpose: Employee problem
 */


#include <iostream>
using namespace std;
#include "ShiftSupervisor.h"

void ShiftSupervisor::pntInfo() const {
    cout<<"Name: "<<getName()<<endl;
    cout<<"Number: #"<<getNum()<<endl;
    cout<<"Annual salary: $"<<getAnn()<<endl;
    cout<<"Bonus: $"<<getBon()<<endl;
    dt.pntDate();
    
}