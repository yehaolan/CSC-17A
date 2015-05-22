/* 
 * File:   Employee.h
 * Author: Haolan Ye(Benjamin)
 * Created on May 19, 2015, 3:07 PM
 * Purpose: Employee problem
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include "Date.h"

class Employee {
    protected:
        string name;
        string num;
        Date dt;
    public:
        Employee();//Constructor 1
        Employee(string,string,Date);//Constructor 2
        Employee(string,string,int,int,int);//Constructor 3
        void setName(string);//set the name
        void setNum(string);//set the employee number
        void setDate(Date);//set the hire date
        string getName() const {return name;}//return name
        string getNum() const {return num;}//return number
        Date getDate() const {return dt;}//print the hire date
        void pntInfo() const;//print out the information
};

#endif	/* EMPLOYEE_H */

