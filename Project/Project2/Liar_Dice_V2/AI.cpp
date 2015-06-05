/* 
 * File:   AI.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on May 31, 2015, 10:29 AM
 * Purpose: CSC-17A Project 2 Liar Dice V2 AI cpp file 
 */


//System libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User library
#include "AI.h"

int AI::numAI=0; //initialize the static variable

//Constructor
AI::AI() {
    //cout<<"AI constructor!!!"<<endl;
    dices=rolDice(5);
    order=++numAI;
    exist=gtEs();
    nExist=gtNtEs();
}

//AI bid
void AI::bid() {
    //bid
    if(open==-1) {
        char faceTem;
        int numTem=numCd;
        if(wild) {
            //truth 3/5
            if(rand()%5>=2||(nExist.size()==1&&nExist[0]=='1')) {  
                if(rand()%3<2&&faceCd==getMtFr())  { //get the most frequent face of of AI's dices
                    faceTem=faceCd;
                } else { //randomly get a dice from existed dices
                    do {
                        faceTem=exist[rand()%exist.size()];
                    } while(faceTem=='1');
                }

                if(faceTem<=faceCd) numTem++;
                //faceCd=faceTem;


            } else { //lie 2/5
                //get the face of dice that AI doesn't have
                do {
                    faceTem=nExist[rand()%nExist.size()];
                } while(faceTem=='1');
                if(faceTem<=faceCd) numTem++;
                //faceCd=faceTem;
            }
        } else {
            
            
            //I can lie
            //lie
            //lie
            
            
            faceTem=getMtFr();
            if(faceTem<=faceCd) numTem++;
        }
        renew(faceTem,numTem,wild);
        cout<<"AI #"<<order<<" bid "<<numCd<<"  "<<faceCd<<"'s";
        if(wild) cout<<" "<<endl;
        else cout<<" only"<<endl;
    }
    round++;
}

//AI challenge
void AI::chalng() {
     if(round!=0&&open==-1) {
        //determine challenge or not
        if(wild) {
            if(getQuan()>=numCd) open=-1; //when bided number of a kind dice <= AI's, not challenge 
            else if(getQuan()==0&&numCd>=numPlyr*2) open=order;
            else if(getQuan()==1&&numCd-1>(numPlyr-1)*2) {
                if(rand()%6<3) open=order; //50% to open
            } else if(getQuan()==2&&numCd-2>(numPlyr-1)*2) {
                if(rand()%6<2) open=order; //1/3 to open
            } else if(getQuan()==3&&numCd-3>(numPlyr-1)*2) {
                if(rand()%6<2) open=order; //1/3 to open
            } else if(getQuan()>=4&&numCd-getQuan()>(numPlyr-1)*2) {
                open=order; // 100% to open
            }
            if(numCd>=numPlyr*3) {
                if(numCd>=numPlyr*4) open=order;
                else {
                    if(rand()%5<4) open=order;
                }
            }
        } else {
            if(numCd-getQuan()>=2*(numPlyr-1)) open=order;
        }
        if(open==order) cout<<"AI #"<<order<<" challenge"<<endl;
        else cout<<"AI #"<<order<<" does not challenge"<<endl;
    }
}

//get the most frequent face of dice in the dices
char AI::getMtFr() {
    int *temp=new int[5];
    int cnt=1;//count for the dice
    int hgst;//highest number
    int indx;//index
    //if dices: 2 2 3 4 2, then temp: 3 3 1 1 3
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            if(dices[i]==dices[j]) cnt++;
        }
        temp[i]=cnt;
        cnt=1;
    }
    hgst=temp[0];//initialize the highest number
    indx=0;//initialize the index
    //find out the highest and its index
    for(int i=0;i<5;i++) {
        if(temp[i]>hgst) {
            hgst=temp[i];
            indx=i;
        }
    }
    delete []temp;//delete allocate memory
    return dices[indx];
}

//get the faces of dice that exist in AI's hand
vector<char> AI::gtEs() {
    bool inside;
    vector<char> e;
    for(int i=0;i<5;i++) {
        inside=false;
        //use for loop to get the existing dices
        for(int j=0;j<e.size();j++) {
            if(e[j]==dices[i]) inside=true;
        }
        if(!inside) e.push_back(dices[i]);
    }
    return e;
}

//get the faces of dice that doesn't exist in AI's hand
vector<char> AI::gtNtEs() {
    vector<char> ne;//not exist face of dice
    //initialize 6 elements from 1 to 6
    for(int i=1;i<=6;i++) {
        ne.push_back(i+48);
    }
    //when the face of the dices comes up, set that face in the vector to 0
    for(int i=0;i<5;i++) {
        ne[static_cast<int>(dices[i]-48)-1]='0';
    }
    //sort the vector form high to low
    for(int i=0;i<5;i++) {
        for(int j=i+1;j<6;j++) {
            if(ne[i]<ne[j]) {
                char temp=ne[i];
                ne[i]=ne[j];
                ne[j]=temp;
            }
        }
    }
    //take out the existing number
    for(int i=5;i>=0;i--) {
        if(ne[i]=='0') ne.pop_back();
    }
    return ne;//return the vector
}

//print the dices that exist
void AI::pntEs() {
    cout<<endl<<"Exist: ";
    for(int i=0;i<exist.size();i++) {
        cout<<exist[i]<<" ";
    }
    cout<<endl;
}

//print the dices that don't exist
void AI::pntNtEs() {
    cout<<endl<<"Not Exist: ";
    for(int i=0;i<nExist.size();i++) {
        cout<<nExist[i]<<" ";
    }
    cout<<endl;
}

//print AI's dices
void AI::pntDice() {
    cout<<"AI #"<<getOrdr()<<":  ";
    for(int i=0;i<5;i++) {
        cout<<dices[i]<<" ";
    }
    cout<<endl;
}

void AI::operator =(const AI& right) {
    delete []dices;
    dices=new char[5];
    for(int i=0;i<5;i++) {
        dices[i]=right.dices[i];
    }
}