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
        char *dices; //dices of player
        char *rolDice(int);//roll dice
        char *getDice() const {return dices;} //get all dices
        static int numPlyr;//number of player
        static char faceCd;//face Called
        static int numCd;//number of dice called
        static int round;//round #
        static bool wild;
    public: 
        Player(int);//Constructor
        ~Player();//Destructor
        void slOrder(int);//randomly select the order of player(not AI)
        void chalng(int &);
        void bid(int &);
        int getOrdr()  const {return order;}//get the order
        int getNumP()  const {return numPlyr;}//get number of player
        int getNum()   const {return numCd;}//get number called
        char getFace() const {return faceCd;}//get the face of dice called
        void pntDice();//print out the dice
        static void renew(char,int);//renew face and number of dices bided
};

#endif	/* PLAYER_H */

