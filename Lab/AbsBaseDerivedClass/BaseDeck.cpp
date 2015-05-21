/* 
 * File:   BaseDeck.h
 * Author: Haolan Ye
 * Created on May 13, 2015, 1:20 PM
 * Purpose: BaseDeck implementation
 */
#include <cstdlib>
#include <ctime>

#include "BaseDeck.h"
BaseDeck::BaseDeck() {
    place=0;
    size=52;
    cards=new int[size];
    for(int i=0;i<size;i++) {
        cards[i]=i;
    }
    //set seed
    srand(static_cast<unsigned int>(time(0)));
}
void BaseDeck::shuffle() {
    for(int mix=1;mix<=7;mix++) {
        for(int pos=0;pos<size;pos++) {
            int ran=rand()%size;
            int temp=cards[pos];
            cards[pos]=cards[ran];
            cards[ran]=temp;
        }
    }
}
int *BaseDeck::deal() {
    int delt=5;
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
