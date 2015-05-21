


/* 
 * File:   DerivedDeck.h
 * Author: Haolan Ye
 * Created on May 13, 2015, 1:48 PM
 * Purpose: 
 */

#include "DerivedDeck.h"

DerivedDeck::DerivedDeck():BaseDeck(){;}

int *DerivedDeck::more(int delt) {
    int *hand=new int[delt];
    for(int card=0;card<delt;card++) {
        hand[card]=cards[place++];
    }
    if(place>0.8f*size) {
        shuffle();
        place=0;
    }
    return hand;
}
