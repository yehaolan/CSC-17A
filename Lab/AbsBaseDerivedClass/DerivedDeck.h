

/* 
 * File:   DerivedDeck.h
 * Author: Haolan Ye
 * Created on May 13, 2015, 1:48 PM
 * Purpose: 
 */




#ifndef DERIVEDDECK_H
#define	DERIVEDDECK_H

#include "BaseDeck.h"
class DerivedDeck:public BaseDeck {
    public:
    DerivedDeck();
    int *more(int);
};

#endif	/* DERIVEDDECK_H */

