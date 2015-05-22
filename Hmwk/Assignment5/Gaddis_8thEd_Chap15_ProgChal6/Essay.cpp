/* 
 * File:   Essay.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on May 22, 2015, 3:02 AM
 * Purpose: Essay class derived from GradedActivity class
 */
#include "Essay.h"

//Default constructor
Essay::Essay() {
    gramr=spell=corLn=contn=0;
    sum();
}

//constructor
Essay::Essay(int g, int s, int cor, int con) {
    gramr=g;
    spell=s;
    corLn=cor;
    contn=con;
    sum();
}

//sum all the score and sum them to score
void Essay::sum() {
    score=gramr+spell+corLn+contn;
}