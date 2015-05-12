/* 
 * File:   DayOfYear.h
 * Author: Haolan Ye(Benjamin)
 *
 * Created on May 10, 2015, 1:17 PM
 */

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H

class DayOfYear {
    private:
        int day;
        static string result;//Format: Month/Date
        static void tran(int);//translate
    public: 
        DayOfYear(int);
        static void print();//output result
};

#endif	/* DAYOFYEAR_H */

