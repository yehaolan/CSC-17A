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

int Player::numPlyr=0;
int Player::numCd;
char Player::faceCd='0';

//Constructor
Player::Player(int n) {
    srand(static_cast<unsigned int>(time(0)));
    dices=rolDice(5);
    order=rand()%n;//random get the order
    numCd=n*3/2;
    numPlyr++;
}

//Destructor
Player::~Player() {
    delete []dices;//deallocate memory
}

Player::order(int n) {
    order=rand()%n;
}

//roll the dice
char *Player::rolDice(int n) {
    char *dice=new char[n];//allocate memory for char array
    //randomly roll dice
    for(int i=0;i<n;i++) {
        dice[i]=static_cast<char>(rand()%6+1+48);
    }
    return dice;
}

//print out the dices
void Player::pntDice() {
    for(int i=0;i<5;i++) {
        cout<<dices[i]<<" ";
    }
}

void Player::renew(char f, int n) {
    faceCd=f;
    numCd=n;
}

void Player::chalng() {
    
}

void Player::bid() {
    
}
