/* 
 * File:   CustomerData.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 22, 2015, 9:22 AM
 * Purpose: Derived class CustomerData
 */

#ifndef CUSTOMERDATA_H
#define	CUSTOMERDATA_H

#include <iostream>
using namespace std;

#include "PersonalData.h"

class CustomerData:public PersonalData{
    protected:
        int num;//customer number
        bool mailList;//mailing list
    public:
        //default constructor
        CustomerData():PersonalData(){
            num=rand()%9000+1000;
            mailList=false;
        }
        //constructor
        CustomerData(string ln,string fn,string a,string c,string s,string z,string p,bool m):PersonalData(ln,fn,a,c,s,z,p){
            num=rand()%9000+1000;
            mailList=m;
        }
        void setMail(bool m) {mailList=m;}//set mailing list
        int getNum() const {return num;}//get customer number
        bool getMail() const {return mailList;}//get mailing list
        void pntInfo() const;//print out information
};


#endif	/* CUSTOMERDATA_H */

