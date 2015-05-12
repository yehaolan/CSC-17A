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
        int inches;
        void simp();
    public:
        FeetInches(int,int);
        void setFeet(int);
        void setInch(int);
        int getFeet() const {return feet;}
        int getInch() const {return inches;}
        bool operator <= (const FeetInches &right);
        bool operator >= (const FeetInches &right);
        bool operator == (const FeetInches &right);
        void pntLnth();
};

#endif	/* FEETINCHES_H */

