/* 
 * File:   ShiftSupervisor.h
 * Author: Haolan Ye(Benjamin)
 * Created on May 19, 2015, 3:07 PM
 * Purpose: Shift Supervisor
 */

#ifndef SHIFTSUPERVISOR_H
#define	SHIFTSUPERVISOR_H

#include "Date.h"
#include "Employee.h"

class ShiftSupervisor:public Employee{
    protected:
        int anuSala;
        int bonus;
    public:
        ShiftSupervisor():Employee() {anuSala=bonus=0;}
        ShiftSupervisor(string n,string numb,Date d,int ann,int b):Employee(n,numb,d){
            anuSala=ann;
            bonus=b;
        }
        ShiftSupervisor(string n,string numb,int y,int m,int d,int ann,int b):Employee(n,numb,y,m,d){
            anuSala=ann;
            bonus=b;
        }
        void setAnn(int ann){anuSala=ann;}
        void setBon(int bon){bonus=bon;}
        int getAnn()const {return anuSala;}
        int getBon()const {return bonus;}
        void pntInfo()const;
        
};

#endif	/* SHIFTSUPERVISOR_H */

