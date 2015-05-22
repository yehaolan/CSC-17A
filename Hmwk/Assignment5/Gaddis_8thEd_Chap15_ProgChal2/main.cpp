/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on May 22, 2015, 8:08 AM
 * Purpose: ShiftSupervisor
 */

#include <iostream>
#include <string>
using namespace std;

#include "ShiftSupervisor.h"

bool checkDay(int,int,int);

int main(int argc, char** argv) {
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
    return 0;
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

