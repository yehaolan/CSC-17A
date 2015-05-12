/* 
 * File:   FeetInches.h
 * Author: Haolan Ye(Benjamin)
 *
 * Created on May 11, 2015, 11:12 PM
 */

#ifndef FEETINCHES_H
#define	FEETINCHES_H

class FeetInches {
    private:
        int feet;//number of feet
        int inches;//number of inch
        void simp();//simplify the length
    public:
        FeetInches(int,int);
        void setFeet(int);
        void setInch(int);
        int getFeet() const {return feet;}
        int getInch() const {return inches;}
        bool operator <= (const FeetInches &right);//overload <=
        bool operator >= (const FeetInches &right);//overload >=
        bool operator == (const FeetInches &right);//overload ==
        void pntLnth();//print the length
};

#endif	/* FEETINCHES_H */

