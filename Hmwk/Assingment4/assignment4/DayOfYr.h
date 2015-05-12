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
        static string result;//format: month/date
        static void translt(int);//translate
    public: 
        DayOfYr(int);
        DayOfYr(string,int);
        static void print();//output result
        DayOfYr operator++();//prefix ++
        DayOfYr operator++(int);//postfix ++
        DayOfYr operator--();//prefix --
        DayOfYr operator--(int);//postfix --
};

#endif	/* DAYOFYR_H */

