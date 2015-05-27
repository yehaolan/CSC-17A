/* 
 * File:   MilTime.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 21, 2015, 3:49 PM
 * Purpose: About time
 */

#ifndef MILTIME_H
#define	MILTIME_H

#include "Time.h"

class MilTime:public Time{
    protected:
        int milHour;//military hour
        int milSec;//military min
    public: 
        MilTime();//Default constructor
        MilTime(int,int);//constructor
        void setTime(int,int);//set the time
        int getHour() const {return milHour;}//get hours
        string getStandHr() const;//get standard hour
    private:
        void cvtToSt(int,int);//convert military time to standard
            
};

#endif	/* MILTIME_H */

