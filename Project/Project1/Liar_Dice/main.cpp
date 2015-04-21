/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on April 21, 2015, 10:29 AM
 * Purpose: CSC-17A Project 1 Liar Dice
 */

//System libraries
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

//User libraries
#include "Player.h"

//Global Constants

//Function prototypes
Player *cretPyr(int);//create player and roll dice
int *rolDice(int);//roll 5 dices
void dspDice(Player);//display dice of a player

//Execution begins here
int main(int argc, char** argv) {
    //set seed for rolling dice
    srand(static_cast<unsigned int>(time(0)));
    int numPyr;
    
    cout<<"Welcome to Liar Dice"<<endl<<endl;
    
    //Prompt number of player
    do {
        cout<<"Amount of player(2 or 3): ";
        cin>>numPyr;
        if(numPyr>3||numPyr<2)
            cout<<"Invalid input"<<endl;
    } while(numPyr>3||numPyr<2);
    //create players
    Player *players=cretPyr(numPyr);
    for(int i=0;i<numPyr;i++) {
        dspDice(players[i]);
    }
    
    
    
    //deallocate memory
    for(int i=0;i<numPyr;i++) {
        delete []players[i].dices;
    }
    delete []players;
    //Exit stage right
    return 0;
}

//create players and roll dice
Player *cretPyr(int n) {
    Player *players=new Player[n];
    for(int i=0;i<n;i++) {
        players[i].dices=rolDice(5);
    }
    return players;
}

int *rolDice(int n) {
    int *dices=new int[n];
    for(int i=0;i<n;i++) {
        dices[i]=rand()%6+1;
    }
    return dices;
}

void dspDice(Player p) {
    cout<<"Dice: ";
    for(int i=0;i<5;i++) {
        cout<<p.dices[i]<<" ";
    }
    cout<<endl;
}