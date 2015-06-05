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
#include "AI.h"
#include "Player.h"

//Global Constants

//Function prototypes
void result(Player &,int,AI *);//Determine who win and lost
int  getNP();//Prompt for the number of player
void destryAI(AI *,int);//destroy AIs
void destryPl(Player);//destroy player
//Player *cretPyr(int);//create player and roll dice

//Execution begins here
int main(int argc, char** argv) {
    cout<<"Welcome to Liar Dice"<<endl<<endl;
    //set seed for rolling dice
    srand(static_cast<unsigned int>(time(0)));
    char ans;
    Player p1;
    p1.init();
    
    do {
        Player::reset();
        AI::reset();
        p1.roll();
        //menu
        do {
            cout<<endl<<"********Menu********"<<endl;
            cout<<"1. Play game"<<endl;
            cout<<"2. Add gaming coin"<<endl;
            cout<<"3. Exit the game"<<endl;
            cout<<"You choose(1-3): ";
            cin>>ans;
            if(ans!='1'&&ans!='2'&&ans!='3') {
                cout<<"Invalid input"<<endl;
            }
        }while(ans!='1'&&ans!='2'&&ans!='3');
        if(ans=='2') {
            p1.addCoin();
        }else if(ans=='1') {
            int np=getNP();//ask number of player
            AI *a=new AI[np-1];
            Player::setNumC();
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
            destryAI(a,np-1);
        }
        if(ans!='3') {
            cout<<"Click Enter to continue...";
            cin.ignore();
            cin.ignore();
        }
    } while(ans!='3');
    cout<<"Now player #1 has "<<p1.getCoin()<<" coins "<<endl;
    p1.renewFl(p1.getName(),p1.getCoin());
    destryPl(p1);
    //Exit stage right
    return 0;
}

//Prompt for the number of player
int getNP() {
    int np;//number of player
    string input;//temp for input
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
void result(Player &p,int numAI,AI *a) {
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
    //when the total number of dices bided greater than the number bided
    if(ttDices>=p.getNum()) {
        //if player challenge
        if(p.getOpen()==0) {
            cout<<"Your challenge failed"<<endl;
            p.setCoin(p.getCoin()-5);
            cout<<"You lost 5 coins"<<endl;
            
            p.renewFl(p.getName(),p.getCoin());
        }
        //if AI challenge
        else {
            cout<<"AI #"<<p.getOpen()<<"'s challenge failed"<<endl;
            //if AI challenge me
            if(p.getLBdr()==0) {
                p.setCoin(p.getCoin()+5);
                cout<<"You won 5 coins"<<endl;
                p.renewFl(p.getName(),p.getCoin());
            }
        }
    //when the total number of dices bided less than the number bided
    } else {
        //if player challenge
        if(p.getOpen()==0) {
            cout<<"Your challenge succeed"<<endl;
            p.setCoin(p.getCoin()+5);
            cout<<"You won 5 coins"<<endl;
            
            p.renewFl(p.getName(),p.getCoin());
        }
        //if AI challenge
        else {
            cout<<"AI #"<<p.getOpen()<<"'s challenge succeed"<<endl;
            //if AI challenge me
            if(p.getLBdr()==0) {
                p.setCoin(p.getCoin()-5);
                cout<<"You lost 5 coins"<<endl;
                p.renewFl(p.getName(),p.getCoin());
            }
        }
    }
    //Tell player how many coins he/she has
    cout<<"Now you have "<<p.getCoin()<<" Coins"<<endl;
}

//deallocate memory
void destryAI(AI *a,int n) {
    for(int i=0;i<n;i++) {
        delete a[i].getDice();
    }
    delete []a;
}

void destryPl(Player p) {
    delete p.getDice();
}

