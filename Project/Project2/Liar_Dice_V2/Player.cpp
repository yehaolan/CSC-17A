/* 
 * File:   Player.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on May 31, 2015, 10:29 AM
 * Purpose: CSC-17A Project 2 Liar Dice V2 source file 
 */

//System libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//user library
#include "Player.h"

Player::Player() {
    dices=rolDice();
}

