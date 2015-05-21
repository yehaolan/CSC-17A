/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 13, 2015, 12:48 PM
 * Purpose: Illustrate chapter 15
 */

//System libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//user libraries
#include "Card.h"
#include "DerivedDeck.h"

int main(int argc, char** argv) {
    DerivedDeck deck;
    deck.shuffle();
    int *hand=deck.deal();
    //display some card
    for(int card=0;card<5;card++) {
        Card a(hand[card]);
        cout<<a.face()<<" "<<a.suit()<<" "<<a.value()<<endl;
    }
    /*
    for(int i=0;i<52;i++) {
        Card card(i);
        cout<<card.face()<<" "<<card.suit()<<" "<<card.value()<<endl;
    }
    */
    
    //delete hand
    delete []hand;
    return 0;
}

