/* 
 * File:   AI.h
 * Author: admin
 *
 * Created on May 31, 2015, 6:59 PM
 */

#ifndef AI_H
#define	AI_H

#include "Player.h"

class AI : public Player {
    private:
        vector<char> exist;
        vector<char> nExist;
    public:
        AI();
        //there is no destructor in AI class because its dices will be deallocate by the destructor of Player class
        void chalng(int &);
        void bid(int &);
};

#endif	/* AI_H */

