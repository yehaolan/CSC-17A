/* 
 * File:   Player.h
 * Author: Haolan Ye(Benjamin)
 * Created on May 31, 2015, 10:29 AM
 * Purpose: CSC-17A Project 2 Liar Dice V2 player header file 
 */

#ifndef PLAYER_H
#define	PLAYER_H

class Player {
    protected:
        int order; //0 is player, 1 is AI#1, 2 is AI#2
        char *dices; //dices of player
        char *rolDice(int);//roll dice
        static int open;
        static int numPlyr;//number of player
        static int numCd;//number of dice called
        static char faceCd;//face Called
        static int round;//round #
        static bool wild;//wild
        static void renew(char,int,bool);//After bidding, renew face and number of dices
    public: 
        Player();//Constructor
        //~Player();//Destructor
        void init();//initialize the variables of the game
        void chalng();//player challenge
        void bid();//player bid
        static int  setNumP(int n) {numPlyr= n;}
        int  getOrdr() const {return order;}//get the order
        int  getOpen() const {return open;}//get the player who challenge
        char* getDice() const {return dices;}//get all dices
        int  getNumP() const {return numPlyr;}//get number of player
        int  getNum()  const {return numCd;}//get number called
        char getFace() const {return faceCd;}//get the face of dice called
        int  getRond() const {return round;}//get the # of round
        bool getWild() const {return wild;}//get the wild(true or false)
        int getQuan();
        void pntDice();//print out the dice
};

#endif	/* PLAYER_H */

