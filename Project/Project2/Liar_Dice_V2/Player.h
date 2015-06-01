/* 
 * File:   Player.h
 * Author: Haolan Ye(Benjamin)
 * Created on May 31, 2015, 10:29 AM
 * Purpose: CSC-17A Project 2 Liar Dice V2 header file 
 */

#ifndef PLAYER_H
#define	PLAYER_H

class Player {
    private:
        int order;//the order of the game
    protected:
        char *dices;
        char *rolDice(int);//roll dice
        char *getDice() const {return dices;}
    public: 
        Player(int);//Constructor
        ~Player();//Destructor
        void chalng();
        void bid();
        int getOrdr() const {return order;}//get the order
        void pntDice();//print out the dice
        
};

#endif	/* PLAYER_H */

