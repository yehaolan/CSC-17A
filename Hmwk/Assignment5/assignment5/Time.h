/* 
 * File:   Time.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 21, 2015, 3:49 PM
 * Purpose: About time
 */

#ifndef TIME_H
#define	TIME_H

class Time {
    protected:
        int hour;
        int min;
        int sec;
    public:
        //Default constructor
        Time() {hour=min=sec=0;}
        //Constructor
        Time(int,int,int);
        //getter
        int getHour() const {return hour;}
        int getMin() const {return min;}
        int getSec() const {return sec;}
};

#endif	/* TIME_H */

