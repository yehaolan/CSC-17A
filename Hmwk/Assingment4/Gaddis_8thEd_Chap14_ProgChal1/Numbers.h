/* 
 * File:   Numbers.h
 * Author: Haolan Ye (Benjamin)
 *
 * Created on May 10, 2015, 12:03 PM
 */

#ifndef NUMBERS_H
#define	NUMBERS_H

#include <string>
class Numbers {
    private:
        int number;
        static string res;//result
        static void trans(int);//translate
    public:
        Numbers();//Constructor1
        Numbers(int);//Constructor1
        static void print();//output result
        
};


#endif	/* NUMBERS_H */

