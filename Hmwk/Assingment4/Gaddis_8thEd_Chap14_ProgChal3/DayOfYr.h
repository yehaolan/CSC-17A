/* 
 * File:   DayOfYr.h
 * Author: admin
 *
 * Created on May 11, 2015, 9:37 PM
 */

#ifndef DAYOFYR_H
#define	DAYOFYR_H

class DayOfYr {
    private:
        int day;
        static string result;
        static void translt(int);//translate
    public: 
        DayOfYr(int);
        DayOfYr(string,int);
        static void print();//output result
        DayOfYr operator++();
        DayOfYr operator++(int);
        DayOfYr operator--();
        DayOfYr operator--(int);
};

#endif	/* DAYOFYR_H */

