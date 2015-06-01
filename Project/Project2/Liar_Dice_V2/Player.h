/* 
 * File:   Player.h
 * Author: Haolan Ye(Benjamin)
 * Created on May 31, 2015, 10:29 AM
 * Purpose: CSC-17A Project 2 Liar Dice V2 header file 
 */

#ifndef PLAYER_H
#define	PLAYER_H

class Player {
    protected:
        char *dices;
        int order;//the order of the game
        char* rolDice();//roll dice
        char* getDice();
    public: 
        Player();//Constructor
        ~Player();//Destructor
        
        int getOrdr() const;//get the order
        void pntDice();//print out the dice
        
};

#endif	/* PLAYER_H */

