/* 
 * File:   Player.h
 * Author: Haolan Ye(Benjamin)
 * Created on May 31, 2015, 10:29 AM
 * Purpose: CSC-17A Project 2 Liar Dice V2 player header file 
 */

#ifndef PLAYER_H
#define	PLAYER_H

//User libraries
#include "Info.h"
#include "aVector.h"
#include "AbsPlayer.h"

class Player:public AbsPlayer {
    private:
        Info info;//save the information about players
    protected:
        int order; //0 is player, 1 is AI#1, 2 is AI#2
        aVector<char> dices; //dices of player
        aVector<char> rolDice(int);//roll dice  
        static int open;// -1 is not open, 0 is player open, 1 is AI#1 open,2 is AI#2 open
        static int numPlyr;//number of player
        static int numCd;//number of dice called
        static char faceCd;//face Called
        static int round;//round #
        static bool wild;//wild
        static int lastBdr;//the last bidder
        static void renew(char,int,bool);//After bidding, renew face and number of dices
        void sign();//sign in/sign up
        int getNInf();//get the number of previous players
        void setNInf(int);//set the number of previous players
        void wtFile(Info *,int);//write the Information of player to the file
        void rdFile(Info *,int);//read the Information of player to the file
        bool validCC(string,int);//function that valid card number
    public: 
        Player();//Constructor
        ~Player();//Destructor
        void init();//initialize the variables of the game
        void chalng();//player challenge
        void bid();//player bid
        void roll();//roll the dice
        static void setNumP(int n) {numPlyr= n;}//set the number of player
        static void setNumC();//initialize the number called
        static void reset();//reset the game
        static void setOpen(int n) {open=n;}//set the open
        static void setNum(int n) {numCd=n;} //set the number called
        static void setFace(char c) {faceCd=c;}//set the face called
        static void setRond(int r) {round=r;}//set the round
        static void setLBdr(int l) {lastBdr=l;}//set the last bidder
        //setter for member variables
        void setOrdr(int n) {order=n;};//set the order
        void setName(string s) {info.name=s;} //set the name
        void setPW(string);//set the password
        void setEm(string e) {info.email=e;}//set the email
        void setInfo(Info i) {info=i;}//set the structure
        void setCoin(int c) {info.coin=c;}//set player's coin
        void setInfo(string,string,string);//set the info
        void addCoin();//add the coins by using credit card
        unsigned int getPW() const {return info.pw;}//get password
        //getter for member variables
        int  getOrdr() const {return order;}//get the order
        int  getOpen() const {return open;}//get the player who challenge
        int  getNumP() const {return numPlyr;}//get number of player
        int  getNum()  const {return numCd;}//get number called
        int  getCoin() const {return info.coin;}//get the coin of player
        int  getRond() const {return round;}//get the # of round
        aVector<char> getDice() const {return dices;}//get all dices
        char getFace() const {return faceCd;}//get the face of dice called
        static int getLBdr() {return lastBdr;}//get the last bidder
        Info getInfo() const {return info;}//get the info (a structure)
        bool getWild() const {return wild;}//get the wild(true or false)
        string getName() const {return info.name;}//get the name
        string getEm() const {return info.email;}//get email
        int getQuan();//get the number of face bided
        void pntDice();//print out the dice
        void renewFl(string,int);//renew the information file
};

#endif	/* PLAYER_H */

