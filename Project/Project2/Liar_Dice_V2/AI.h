/* 
 * File:   AI.h
 * Author: Haolan Ye(Benjamin)
 * Created on May 31, 2015, 10:29 AM
 * Purpose: CSC-17A Project 2 Liar Dice V2 AI header file 
 */

#ifndef AI_H
#define	AI_H

#include "Player.h"
class AI : public Player {
    private:
        static int numAI; //number of AI
        vector<char> exist;//faces of dice that exist in AI's hand
        vector<char> nExist;//faces of dice that doesn't exist in AI's hand
        vector<char> gtEs();//find the faces of dice that exist in AI's hand
        vector<char> gtNtEs();//find the faces of dice that doesn't exist in AI's hand
        char getMtFr();//get the most frequent face of dice in the dices
    public:
        AI();
        int getNAI() const {return numAI;} //get the number of AI in the game
        //there is no destructor in AI class because its dices will be deallocate by the destructor of Player class
        void chalng(); //AI challenge
        void bid(); //AI bid
        vector<char> getEs() const {return exist;} //get the faces of dice that exist in AI's hand
        vector<char> getNtEs() const {return nExist;}//get the faces of dice that doesn't exist in AI's hand
        void pntEs(); //print the dices that exist
        void pntNtEs();//print the dices that don't exist
        void pntDice();//print AI's dices
        
        
};

#endif	/* AI_H */

