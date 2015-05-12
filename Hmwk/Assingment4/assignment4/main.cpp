/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on May 11, 2015, 10:33 PM
 * Purpose:Homework assignment4
 */

//System Library
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//user libraries
#include "Date.h"
#include "PayRoll.h"
#include "RetailItem.h"
#include "info.h"
#include "Inventory.h"
#include "Numbers.h"
#include "DayOfYear.h"
#include "DayOfYr.h"
#include "NumDays.h"
#include "FeetInches.h"

//Function prototypes
void pg1();//Gaddis_8thEd_Chap13_ProgChal1
void pg2();//Gaddis_8thEd_Chap13_ProgChal4
void pg3();//Gaddis_8thEd_Chap13_ProgChal5
void pg4();//Gaddis_8thEd_Chap13_ProgChal6
void pg5();//Gaddis_8thEd_Chap13_ProgChal11
void pg6();//Gaddis_8thEd_Chap14_ProgChal1
void pg7();//Gaddis_8thEd_Chap14_ProgChal2
void pg8();//Gaddis_8thEd_Chap14_ProgChal3
void pg9();//Gaddis_8thEd_Chap14_ProgChal4
void pg10();//Gaddis_8thEd_Chap14_ProgChal9

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    //declare variables
    string ans;
    int sel;
    do {    
        cout<<"**************Program Menu**************"<<endl;
        cout<<"1.  13.1"<<endl;
        cout<<"2.  13.4"<<endl;
        cout<<"3.  13.5"<<endl;
        cout<<"4.  13.6"<<endl;
        cout<<"5.  13.11"<<endl;
        cout<<"6.  14.1"<<endl;
        cout<<"7.  14.2"<<endl;
        cout<<"8.  14.3"<<endl;
        cout<<"9.  14.4"<<endl;
        cout<<"10. 14.9"<<endl;
        cout<<"0.Exit the program"<<endl;
        //select program
        bool invalid;
        do {
            invalid=false;
            cout<<"Please select the program(0 to 10)"<<endl;
            cin>>ans;
            if(ans.length()>2) {
                invalid=true;
                cout<<"Invalid input"<<endl;
            }
            if(ans.length()==1) {
                if(ans.at(0)<48||ans.at(0)>57) {
                    cout<<"Invalid input"<<endl;
                    invalid=true;
                }
            }
            if(ans.length()==2) {
                if(ans!="10") {
                    cout<<"Invalid input"<<endl;
                    invalid=true;
                }
            }
        }while(invalid);
        if(ans.length()==1) sel=static_cast<int>(ans.at(0)-48);
        if(ans.length()==2) sel=10;
        switch(sel) {
            case 1: pg1(); break;
            case 2: pg2(); break;
            case 3: pg3(); break;
            case 4: pg4(); break;
            case 5: pg5(); break;
            case 6: pg6(); break;
            case 7: pg7(); break;
            case 8: pg8(); break;
            case 9: pg9(); break;
            case 10: pg10(); break;
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

void pg1(){
    int year;
    int month;
    int day;
    bool invalid;
    int dyInMth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//day in months
    //Prompt user for year, month, and day
    cout<<"Please input a date"<<endl;
    cout<<"Year: ";
    cin>>year;
    do {
        cout<<"Month: ";
        cin>>month;
        if(month<1||month>12)
            cout<<"Invalid input"<<endl;
    }while(month<1||month>12);
    
    do {
        invalid=false;
        cout<<"Day: ";
        cin>>day;
        if(day<1||day>dyInMth[month])
            invalid=true;
        if(month==2&&day==29&&(year%400==0||(year%4==0&&year%100!=0)))
            invalid=false;
        if(invalid) cout<<"Invalid input"<<endl;
    }while(invalid);
    
    Date date(year,month,day);
    date.pntDate();//print out the day in format
    cout<<"Change the day to 1997/6/18"<<endl;
    date.setYear(1997);
    date.setMnth(6);
    date.setDay(18);
    date.pntDate();
}

void pg2(){
    //create 3 different object
    info me("Benjamin Ye","12345 15th st","6335245424",17);
    info uncle("Kelvin","54326 16th st","124165943",26);
    info cousin("Nick","1044 14th st","752824452",20);
    me.pntInfo();//print out my info
    me.setAge(18);//set my age to 18
    cout<<"Change the age to 18..."<<endl;
    me.pntInfo();//print mine again
    cousin.pntInfo();//print my cousin
    cout<<"Change the address..."<<endl;
    cousin.setAddr("1044 Spruce St");//change address
    cousin.pntInfo();//print again
    uncle.pntInfo();//print my uncle's
    cout<<"Change the number..."<<endl;
    uncle.setNum("6262559824");//change phone number
    uncle.pntInfo();//print again
}

void pg3(){
    //create 3 objects
    RetailItem item1("Jacket",12,59.95);
    RetailItem item2("Jeans",40,34.95);
    RetailItem item3("Shirt",20,24.95);
    //print in a table
    cout<<"Description"<<"   "<<"Units on hand"<<"   Price"<<endl;
    item1.pntItem();
    item2.pntItem();
    item3.pntItem();
    cout<<"Change the price of item1 to $67.89"<<endl;
    item1.setPric(67.89);
    cout<<"Change the number of unit of item2 to 70"<<endl;
    item2.setUnit(70);
    cout<<"Change the Description of item3"<<endl;
    item3.setDesc("Pants");
    cout<<"After changing the information of 3 items"<<endl<<endl;
    //print again
    cout<<"Description"<<"   "<<"Units on hand"<<"   Price"<<endl;
    item1.pntItem();
    item2.pntItem();
    item3.pntItem();
}

void pg4(){
    Inventory product(1064,5.5f,10);//declare a product
    product.pntInfo();//display the information 
    cout<<"After Changing the cost to $15..."<<endl;
    product.setCost(15.0f);//set the cost to $15
    product.pntInfo();//output again
    Inventory prod;//declare another product without argument
    prod.pntInfo();//display the information 
}

void pg5(){
    int size=7;//size of pay roll
    float p;//Hour pay rate
    int n;//number of working hour
    PayRoll *arr=new PayRoll[size];
    //print the empty file
    cout<<"Calling the Constructor 1"<<endl;
    for(int i=0;i<size;i++) {
        cout<<"#"<<(i+1)<<endl;
        arr[i].pntRsut();
    }
    cout<<"Please fill in..."<<endl;
    //prompt user to fill in
    for(int i=0;i<size;i++) {
        cout<<endl<<"#"<<(i+1)<<endl;
        cout<<"Hourly pay rate: $";
        cin>>p;
        cout<<"Hours worked: ";
        cin>>n;
        arr[i].setPyRt(p);
        arr[i].setWkHr(n);
    }
    //output the 7 pay roll
    cout<<"Output 7 pay roll..."<<endl;
    for(int i=0;i<size;i++) {
        cout<<endl<<"#"<<(i+1)<<endl;
        arr[i].pntRsut();
    }
    delete []arr;
}

void pg6(){
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    int n=rand()%10000;
    cout<<"Random number is "<<n<<endl;
    Numbers num(n);
    Numbers::print();
}

void pg7(){
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    int n=rand()%365+1;
    cout<<"Randomly choose a day"<<endl;
    cout<<"It is day #"<<n<<endl;
    
    DayOfYear dd(n);
    DayOfYear::print();
    
}

void pg8(){
    cout<<"Initial a day to Dec 31st"<<endl;
    DayOfYr dd("December",31);
    DayOfYr::print();
    cout<<endl<<"After using postfix ++"<<endl;
    dd++;
    DayOfYr::print();
    cout<<endl<<"After using prefix ++"<<endl;
    ++dd;
    DayOfYr::print();
    cout<<endl<<"After using postfix --"<<endl;
    dd--;
    DayOfYr::print();
    cout<<endl<<"After using prefix --"<<endl;
    --dd;
    DayOfYr::print();
}
void pg9(){
    NumDays aa(12);
    cout<<"First worker: "; 
    aa.pntDays();
    
    NumDays bb(20);
    cout<<"Second worker: "; 
    bb.pntDays();
    
    NumDays cc=aa+bb;
    cout<<"Third worker(1st+2nd): ";
    cc.pntDays();
    
    aa++;
    cout<<endl<<"After using postfix++ to 1st worker..."<<endl;
    aa.pntDays();
    
    bb--;
    cout<<endl<<"After using postfix-- to 2nd worker..."<<endl;
    bb.pntDays();
    
    ++aa;
    cout<<endl<<"After using prefix++ to 1st worker..."<<endl;
    aa.pntDays();
    
    --bb;
    cout<<endl<<"After using prefix-- to 2nd worker..."<<endl;
    bb.pntDays();
    
}

void pg10(){
    //declare 2 length
    FeetInches length1(1,4);
    cout<<"#1:";
    length1.pntLnth();
    FeetInches length2(2,4);
    cout<<"#2:";
    length2.pntLnth();
    if(length1<=length2) cout<<"length1<=length2"<<endl;
    cout<<endl<<"Change length 1 to 3 feet"<<endl;
    length1.setFeet(3);
    if(length1>=length2) cout<<"length1>=length2"<<endl;
    if(length1<=length2) cout<<endl<<"length1==length2"<<endl;
    else cout<<endl<<"They are not equal"<<endl;
}