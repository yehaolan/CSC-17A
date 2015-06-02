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
int Player::round=0;
int Player::numCd;
char Player::faceCd='0';
bool Player::wild=false;

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

void Player::slOrder(int n) {
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
    round++;
}

void Player::chalng(int &open) {
    string ans="N";//answer of open or not
    //prompt user for challenge or not
    if(round!=0&&open==-1) {
        do {
            cout<<"Would you like to challenge?(Y or N): ";
            cin>>ans;
            if(ans!="Y"&&ans!="N"&&ans!="y"&&ans!="n") 
                cout<<"Invalid input"<<endl;
        } while(ans!="Y"&&ans!="N"&&ans!="y"&&ans!="n");
    }
    //when answer is open
    if(ans=="Y"||ans=="y") {
        open=getOrdr(); //set open to true
        cout<<"You Challenge"<<endl;
    }
}

void Player::bid(int &open) {
    string bStr;
    int numTemp;
    char fceTemp;
    bool invalid;
    //when answer is open
    if(open==-1) { //when answer is not open
        cin.ignore();
        do {
            numTemp=0;
            fceTemp=' ';
            invalid=false;
            if(round<=2) {
            cout<<"Your bidding: ";
            cout<<"format:\"3 4\"(means u bid 3 4s,and 1s are wild) or \"4n5\"(means you bid 4 5s only, and 1s are not wild)"<<endl;
            cout<<"First bid must be >= 1.5*players"<<endl;
            }
            cout<<"Your bidding: ";
            getline(cin,bStr);//1st element is number of dice,2nd is space or n,3rd is face of dice
            //check the input valid or not
            if(bStr.length()!=3&&bStr.length()!=4) invalid=true;//length only 3 or 4
            if(bStr.length()==3||bStr.length()==4) {
                for(int i=0;i<bStr.length();i++) {  
                    if(i==bStr.length()-2) {
                        if(bStr.at(i)!=' '&&bStr.at(i)!='n'&&bStr.at(i)!='N') invalid=true;
                    }
                    if(i<bStr.length()-2) //number of one face of dice should be a integer
                        if(bStr.at(i)<'0'||bStr.at(i)>'9') invalid=true;
                    if(i>bStr.length()-2) //face of dice should be between 1 and 6
                        if(bStr.at(i)<'1'||bStr.at(i)>'6') invalid=true;
                }
            }
            if(!invalid) {
                if(bStr.length()==3) {
                    numTemp=static_cast<int>(bStr.at(0)-48);
                    fceTemp=bStr.at(2);
                } else if(bStr.length()==4) {
                    numTemp=static_cast<int>(bStr.at(0)-48)*10+static_cast<int>(bStr.at(1)-48);
                    fceTemp=bStr.at(3);
                }
            }
            //if format of input is right, check the contents of input
            if(numTemp<numCd) invalid=true; //quantity less than previous one
            //quantity=previous one,but face of dice< previous one
            if(numTemp==numCd&&fceTemp<=faceCd) invalid=true;
            if(numTemp>numPlyr*5) invalid=true;
            if(invalid) cout<<"Invalid input!!"<<endl;
        } while(invalid);
        
        renew(fceTemp,numTemp);
        if(bStr.at(bStr.length()-2)=='n'||bStr.at(bStr.length()-2)=='N') wild=false;
        if(bStr.at(bStr.length()-1)=='1') wild=false;
        cout<<"You bid "<<numCd<<"  "<<faceCd<<"s";
        if(wild) cout<<" "<<endl;
        else cout<<" only"<<endl;
    }
}
