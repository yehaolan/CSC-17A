/* 
 * File:   Essay.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 22, 2015, 3:02 AM
 * Purpose: Essay class derived from GradedActivity class
 */

#ifndef ESSAY_H
#define	ESSAY_H

#include "GradedActivity.h"

class Essay:public GradedActivity{
    protected:
        int gramr;
        int spell;
        int corLn;
        int contn;
    public:
        Essay();//default constructor
        Essay(int,int,int,int);//constructor
        //setter
        void setGram(int g) {gramr=g;sum();}
        void setSpel(int s) {spell=s;sum();}
        void setCorL(int c) {corLn=c;sum();}
        void setCont(int c) {contn=c;sum();}
        //getter
        int getGram() const {return gramr;}
        int getSpel() const {return spell;}
        int getCorl() const {return corLn;}
        int getCont() const {return contn;}
    private:
        void sum();//sum all the score and sum them to score
};

#endif	/* ESSAY_H */

