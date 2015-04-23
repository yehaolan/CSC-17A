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
void bidP1(int &,Player &,char &,int &,int);//First player(you)
void AI(int &,Player &,char &,char &);
int getQuan(Player,char);
vector<char> getNtEs(char *);
vector<char> getEs(char *);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for rolling dice
    srand(static_cast<unsigned int>(time(0)));
    int numPyr;//number of player
    
    int open=-1;//open=-1 -> not open, =0 -> player1 open, =1 -> player2 open etc.
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
    int num=numPyr*3/2;
    //cout<<"face is "<<face<<endl;
    
    //show dices of all players
    for(int i=0;i<numPyr;i++) {
        dspDice(players[i]);
    }
    do {
        bidP1(open,players[0],face,num,numPyr);
        
    } while(open==-1);
    
    
    /*
    cout<<"You guessed "<<players[0].codQuan.size()<<" times"<<endl;
    cout<<"The record of me: "<<endl;
    cout<<"Face  Quantity"<<endl;
    for(int i=0;i<players[0].codQuan.size();i++) {
        cout<<players[0].codVal[i]<<"     "<<players[0].codQuan[i]<<endl;
    }
    */
    
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
        players[i].order=i;
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

void bidP1(int &open,Player &p,char &face,int &num,int numPyr) {
    string ans;//answer of open or not
    string bid;
    int numTemp;
    char fceTemp;
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
        open=p.order; //set open to true
        cout<<"Open"<<endl;
    } else { //when answer is not open
        cin.ignore();
        do {
            numTemp=0;
            fceTemp=' ';
            invalid=false;
            cout<<"Your bidding(format:\"1 2\" or \"2w3\"): ";
            getline(cin,bid);//1st element is number of dice,2nd is space or w,3rd is face of dice
            //check the input valid or not
            if(bid.length()!=3&&bid.length()!=4) invalid=true;//length only 3 or 4
            if(bid.length()==3||bid.length()==4) {
                for(int i=0;i<bid.length();i++) {  
                    if(i==bid.length()-2) {
                        if(bid.at(i)!=' '&&bid.at(i)!='w') invalid=true;
                    }
                    if(i<bid.length()-2) //number of one face of dice should be a integer
                        if(bid.at(i)<'0'||bid.at(i)>'9') invalid=true;
                    if(i>bid.length()-2) //face of dice should be between 1 and 6
                        if(bid.at(i)<'1'||bid.at(i)>'6') invalid=true;
                }
            }
            if(!invalid) {
                if(bid.length()==3) {
                    numTemp=static_cast<int>(bid.at(0)-48);
                    fceTemp=bid.at(2);
                } else if(bid.length()==4) {
                    numTemp=static_cast<int>(bid.at(0)-48)*10+static_cast<int>(bid.at(1)-48);
                    fceTemp=bid.at(3);
                }
            }
            //if format of input is right, check the contents of input
            if(numTemp<num) invalid=true; //quantity less than previous one
            //quantity=previous one,but face of dice< previous one
            if(numTemp==num&&fceTemp<=face) invalid=true;
            if(numTemp>numPyr*5) invalid=true;
            if(invalid) cout<<"Invalid input!!"<<endl;
        } while(invalid);
        
        num=numTemp;
        face=fceTemp;
        cout<<"You guessed "<<num<<" of "<<face<<endl;
        p.codVal.push_back(face);
        p.codQuan.push_back(num);
    }
}

void AI(int &open,Player &p,char &face,int &num,int numPyr) {
    //determine challenge or not
    if(getQuan(p,face)>=num) open=-1; //when bided number of a kind dice <= AI's, not challenge 
    else if(getQuan(p,face)==0&&num>=numPyr*2) open=p.order;
    else if(getQuan(p,face)==1&&num-1>(numPyr-1)*2) {
        if(rand()%6<3) open=p.order; //50% to open
    } else if(getQuan(p,face)==2&&num-2>(numPyr-1)*2) {
        if(rand()%6<2) open=p.order; //1/3 to open
    } else if(getQuan(p,face)==3&&num-3>(numPyr-1)*2) {
        if(rand()%6<2) open=p.order; //1/3 to open
    }
    if(num>=numPyr*4) open=p.order;
    //bid
    if(open==-1) {
        vector<char> nExist=getNtEs(p.dices);
        if(rand()%5>=2||(nExist.size()==1&&nExist[0]=='1')) {  //truth 3/5
            vector<char> exist=getEs(p.dices);
            char faceTem;
            do {
                faceTem=exist[rand()%exist.size()];
            } while(faceTem=='1');
            if(faceTem<=face) num++;
            face=faceTem;
        } else { //lie 2/5
            //get the face of dice that AI doesn't have
            char faceTem;
            do {
                faceTem=nExist[rand()%nExist.size()];
            } while(faceTem=='1');
            if(faceTem<=face) num++;
            face=faceTem;
        } 
        cout<<"He bid "<<num<<" of "<<face<<endl;
    }
}

//get the quantity of one face of dice of one player
int getQuan(Player p,char face) {  //Tested it's ok
    int num=0;
    int ones=0;
    for(int i=0;i<5;i++) {
        if(p.dices[i]==face) num++;
        if(p.dices[i]=='1'&&face!='1') ones++;
    }
    return num+ones;
}

//get the faces of dice that doesn't exist in AI's hand
vector<char> getNtEs(char *dices) {  //Tested it's ok
    vector<char> nExist;//not exist face of dice
    for(int i=1;i<=6;i++) {
        nExist.push_back(i+48);
    }
    for(int i=0;i<5;i++) {
        nExist[static_cast<int>(dices[i]-48)-1]='0';
    }
    for(int i=0;i<5;i++) {
        for(int j=i+1;j<6;j++) {
            if(nExist[i]<nExist[j]) {
                char temp=nExist[i];
                nExist[i]=nExist[j];
                nExist[j]=temp;
            }
        }
    }
    for(int i=5;i>=0;i--) {
        if(nExist[i]=='0') nExist.pop_back();
    }
    return nExist;
}

//get the faces of dice that exist in AI's hand
vector<char> getEs(char *dices) { //Tested it's ok
    bool inside;
    vector<char> exist;
    for(int i=0;i<5;i++) {
        inside=false;
        for(int j=0;j<exist.size();j++) {
            if(exist[j]==dices[i]) inside=true;
        }
        if(!inside) exist.push_back(dices[i]);
    }
    return exist;
}