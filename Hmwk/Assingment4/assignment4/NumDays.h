/* 
 * File:   NumDays.h
 * Author: Haolan Ye (Benjamin)
 *
 * Created on May 11, 2015, 10:27 PM
 */

#ifndef NUMDAYS_H
#define	NUMDAYS_H

class NumDays {
    private:
        int hours;
        float days;
        void calDays();//calculate days
    public:
        NumDays(int);
        void setHour(int);
        int getHour() const {return hours;}
        float getDay() const {return days;}
        NumDays operator+(const NumDays &);//overload +
        NumDays operator-(const NumDays &);//overload -
        NumDays operator++(int);//overload postfix ++
        NumDays operator--(int);//overload postfix --
        NumDays operator++();//overload prefix ++
        NumDays operator--();//overload prefix --
        void pntDays();//print the day
        
};

#endif	/* NUMDAYS_H */

