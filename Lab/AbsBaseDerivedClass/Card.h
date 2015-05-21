/* 
 * File:   AbsCard.h
 * Author: admin
 * Created on May 13, 2015, 12:52 PM
 * Purpose: Card class
 */

#ifndef CARD_H
#define	CARD_H

class Card {
    private:
        int num;
    public:
        Card(int);
        char suit();
        char face();
        int value();
};

#endif	/* CARD_H */

