/* 
 * File:   Player.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on May 31, 2015, 10:29 AM
 * Purpose: CSC-17A Project 2 Liar Dice V2 player source file 
 */

//System libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;

//user library
#include "Player.h"
#include "GeneralHashFunctions.h"

int Player::open=-1;
int Player::numPlyr=0;
int Player::round=0;
int Player::numCd;
char Player::faceCd='0';
bool Player::wild=true;

//Constructor
Player::Player() {
    dices=rolDice(5);
    numPlyr++;
    
}

//Destructor
/*
Player::~Player() {
    delete []dices;//deallocate memory
}
*/

//initialize the game variable
void Player::init() {
    numCd=numPlyr*3/2;
    order=0;
    sign();
}

void Player::sign() {
    bool nmExist;//invalid
    bool pwWrong;//name exist
    do {
        //ask name
        string n;
        cin.ignore();
        cout<<"Your name: ";
        getline(cin,n);
        //ask password
        string p;
        cout<<"Your password: ";
        cin>>p;
        //ask email
        string e;
        cout<<"Your email: ";
        cin>>e;
        int numInfo=getNInf()+1; //1
        
        Info *allInfo=new Info[numInfo];//2
        cout<<"Number of previous player is "<<(numInfo-1)<<endl;
        //when number of previous player is 0
        if(numInfo==1) {
            setInfo(n,p,e);
            allInfo[0]=getInfo();
            wtFile(allInfo,numInfo);
            setNInf(numInfo);
        } else {
            rdFile(allInfo,(numInfo-1));//1
            nmExist=false;
            pwWrong=false;
            for(int i=0;i<numInfo-1;i++) {
                cout<<"#"<<i<<": "<<allInfo[i].name<<endl;
                if(n==allInfo[i].name) {
                    nmExist=true;
                    pwWrong=true;
                    if(nmExist) {
                        unsigned int hashpw=JSHash(p);
                        unsigned int hshPass=JSHash(allInfo[i].pw);
                        if(hashpw==hshPass) pwWrong=false;
                    }
                    break;
                }
            }
            if(!nmExist) {
                setInfo(n,p,e);
                allInfo[numInfo-1]=getInfo();
                wtFile(allInfo,numInfo);
                cout<<"Set the previous number of player is "<<numInfo<<endl;
                setNInf(numInfo);
            } else  { //name exist
                if(!pwWrong) {
                    cout<<"Login Successfully"<<endl;
                } else {
                    cout<<"Wrong name or wrong password"<<endl;
                }
                setNInf(--numInfo);
            }
            
        }
        
        delete []allInfo;
    } while(nmExist);
    
    
}

void Player::wtFile(Info *info,int n) {
    fstream out;
    cout<<"Write all info to the file..."<<endl;
    out.open("Information.txt",ios::out|ios::binary);
    if(!out.fail()) {
       out.write(reinterpret_cast<char *>(info),sizeof(Info)*n); 
    }
    out.close();
}

void Player::rdFile(Info *info,int n) {
    fstream in;
    cout<<"Read all info from the file..."<<endl;
    in.open("Information.txt",ios::in|ios::binary);
    if(!in.fail()) {
       in.read(reinterpret_cast<char *>(info),sizeof(Info)*n); 
    }
    in.close();
}

void Player::setInfo(string n, string p, string e) {
    setName(n);
    setPW(p);
    setEm(e);
}

int Player::getNInf() {
    int n=0;
    fstream in;
    //cout<<"Read from the file..."<<endl<<endl;
    in.open("numOfPlayer.txt",ios::in);
    if(!in.fail()) {
        in>>n;
    }
    in.close();
    return n;
}

void Player::setNInf(int num) {
    fstream out;
    cout<<"Write number of previous player to the file..."<<endl;
    out.open("numOfPlayer.txt",ios::out);
    if(!out.fail()) {
       out<<num; 
    }
    out.close();
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
    cout<<"Player: ";
    for(int i=0;i<5;i++) {
        cout<<dices[i]<<" ";
    }
    cout<<endl;
}

//After bidding, renew the face and number of dice
void Player::renew(char f, int n,bool w) {
    faceCd=f;
    numCd=n;
    if(wild)
        wild=w;
}


int Player::getQuan() {
    int num=0;
    int ones=0;
    for(int i=0;i<5;i++) {
        if(dices[i]==faceCd) num++;
        if(wild&&faceCd!='1'&&dices[i]=='1') ones++;
        //when 1 is not wild
    }
    return num+ones;
}

//player challenge
void Player::chalng() {
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

//player bid
void Player::bid() {
    //declare variable
    string bStr;//string that player input
    //temp variables of number of dice, face, and wild
    int numTemp;
    char fceTemp;
    bool widTemp;
    bool invalid;//invalid
    //when answer is open
    if(open==-1) { //when answer is not open
        cin.ignore();
        do {
            //initialize variables
            numTemp=0;
            fceTemp=' ';
            widTemp=true;
            invalid=false;
            if(round<=2) {
            cout<<"Your bidding: ";
            cout<<"format:\"3 4\"(means u bid 3 4's,and 1s are wild) or \"4n5\"(means you bid 4 5's only, and 1s are not wild)"<<endl;
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
        //determine wild or not
        if(bStr.at(bStr.length()-2)=='n'||bStr.at(bStr.length()-2)=='N') widTemp=false;
        if(bStr.at(bStr.length()-1)=='1') widTemp=false;
        //output what player bid
        renew(fceTemp,numTemp,widTemp);//renew the static variable in Player class
        cout<<"You bid "<<numCd<<"  "<<faceCd<<"'s";
        if(widTemp) cout<<" "<<endl;
        else cout<<" only"<<endl;
        
        round++;
    }
}
