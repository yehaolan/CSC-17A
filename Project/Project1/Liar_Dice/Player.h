/* 
 * File:   Player.h
 * Author: Haolan Ye(Benjamin)
 * Created on April 21, 2015, 10:29 AM
 * Purpose: CSC-17A Project 1 Liar Dice header file
 */

#ifndef PLAYER_H
#define	PLAYER_H

struct Player {
    char *dices;
    vector<char> codVal;//called dice
    vector<int> codQuan;//quantity of dice called
    int order;//the order of the game
};

#endif	/* PLAYER_H */

