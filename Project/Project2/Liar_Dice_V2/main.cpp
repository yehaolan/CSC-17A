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
#include <fstream>
#include <string>
using namespace std;

//User libraries
#include "Player.h"
#include "AI.h"
//Global Constants

//Function prototypes
void result(Player,int,AI []);//Determine who win and lost
int  getNP();//Prompt for the number of player
void wtFile(Player *,int);//write the array of Player into file
void rdFile(Player *,int);//read the file 

//Player *cretPyr(int);//create player and roll dice

//Execution begins here
int main(int argc, char** argv) {
    /*
    
    //create players and roll dices
    Player *players=cretPyr(numPyr);
    Player *copy=new Player[numPyr];//create for reading file
    wtFile(players,numPyr);//write all the players into file

    //read the binary file(players)
    rdFile(copy,numPyr);
    //show dices of all players
    for(int i=0;i<numPyr;i++) {
        dspDice(copy+i);
    } 
    //display the result of the game
    result(num,face,numPyr,copy,open,wild);
    //deallocate memory
    for(int i=0;i<numPyr;i++) {
        //delete []copy[i].dices;
        delete []players[i].dices;
    }
    delete []players;
    delete []copy;
    
    */
    //set seed for rolling dice
    srand(static_cast<unsigned int>(time(0)));
    int np=getNP();//ask number of player
    Player p1;
    AI *a=new AI[np-1];
    //vector<AI> a;
    //a.push_back(a1);
    
    //write and read file 
    
    cout<<"Number of player: "<<p1.getNumP()<<endl;
    p1.init();
    int temp=rand()%np;//randomly select who is the first to bid
    //show your dice
    p1.pntDice();
    //game begins
    //run until somebody challenges
    do {
        switch(temp) {
            case 0: {
                p1.chalng();//player challenge
                if(np==3) a[1].chalng();//AI #2 challenge
                p1.bid();//player bid
            }
            case 1: {
                a[0].chalng();//AI #1 challenge
                if(np==3) a[1].chalng();//AI #2 challenge
                a[0].bid();//AI #1 bid
            }
            case 2: {
                if(np==3) {
                    p1.chalng();//Player challenge
                    a[1].chalng();//AI #2 challenge
                    a[1].bid();//AI #2 bid
                }
            }
        }
        temp=0;
    } while(p1.getOpen()==-1);
    
    result(p1,np-1,a);
    cout<<"The end of main"<<endl;
    //Exit stage right
    return 0;
}

//Prompt for the number of player
int getNP() {
    int np;//number of player
    string input;//temp for input
    cout<<"Welcome to Liar Dice"<<endl<<endl;
    //Prompt user for number of player
    do {
        cout<<"Number of player(2(Easy) or 3(Hard)): ";
        cin>>input;
        if(input!="2"&&input!="3")
            cout<<"Invalid input"<<endl;
    } while(input!="2"&&input!="3");
    np=(input=="2"?2:3);
    return np;
}

//print out the result
void result(Player p,int numAI,AI *a) {
    p.pntDice();
    for(int i=0;i<numAI;i++) {
        a[i].pntDice();
    }
    int ttDices=0;
    ttDices+=p.getQuan();
    for(int i=0;i<numAI;i++) {
        ttDices+=a[i].getQuan();
    }
    cout<<"There are "<<ttDices<<" "<<p.getFace()<<"'s in all players"<<endl;
    if(ttDices>=p.getNum()) {
        if(p.getOpen()==0) cout<<"Your challenge failed"<<endl;
        else cout<<"AI #"<<p.getOpen()<<"'s challenge failed"<<endl;
    } else {
        if(p.getOpen()==0) cout<<"Your challenge succeed"<<endl;
        else cout<<"AI #"<<p.getOpen()<<"'s challenge succeed"<<endl;
    }
    cout<<"The end of the result"<<endl;
}
/*
void wtFile(Player *p,int n) {
    fstream out;
    cout<<"Write to the file..."<<endl;
    out.open("players.txt",ios::out|ios::binary);
    if(!out.fail()) {
       out.write(reinterpret_cast<char *>(p),sizeof(Player)*n); 
    }
    out.close();
}

void rdFile(Player *c,int n) {
    fstream in;
    cout<<"Read from the file..."<<endl<<endl;
    in.open("players.txt",ios::in|ios::binary);
    if(!in.fail()) {
       in.read(reinterpret_cast<char *>(c),sizeof(Player)*n); 
    }
    in.close();
}

//create players and roll dices
Player *cretPyr(int n) {
    Player *players=new Player[n];
    for(int i=0;i<n;i++) {
        players[i].dices=rolDice(5);
        players[i].order=i;
    }
    return players;
}




*/