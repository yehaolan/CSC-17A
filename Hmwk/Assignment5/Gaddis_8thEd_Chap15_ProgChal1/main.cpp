/* 
 * File:   main.cpp
 * Author: Haolan Ye
 * Created on May 17, 2015, 8:40 AM
 * Purpose: Worker
 */

#include <iostream>
#include <string>
using namespace std;

#include "ProductionWorker.h"

bool checkDay(int,int,int);

int main(int argc, char** argv) {
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