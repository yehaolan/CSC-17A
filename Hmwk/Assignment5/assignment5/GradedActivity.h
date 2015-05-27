/* 
 * File:   GradedActivity.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 22, 2015, 3:02 AM
 * Purpose: based class for Essay class
 */

#ifndef GRADEDACTIVITY_H
#define	GRADEDACTIVITY_H

class GradedActivity {
    protected:
        float score;
    public: 
        GradedActivity(){score=0;} //default constructor
        GradedActivity(float s) {score=s;}//constructor
        void setScore(float s) {score=s;}
        float getScore() const {return score;}
        char getLetterGrade() const;
};

#endif	/* GRADEDACTIVITY_H */

