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

//initialize the static variables
int Player::open=-1;
int Player::numPlyr=0;
int Player::round=0;
int Player::numCd;
char Player::faceCd='0';
bool Player::wild=true;
int Player::lastBdr=-1;

//Constructor
Player::Player() {
    dices=rolDice(5);
    numPlyr++;
}

//Destructor
Player::~Player() {
}

//roll the dice
void Player::roll() {
    aVector<char> a=rolDice(5);
    for(int i=0;i<5;i++) {
        dices[i]=a[i];
    }
}

//roll the dice
aVector<char> Player::rolDice(int n) {
    aVector<char> dice(n);//allocate memory for char array
    //randomly roll dice
    for(int i=0;i<n;i++) {
        dice[i]=static_cast<char>(rand()%6+1+48);
    }
    return dice;
}

//reset the static variables
void Player::reset() {
    open=-1;
    numPlyr=1;
    round=0;
    faceCd='0';
    wild=true;
    lastBdr=-1;
}

//initialize the game variable
void Player::init() {
    order=0;
    sign();
    cout<<"You have "<<getCoin()<<" coins"<<endl;
}

//set the number called
void Player::setNumC() {
    numCd=numPlyr*3/2;
}

//player can buy gaming coin here
void Player::addCoin() {
    int numCoin;//number of coin
    int length;
    bool invalid;
    string cc;
    bool ccRight;
    //prompt player for the number of coin
    do {
        do {
            cout<<"How many gaming coin you would like to buy($1 for 1 coin): ";
            cin>>numCoin;
            if(numCoin<0) 
                cout<<"Invalid input"<<endl;
        } while(numCoin<0);
        //Prompt player for the card number of his/her credit/debit card
        do {
            invalid=false;
            cout<<"Your credit/debit card number: ";
            cin>>cc;
            length=cc.length();
            for(int i=0;i<cc.length();i++) {
                if(cc.at(i)<'0'||cc.at(i)>'9') {
                    invalid=true;
                    break;
                }
            }
        } while(invalid||(length<13||length>16));
        //verify card number by Luhn algorithm
        ccRight=validCC(cc,cc.length());//card number is invalid
    } while(!ccRight);
    cout<<"You bought "<<numCoin<<" gaming coins successfully"<<endl;
    setCoin(getCoin()+numCoin);
    //renew
    renewFl(getName(),getCoin());
    cout<<"Now, you have "<<getCoin()<<" gaming coins"<<endl;
}

//verify the card number by Luhn algorithm
bool Player::validCC(string cc,int digit) {
    int check=0;//check digit
    bool valid=true;
    
    int *reverse=new int[digit-1];//reversed card number
    
    for(int i=0;i<digit-1;i++) {
        reverse[i]=static_cast<int>(cc.at(digit-i-2)-48);
    }
    //double the odd digit
    for(int i=0;i<digit-1;i++) {
        if(i%2==0) {
            reverse[i]=reverse[i]*2;
        } 
    }
    //sum of each digits
    for(int i=0;i<digit-1;i++) {
        if(reverse[i]>9)
            reverse[i]=reverse[i]/10+reverse[i]%10;
    }
    //get the sum of all digits
    for(int i=0;i<digit-1;i++) {
        check+=reverse[i];
    }
    //get the check digit
    check=check*9%10;
    if(check!=static_cast<int>(cc[digit-1]-48)) valid=false;
    delete [] reverse;
    reverse=0;
    return valid;
}

//sign in or Sign up
void Player::sign() {
    bool nmExist;//invalid
    bool pwWrong;//name exist
    int nCoin=0;
    //loop until the player sign up or sign successfully
    do {
        string e;
        cout<<"Your email: ";
        cin>>e;
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
        
        int numInfo=getNInf()+1; //get the number of previous player and add 1
        //Allocate memory for the information of all previous players
        Info *allInfo=new Info[numInfo];//2
        //cout<<"Number of previous player is "<<(numInfo-1)<<endl;
        //when number of previous player is 0
        if(numInfo==1) {
            setInfo(n,p,e);
            setCoin(10);
            allInfo[0]=getInfo();
            wtFile(allInfo,numInfo);
            setNInf(numInfo);
        } else {  //there are previous players
            rdFile(allInfo,(numInfo-1));//1
            nmExist=false;
            pwWrong=false;
            //check this name exist or not
            for(int i=0;i<numInfo-1;i++) {
                //cout<<"#"<<i<<": "<<allInfo[i].name<<endl;
                //cout<<"#"<<i<<": "<<allInfo[i].coin<<endl;
                //if the name that player input exists in the information of all previous players
                if(n==allInfo[i].name) {
                    nmExist=true;
                    pwWrong=true;
                    if(nmExist) { //if the name exist
                        //use hash function to check the password correct or not
                        unsigned int hashpw=JSHash(p);
                        if(hashpw==allInfo[i].pw) {
                            pwWrong=false; //if the password is wrong
                            setInfo(n,p,e);
                            nCoin=allInfo[i].coin;
                        }
                    }
                    break;
                }
            }
            //if the name not exist in the list
            if(!nmExist) {
                setInfo(n,p,e);//set the name, password, and email address
                //get the coin
                setCoin(10);
                allInfo[numInfo-1]=getInfo();
                wtFile(allInfo,numInfo);
                cout<<"Sign up successfully"<<endl;
                //cout<<"Set the previous number of player is "<<numInfo<<endl;
                setNInf(numInfo);
            } else  { //name exist
                //password is correct
                if(!pwWrong) {
                    info.coin=nCoin;
                    cout<<"Sign in Successfully"<<endl;
                } else { //password is wrong
                    cout<<"Wrong name or wrong password"<<endl;
                }
                setNInf(--numInfo);
            }
        }
        delete []allInfo;
    } while(nmExist&&pwWrong);
    
    
}

//write the information to the file
void Player::wtFile(Info *info,int n) {
    fstream out;
    cout<<"Write all info to the file..."<<endl<<endl;
    out.open("Information.txt",ios::out|ios::binary);
    if(!out.fail()) {
       out.write(reinterpret_cast<char *>(info),sizeof(Info)*n); 
    }
    out.close();
}

//get the information from file
void Player::rdFile(Info *info,int n) {
    fstream in;
    cout<<"Read all info from the file..."<<endl<<endl;
    in.open("Information.txt",ios::in|ios::binary);
    if(!in.fail()) {
       in.read(reinterpret_cast<char *>(info),sizeof(Info)*n); 
    }
    in.close();
}

//renew the information
void Player::renewFl(string n,int c) {
    Info *infor=new Info[getNInf()];
    fstream in;
    cout<<"Read all info from the file..."<<endl;
    in.open("Information.txt",ios::in|ios::binary);
    if(!in.fail()) {
       in.read(reinterpret_cast<char *>(infor),sizeof(Info)*getNInf()); 
    }
    in.close();
    for(int i=0;i<getNInf();i++) {
        if(infor[i].name==n) {
            infor[i].coin=c;
            break;
        }
    }
    cout<<"Update "<<c<<" to the file"<<endl;
    fstream out;
    out.open("Information.txt",ios::out|ios::binary);
    if(!out.fail()) {
       out.write(reinterpret_cast<char *>(infor),sizeof(Info)*getNInf()); 
    }
    cout<<"Write all info to the file..."<<endl<<endl;
    out.close();
    
}

//set the info
void Player::setInfo(string n, string p, string e) {
    setName(n);
    setPW(p);
    setEm(e);
}

//set the password with hash function
void Player::setPW(string p) {
    info.pw=JSHash(p);
}

//get the number of previous players
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

//set the number of previous players
void Player::setNInf(int num) {
    fstream out;
    cout<<"Write number of previous player to the file..."<<endl;
    out.open("numOfPlayer.txt",ios::out);
    if(!out.fail()) {
       out<<num; 
    }
    out.close();
}



//print out the dices
void Player::pntDice() {
    cout<<"Yours: ";
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

//get the number of the dice called in all players' hands
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
    cout<<"The previous player is "<<getLBdr()<<endl;
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
        lastBdr=0;
        round++;
    }
}
