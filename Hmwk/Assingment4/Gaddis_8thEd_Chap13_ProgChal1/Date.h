/* 
 * File:   Date.h
 * Author: Haolan YE(Benjamin)
 * Created on April 30, 2015, 2:48 PM
 * Purpose: Gaddis_8thEd_Chap13_ProgChal 1
 */

#ifndef DATE_H
#define	DATE_H

class Date {
    
    private:
        int yr;//year
        int mt;//month
        int dy;//day
    public:
        Date(int yr,int mt,int dy);
        void setYear(int yr);
        void setMnth(int mt);
        void setDay(int dy);
        void pntDate();
};

#endif	/* DATE_H */

