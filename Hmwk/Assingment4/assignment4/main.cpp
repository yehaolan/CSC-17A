/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on May 11, 2015, 10:33 PM
 * Purpose:Homework assignment4
 */

//Library includes Here!!!
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
    int dyInMth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
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
    date.pntDate();
    cout<<"Change the day to 1997/6/18"<<endl;
    date.setYear(1997);
    date.setMnth(6);
    date.setDay(18);
    date.pntDate();
}

void pg2(){
    info me("Benjamin Ye","12345 15th st","6335245424",17);
    info uncle("Kelvin","54326 16th st","124165943",26);
    info cousin("Nick","1044 14th st","752824452",20);
    me.pntInfo();
    me.setAge(18);
    cout<<"Change the age to 18..."<<endl;
    me.pntInfo();
    cousin.pntInfo();
    cout<<"Change the address..."<<endl;
    cousin.setAddr("1044 Spruce St");
    cousin.pntInfo();
    uncle.pntInfo();
    cout<<"Change the number..."<<endl;
    uncle.setNum("6262559824");
    uncle.pntInfo();
}

void pg3(){
    RetailItem item1("Jacket",12,59.95);
    RetailItem item2("Jeans",40,34.95);
    RetailItem item3("Shirt",20,24.95);
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
    int size=7;
    float p;
    int n;
    PayRoll *arr=new PayRoll[size];
    cout<<"Calling the Constructor 1"<<endl;
    for(int i=0;i<size;i++) {
        cout<<"#"<<(i+1)<<endl;
        arr[i].pntRsut();
    }
    cout<<"Please fill in..."<<endl;
    for(int i=0;i<size;i++) {
        cout<<endl<<"#"<<(i+1)<<endl;
        cout<<"Hourly pay rate: $";
        cin>>p;
        cout<<"Hours worked: ";
        cin>>n;
        arr[i].setPyRt(p);
        arr[i].setWkHr(n);
    }
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
        cout<<"In pg # 7"<<endl<<endl;
}

void pg8(){
        cout<<"In pg # 8"<<endl<<endl;
}
void pg9(){
        cout<<"In pg # 9"<<endl<<endl;
}

void pg10(){
        cout<<"In pg # 10"<<endl<<endl;
}