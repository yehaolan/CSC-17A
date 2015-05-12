/* 
 * File:   PayRoll.h
 * Author: Haolan YE (Benjamin)
 * Created on May 10, 2015, 1:39 AM
 */

#ifndef PAYROLL_H
#define	PAYROLL_H

class PayRoll {
    private:
        float payRate;//pay rate
        int wrkHour;//work hours
        float tPay;//total pay
        void setTPay();//set the total pay
    public:
        PayRoll();//Constructor 1
        PayRoll(float,int);//Constructor 2
        void setPyRt(float);//set the pay rate
        void setWkHr(int);//set the working hour
        void pntRsut() const;//output result
        float getPyRt() const {return payRate;}//return pay rate
        int getWkHr() const {return wrkHour;}//return working hour
        float getTPay() const {return tPay;}//return the total pay
};

#endif	/* PAYROLL_H */

