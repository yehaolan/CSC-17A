/* 
 * File:   ProductionWorker.h
 * Author: Haolan Ye(Benjamin)
 * Created on May 19, 2015, 3:07 PM
 * Purpose: Employee problem
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H

#include "Employee.h"
#include "Date.h"
class ProductionWorker:public Employee {
    protected:
        int shift;//shift for the worker
        float hrPayRt;//hourly pay rate
    public:
        ProductionWorker():Employee(){shift=1;hrPayRt=0;} //Default constructor
        //Constructor 1
        ProductionWorker(string n,string numb,Date d,int s,int p):Employee(n,numb,d){
            shift=s;hrPayRt=p;
        }
        //Constructor 1
        ProductionWorker(string n,string numb,int y,int m,int d,int s,int p):Employee(n,numb,y,m,d){
            shift=s;hrPayRt=p;
        }
        void setShft(int s){shift=s;}//set the shift
        void setPR(float p){hrPayRt=p;}//set the pay rate
        int getShft() const {return shift;}//get shift
        float getPR() const {return hrPayRt;}//get pay rate
        void pntInfo()const;//print out information
};

#endif	/* PRODUCTIONWORKER_H */

