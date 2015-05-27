/* 
 * File:   ProductionWorker.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on May 19, 2015, 3:07 PM
 * Purpose: Employee problem
 */

#include <iostream>
using namespace std;
#include "ProductionWorker.h"

void ProductionWorker::pntInfo() const {
    cout<<"Name: "<<getName()<<endl;
    cout<<"Number: #"<<getNum()<<endl;
    cout<<"Shift: "<<getShft()<<endl;
    cout<<"Hourly Pay Rate: $"<<getPR()<<endl;
    dt.pntDate();
    
}


