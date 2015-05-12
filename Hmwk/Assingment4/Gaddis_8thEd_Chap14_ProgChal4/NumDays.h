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
        void calDays();
    public:
        NumDays(int);
        void setHour(int);
        int getHour() const {return hours;}
        float getDay() const {return days;}
        NumDays operator+(const NumDays &);
        NumDays operator-(const NumDays &);
        NumDays operator++(int);
        NumDays operator--(int);
        NumDays operator++();
        NumDays operator--();
        void pntDays();
        
};

#endif	/* NUMDAYS_H */

