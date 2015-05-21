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
        int shift;
        float hrPayRt;
    public:
        ProductionWorker():Employee(){shift=1;hrPayRt=0;}
        ProductionWorker(string n,string numb,Date d,int s,int p):Employee(n,numb,d){
            shift=s;hrPayRt=p;
        }
        ProductionWorker(string n,string numb,int y,int m,int d,int s,int p):Employee(n,numb,y,m,d){
            shift=s;hrPayRt=p;
        }
        void setShft(int s){shift=s;}
        void setPR(float p){hrPayRt=p;}
        int getShft() const {return shift;}
        float getPR() const {return hrPayRt;}
        void pntInfo()const;
};

#endif	/* PRODUCTIONWORKER_H */

