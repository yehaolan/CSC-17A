/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on April 21, 2015, 10:29 AM
 * Purpose: CSC-17A Project 1 Liar Dice
 */

//System libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

//User libraries
#include "Player.h"

//Global Constants

//Function prototypes
Player *cretPyr(int);//create player and roll dice
char *rolDice(int);//roll 5 dices
void dspDice(Player);//display dice of a player
void bidP1(int &,Player &,char &,char &);//First player(you)
void AI(int &,Player &,char &,char &);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for rolling dice
    srand(static_cast<unsigned int>(time(0)));
    int numPyr;//number of player
    
    int open=0;//open=0 -> not open, =1 -> player1 open, =2 -> player2 open
    cout<<"Welcome to Liar Dice"<<endl<<endl;
    
    //Prompt number of player
    do {
        cout<<"Amount of player(2 or 3): ";
        cin>>numPyr;
        if(numPyr>3||numPyr<2)
            cout<<"Invalid input"<<endl;
    } while(numPyr>3||numPyr<2);
    //create players and roll dices
    Player *players=cretPyr(numPyr);
    char face='0';
    char num='0'+numPyr*3/2;
    //cout<<"face is "<<face<<endl;
    
    //show dices of all players
    for(int i=0;i<numPyr;i++) {
        dspDice(players[i]);
    }
    do {
        bidP1(open,players[0],face,num);
        
    } while(open==0);
    
    cout<<"You guessed "<<players[0].codQuan.size()<<" times"<<endl;
    cout<<"The record of me: "<<endl;
    cout<<"Face  Quantity"<<endl;
    for(int i=0;i<players[0].codQuan.size();i++) {
        cout<<players[0].codVal[i]<<"     "<<players[0].codQuan[i]<<endl;
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

//roll dices and save in char array
char *rolDice(int n) {
    char *dices=new char[n];
    for(int i=0;i<n;i++) {
        dices[i]=static_cast<char>(rand()%6+1+48);
    }
    return dices;
}

//output the dices of a player
void dspDice(Player p) {
    cout<<"Dice: ";
    for(int i=0;i<5;i++) {
        cout<<p.dices[i]<<" ";
    }
    cout<<endl;
}

void bidP1(int &open,Player &p,char &face,char &num) {
    string ans;//answer of open or not
    string bid;
    bool invalid;
    //prompt user for challenge or not
    do {
        cout<<"Would you like to challenge?(Y or N): ";
        cin>>ans;
        if(ans!="Y"&&ans!="N"&&ans!="y"&&ans!="n") 
            cout<<"Invalid input"<<endl;
    } while(ans!="Y"&&ans!="N"&&ans!="y"&&ans!="n");
    //when answer is open
    if(ans=="Y"||ans=="y") {
        open=1; //set open to true
        cout<<"Open"<<endl;
    } else { //when answer is not open
        cin.ignore();
        do {
            invalid=false;
            cout<<"Your bidding(format:\"1 2\" or \"2w3\"): ";
            getline(cin,bid);//1st element is number of dice,2nd is space or w,3rd is face of dice
            if(bid.length()!=3) invalid=true;
            if(bid.length()==3) {
                if(bid.at(0)<49||bid.at(0)>54||bid.at(2)<49||bid.at(2)>54) 
                    invalid=true;
                if(bid.at(1)!=' '&&bid.at(1)!='w') invalid=true;
            }
            //if format of input is right, check the contents of input
            if(bid.at(0)<num) invalid=true; //quantity less than previous one
            //quantity=previous one,but face of dice< previous one
            if(bid.at(0)==num&&bid.at(2)<=face) invalid=true;
            
            if(invalid) cout<<"Invalid input!!"<<endl;
        } while(invalid);
        num=bid.at(0);
        face=bid.at(2);
        p.codVal.push_back(static_cast<int>(bid.at(2)-48));
        p.codQuan.push_back(static_cast<int>(bid.at(0)-48));
    }
}