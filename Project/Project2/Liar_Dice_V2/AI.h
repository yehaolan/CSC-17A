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
        static int numAI;
        vector<char> exist;
        vector<char> nExist;
        vector<char> gtEs();
        vector<char> gtNtEs();
        char getMtFr();
    public:
        AI();
        int getNAI() const {return numAI;}
        //there is no destructor in AI class because its dices will be deallocate by the destructor of Player class
        void chalng();
        void bid();
        vector<char> getEs() const {return exist;}
        vector<char> getNtEs() const {return nExist;}
        
        void pntEs();
        void pntNtEs();
        void pntDice();
        
        
};

#endif	/* AI_H */

