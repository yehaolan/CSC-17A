/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on May 22, 2015, 10:33 PM
 * Purpose:Homework assignment5
 */

//System libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//user libraries
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "MilTime.h"
#include "Essay.h"
#include "CustomerData.h"

//Function prototypes
void pg1();//Gaddis_8thEd_Chap15_ProgChal1
void pg2();//Gaddis_8thEd_Chap15_ProgChal2
void pg3();//Gaddis_8thEd_Chap15_ProgChal4
void pg4();//Gaddis_8thEd_Chap15_ProgChal6
void pg5();//Gaddis_8thEd_Chap15_ProgChal7
bool checkDay(int,int,int);

int main(int argc, char** argv) {
    //declare variables
    string ans;
    int sel;
    do {    
        cout<<"**************Program Menu**************"<<endl;
        cout<<"1.  15.1  Employee and ProductionWorker"<<endl;
        cout<<"2.  15.2  ShiftSupervisor"<<endl;
        cout<<"3.  15.4  Time Format"<<endl;
        cout<<"4.  15.6  Essay"<<endl;
        cout<<"5.  15.7  PersonData and CustomerData"<<endl;
        cout<<"0.Exit the program"<<endl;
        //select program
        bool invalid;
        do {
            invalid=false;
            cout<<"Please select the program(0 to 5)"<<endl;
            cin>>ans;
            if(ans.length()==1){
                if(ans.at(0)<'0'&&ans.at(0)>'5') invalid=true;
            } else invalid=true;
        }while(invalid);
        sel=static_cast<int>(ans.at(0)-48);
        switch(sel) {
            case 1: pg1(); break;
            case 2: pg2(); break;
            case 3: pg3(); break;
            case 4: pg4(); break;
            case 5: pg5(); break;
            case 0: {
                cout<<"This is the end of the program"<<endl;
                break;
            }
            default:;
        }
        if(sel!=0) {
            cout<<endl<<endl;
            cout<<"Press Enter to continue"<<endl;
            cin.ignore();
            cin.ignore();
        }
    }while(sel!=0);
    return 0;//If midterm not perfect, return something other than 1

}

void pg1() {
    //declare variables of worker
    string name;
    string id;
    int year;
    int month;
    int day;
    int shift;
    float pr;//pay rate
    bool invalid;//correct date
    //get the name and number
    cin.ignore();
    cout<<"Name: ";
    getline(cin,name);
    cout<<"Number: ";
    cin>>id;
    //get the hire date
    do {
        invalid=false;
        cout<<"Hire date(yy mm dd): ";
        cin>>year>>month>>day;
        invalid=checkDay(year,month,day);
        if(invalid) cout<<"Invalid date"<<endl;
    } while(invalid);
    //get shift
    do {
        cout<<"Shift(1 is day, 2 is night): ";
        cin>>shift;
        if(shift!=1&&shift!=2) cout<<"Invalid input"<<endl;
    }while(shift!=1&&shift!=2);
    //get pay rate
    do {
        cout<<"Hourly Pay Rate: $";
        cin>>pr;
        if(pr<0) cout<<"Invalid input"<<endl;
    }while(pr<0);
    
    //Test object
    ProductionWorker ben(name,id,year,month,day,shift,pr);
    cout<<"Worker information: "<<endl;
    ben.pntInfo();//print out info
}

void pg2() {
    //declare variables of worker
    string name;
    string id;
    int year;
    int month;
    int day;
    int annual;
    int bonus;
    bool invalid;//correct date
    //get the name and number
    cin.ignore();
    cout<<"Name: ";
    getline(cin,name);
    cout<<"Number: ";
    cin>>id;
    //get the hire date
    do {
        invalid=false;
        cout<<"Hire date(yy mm dd): ";
        cin>>year>>month>>day;
        invalid=checkDay(year,month,day);
        if(invalid) cout<<"Invalid date"<<endl;
    } while(invalid);
    //get annual salary
    do {
        cout<<"Annual Salary: $";
        cin>>annual;
        if(annual<0) cout<<"Invalid input"<<endl;
    }while(annual<0);
    
    //get Bonus
    do {
        cout<<"Bonus: $";
        cin>>bonus;
        if(bonus<0) cout<<"Invalid input"<<endl;
    }while(bonus<0);
    
    //Test object
    ShiftSupervisor ben(name,id,year,month,day,annual,bonus);
    cout<<endl<<"Worker information: "<<endl;
    ben.pntInfo();//print out info
    //reset annual salary and bonus
    ben.setAnn(100);
    ben.setBon(123);
    cout<<endl<<"Worker information after setting: "<<endl;
    ben.pntInfo();//print out info
}

void pg3() {
    int mh,ms;
    //get the military time to be changed
    cout<<"Time in military:"<<endl;
    do {
        cout<<"MilHour(2359 in milHour ->23:59 in standard): ";
        cin>>mh;
        if(mh<0||mh>2359||mh%100>59) cout<<"Invalid milHour"<<endl;
    }while(mh<0||mh>2359||mh%100>59);
    do {
        cout<<"MilSecond: ";
        cin>>ms;
        if(ms<0||ms>59) cout<<"Invalid milSecond"<<endl;
    }while(ms<0||ms>59);
    
    //Test
    MilTime mt(mh,ms);
    //Output standard hours
    cout<<mt.getStandHr()<<endl;
    cout<<"Reset the time..."<<endl;
    mt.setTime(1234,56);//set the hours
    //output again
    cout<<mt.getStandHr()<<endl;
}

void pg4() {
    int gram;
    int spel;
    int corL;
    int cont;
    cout<<"Points of Test: "<<endl;
    //Prompt user for the score of Essay
    do {
        cout<<"Grammar(30 points): ";
        cin>>gram;
        if(gram<0||gram>30) cout<<"Invalid grammar score"<<endl;
    } while(gram<0||gram>30);
    
    do {
        cout<<"Spelling(20 points): ";
        cin>>spel;
        if(spel<0||spel>20) cout<<"Invalid spelling score"<<endl;
    } while(spel<0||spel>20);
    
    do {
        cout<<"Correct length(20 points): ";
        cin>>corL;
        if(corL<0||corL>20) cout<<"Invalid length score"<<endl;
    } while(corL<0||corL>20);
    
    do {
        cout<<"Content(30 points): ";
        cin>>cont;
        if(cont<0||cont>30) cout<<"Invalid content score"<<endl;
    } while(cont<0||cont>30);
    
    //declare a Essay Object
    Essay ee(gram,spel,corL,cont);
    cout<<"He/She got "<<ee.getScore()<<"    "<<ee.getLetterGrade();
}

void pg5() {
    string lastNm;//last name
    string firstNm;//first name
    string address;
    string city;
    string state;
    string phone;
    string zip;
    bool mailList;
    //prompt user for the information
    cout<<"Last name: ";
    cin>>lastNm;
    cout<<"First name: ";
    cin>>firstNm;
    cin.ignore();
    cout<<"Address: ";
    getline(cin,address);
    cout<<"City: ";
    getline(cin,city);
    cout<<"State: ";
    cin>>state;
    cout<<"Phone: ";
    cin>>phone;
    cout<<"ZIP: ";
    cin>>zip;
    cout<<"Mailing list(0 for false,otherwise it is for true): ";
    cin>>mailList;
    //test the object
    CustomerData pp(lastNm,firstNm,address,city,state,zip,phone,mailList);
    pp.pntInfo();
}

bool checkDay(int y,int m,int d) {
    bool invalid=false;
    if(m<1||m>12) return true;
    int dyInMth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(d<1||d>dyInMth[m])
            invalid=true;
    if(m==2&&d==29&&(y%400==0||(y%4==0&&y%100!=0)))
            invalid=false;
    return invalid;
}