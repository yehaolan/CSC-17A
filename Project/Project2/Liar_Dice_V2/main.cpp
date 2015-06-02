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
Player *cretPyr(int);//create player and roll dice
char *rolDice(int);//roll 5 dices
void dspDice(Player *);//display dice of a player
void chalng(Player,int &,int);//Player challenge
void bid(Player &,char &,int &,int,int &,int,bool &);//First player(you)
void AIBid(int,Player &,char &,int &,int &,bool);//AI's turn
void AIChalg(int &,Player,char,int,int,int,bool);//AI challenge
int getQuan(Player,char,bool);//get the quantity of that face of dice in one AI's hand
vector<char> getNtEs(char *);//get the dices that not exist one AI's hand
vector<char> getEs(char *);//get the dices that exist one AI's hand
char getMtFr(char *);//get the most frequent face of dices in one AI's hand
void result(int,char,int,Player *,int,bool);//Determine who win and lost
void wtFile(Player *,int);//write the array of Player into file
void rdFile(Player *,int);//read the file 

//Execution begins here
int main(int argc, char** argv) {
    /*
    //set seed for rolling dice
    srand(static_cast<unsigned int>(time(0)));
    int numPyr;//number of player
    int round=0;//round of the game
    int open=-1;//open=-1 -> not open; =0 -> player1 open; =1 -> player2 open etc.
    bool wild=true;//1 is wild, when after bidding 1s or bidding only 3 5s,then 1 is not wild
    string input;//temp for input
    cout<<"Welcome to Liar Dice"<<endl<<endl;
    //Prompt user for number of player
    do {
        cout<<"Number of player(2(Easy) or 3(Hard)): ";
        cin>>input;
        if(input!="2"&&input!="3")
            cout<<"Invalid input"<<endl;
    } while(input!="2"&&input!="3");
    numPyr=(input=="2"?2:3);
    //create players and roll dices
    Player *players=cretPyr(numPyr);
    Player *copy=new Player[numPyr];//create for reading file
    wtFile(players,numPyr);//write all the players into file
    //Initialize based on the number of player
    char face='0';//initial the face to 0
    int num=numPyr*3/2;//initial the number to 1.5*number of player
    dspDice(players);//display your dice
    //game begins
    int temp=rand()%numPyr;//randomly select who is the first to bid
    //run until somebody challenges
    do {
        switch(temp) {
            case 0: {
                chalng(players[0],open,round);//player challenge
                if(numPyr==3) AIChalg(open,players[1],face,num,numPyr,round,wild);//AI #2 challenge
                bid(players[0],face,num,numPyr,round,open,wild);//player bid
            }
            case 1: {
                AIChalg(open,players[1],face,num,numPyr,round,wild);//AI #1 challenge
                if(numPyr==3) AIChalg(open,players[2],face,num,numPyr,round,wild);//AI #2 challenge
                AIBid(open,players[1],face,num,round,wild);//AI #1 bid
            }
            case 2: {
                if(numPyr==3) {
                    chalng(players[0],open,round);//Player challenge
                    AIChalg(open,players[2],face,num,numPyr,round,wild);//AI #2 challenge
                    AIBid(open,players[2],face,num,round,wild);//AI #2 bid
                }
            }
        }
        temp=0;
    } while(open==-1);
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
    //Exit stage right
    */
    int open=-1;
    Player p1;
    Player p2;
    AI a;
    p1.init();
    cout<<"Round: #"<<p1.getRond()<<endl;
    cout<<"Wild: "<<p1.getWild()<<endl;
    cout<<"Number of player: "<<p1.getNumP()<<endl;
    cout<<p1.getFace()<<endl;
    cout<<p1.getNum()<<endl;
    p1.pntDice();
    
    cout<<endl;
    cout<<"Number of AI: "<<a.getNAI()<<endl;
    
    cout<<"Number of player: "<<p1.getNumP()<<endl;
    cout<<"AI's dices:"<<endl;
    a.pntDice();
    a.pntEs();
    a.pntNtEs();
    return 0;
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

//roll dices and save in char array
char *rolDice(int n) {
    //allocate memory
    char *dices=new char[n];
    //randomly roll the dice
    for(int i=0;i<n;i++) {
        dices[i]=static_cast<char>(rand()%6+1+48);
    }
    return dices;
}

//output the dices of a player
void dspDice(Player *p) {
    if(p->order==0) cout<<endl<<"Your    ";
    else cout<<"AI #"<<p->order<<"'s ";
    cout<<"dice: ";
    for(int i=0;i<5;i++) {
        cout<<p->dices[i]<<" ";
    }
    cout<<endl;
}

void chalng(Player p,int &open,int r) {
    string ans="N";//answer of open or not
    //prompt user for challenge or not
    if(r!=0&&open==-1) {
        do {
            cout<<"Would you like to challenge?(Y or N): ";
            cin>>ans;
            if(ans!="Y"&&ans!="N"&&ans!="y"&&ans!="n") 
                cout<<"Invalid input"<<endl;
        } while(ans!="Y"&&ans!="N"&&ans!="y"&&ans!="n");
    }
    //when answer is open
    if(ans=="Y"||ans=="y") {
        open=p.order; //set open to true
        cout<<"You Challenge"<<endl;
    }
}

void bid(Player &p,char &face,int &num,int numPyr,int &r,int open,bool &w) {
    string bid;
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
            if(r<=2) {
            cout<<"Your bidding: ";
            cout<<"format:\"3 4\"(means u bid 3 4s,and 1s are wild) or \"4n5\"(means you bid 4 5s only, and 1s are not wild)"<<endl;
            cout<<"First bid must be >= 1.5*players"<<endl;
            }
            cout<<"Your bidding: ";
            getline(cin,bid);//1st element is number of dice,2nd is space or n,3rd is face of dice
            //check the input valid or not
            if(bid.length()!=3&&bid.length()!=4) invalid=true;//length only 3 or 4
            if(bid.length()==3||bid.length()==4) {
                for(int i=0;i<bid.length();i++) {  
                    if(i==bid.length()-2) {
                        if(bid.at(i)!=' '&&bid.at(i)!='n'&&bid.at(i)!='N') invalid=true;
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
        if(bid.at(bid.length()-2)=='n'||bid.at(bid.length()-2)=='N') w=false;
        if(bid.at(bid.length()-1)=='1') w=false;
        cout<<"You bid "<<num<<"  "<<face<<"s";
        if(w) cout<<" "<<endl;
        else cout<<" only"<<endl;
        r++;
    }
}

void AIChalg(int &open,Player p,char face,int num,int numPyr,int r,bool w) {
    if(r!=0&&open==-1) {
        //determine challenge or not
        if(w) {
            if(getQuan(p,face,w)>=num) open=-1; //when bided number of a kind dice <= AI's, not challenge 
            else if(getQuan(p,face,w)==0&&num>=numPyr*2) open=p.order;
            else if(getQuan(p,face,w)==1&&num-1>(numPyr-1)*2) {
                if(rand()%6<3) open=p.order; //50% to open
            } else if(getQuan(p,face,w)==2&&num-2>(numPyr-1)*2) {
                if(rand()%6<2) open=p.order; //1/3 to open
            } else if(getQuan(p,face,w)==3&&num-3>(numPyr-1)*2) {
                if(rand()%6<2) open=p.order; //1/3 to open
            } else if(getQuan(p,face,w)>=4&&num-getQuan(p,face,w)>(numPyr-1)*2) {
                open=p.order; // 100% to open
            }
            if(num>=numPyr*3) {
                if(num>=numPyr*4) open=p.order;
                else {
                    if(rand()%5<4) open=p.order;
                }
            }
        } else {
            if(num-getQuan(p,face,w)>=2*(numPyr-1)) open=p.order;
        }
        if(open==p.order) cout<<"AI #"<<p.order<<" challenge"<<endl;
        else cout<<"AI #"<<p.order<<" does not challenge"<<endl;
    }
}

void AIBid(int open,Player &p,char &face,int &num,int &r,bool w) {
    //bid
    if(open==-1) {
        char faceTem;
        if(w) {
            vector<char> nExist=getNtEs(p.dices);
            //truth 3/5
            if(rand()%5>=2||(nExist.size()==1&&nExist[0]=='1')) {  
                if(rand()%3<2&&face==getMtFr(p.dices))  { //get the most frequent face of of AI's dices
                    faceTem=face;
                } else { //randomly get a dice from existed dices
                    vector<char> exist=getEs(p.dices);

                    do {
                        faceTem=exist[rand()%exist.size()];
                    } while(faceTem=='1');
                }

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
        } else {
            face=getMtFr(p.dices);
            if(faceTem<=face) num++;
        }
        cout<<"AI #"<<p.order<<" bid "<<num<<"  "<<face<<"s";
        if(w) cout<<" "<<endl;
        else cout<<" only"<<endl;
        r++;
    }
}

//get the quantity of one face of dice of one player
int getQuan(Player p,char face,bool w) { 
    int num=0;
    int ones=0;
    for(int i=0;i<5;i++) {
        if(p.dices[i]==face) num++;
        if(w&&face!='1'&&p.dices[i]=='1') ones++;
        //when 1 is not wild
    }
    return num+ones;
}

//get the faces of dice that doesn't exist in AI's hand
vector<char> getNtEs(char *dices) {
    vector<char> nExist;//not exist face of dice
    //initialize 6 elements from 1 to 6
    for(int i=1;i<=6;i++) {
        nExist.push_back(i+48);
    }
    //when the face of the dices comes up, set that face in the vector to 0
    for(int i=0;i<5;i++) {
        nExist[static_cast<int>(dices[i]-48)-1]='0';
    }
    //sort the vector form high to low
    for(int i=0;i<5;i++) {
        for(int j=i+1;j<6;j++) {
            if(nExist[i]<nExist[j]) {
                char temp=nExist[i];
                nExist[i]=nExist[j];
                nExist[j]=temp;
            }
        }
    }
    //take out the existing number
    for(int i=5;i>=0;i--) {
        if(nExist[i]=='0') nExist.pop_back();
    }
    return nExist;//return the vector
}

//get the faces of dice that exist in AI's hand
vector<char> getEs(char *dices) {
    bool inside;
    vector<char> exist;
    for(int i=0;i<5;i++) {
        inside=false;
        //use for loop to get the existing dices
        for(int j=0;j<exist.size();j++) {
            if(exist[j]==dices[i]) inside=true;
        }
        if(!inside) exist.push_back(dices[i]);
    }
    return exist;
}

//get the most frequent face of dice in the dices
char getMtFr(char *dices) {
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

//print out the result
void result(int num,char face,int numPyr,Player *players,int open,bool w) {
    int total=0;
    //count the face of all players
    for(int i=0;i<numPyr;i++) {
        total+=getQuan(players[i],face,w);
    }
    cout<<endl<<"Totally, there are "<<total<<" "<<face<<"s"<<endl;
    if(total>=num) {
        if(open==0) cout<<"Your challenge failed"<<endl;
        else cout<<"AI #"<<open<<"'s challenge failed"<<endl;
    } else {
        if(open==0) cout<<"Your challenge succeed"<<endl;
        else cout<<"AI #"<<open<<"'s challenge succeed"<<endl;
    }
}
*/