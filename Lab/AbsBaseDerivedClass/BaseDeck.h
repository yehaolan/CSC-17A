/* 
 * File:   BaseDeck.h
 * Author: Haolan Ye
 * Created on May 13, 2015, 1:20 PM
 * Purpose: BaseDeck 
 */

#ifndef BASEDECK_H
#define	BASEDECK_H

#include "AbsDeck.h"
class BaseDeck:public AbsDeck {
    protected:
        int place;
        int *cards;
        int size;
    public:
        BaseDeck();
        ~BaseDeck() {delete []cards;}
        void shuffle();
        int *deal();
};

#endif	/* BASEDECK_H */

