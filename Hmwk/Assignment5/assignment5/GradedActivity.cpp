/* 
 * File:   GradedActivity.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 22, 2015, 3:02 AM
 * Purpose: based class for Essay class
 */

#include "GradedActivity.h"

char GradedActivity::getLetterGrade() const {
    char letter;
    switch(static_cast<int>(score)/10) {
        case 10:
        case 9:letter='A'; break;
        case 8:letter='B'; break;
        case 7:letter='C'; break;
        case 6:letter='D'; break;
        default: letter='F';
    }
    return letter;
}
