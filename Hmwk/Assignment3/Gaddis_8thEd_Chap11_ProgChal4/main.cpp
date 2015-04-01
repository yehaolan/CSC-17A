/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 30, 2015, 11:35 AM
 * Purpose: 10.4 Weather Statistics
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Weather.h"

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    const int SIZE=3;
    Weather month[SIZE];
    //prompt user to fill in the weather
    for(int i=0;i<SIZE;i++) {
        cout<<"Month #"<<(i+1)<<": "<<endl;
        //get the total rainfall
        do {
            //Get the total rainfall
            cout<<"     Total Rainfall(mm): ";
            cin>>month[i].totRain;
            if(month[i].totRain<0)
                cout<<"**Invalid input**"<<endl;
        } while(month[i].totRain<0);
        //get the high temperature
        do {
            //Get the high temperature
            cout<<"     High temperature(F): ";
            cin>>month[i].hTemp;
            if(month[i].hTemp<-100||month[i].hTemp>140)
                cout<<"**Invalid input(out of range)**"<<endl;
        } while(month[i].hTemp<-100||month[i].hTemp>140);
        //get the low temperature
        do {
            //Get the total rainfall
            cout<<"     Low temperature(F): ";
            cin>>month[i].lTemp;
            if(month[i].lTemp<-100||month[i].lTemp>140)
                cout<<"**Invalid input(out of range)**"<<endl;
            if(month[i].lTemp>month[i].hTemp)
                cout<<"**Low temperature cannot greater than high temperature! Input again!**"<<endl;
        } while(month[i].lTemp<-100||month[i].lTemp>140||month[i].lTemp>month[i].hTemp);
        //calculate the average temperature
        month[i].aveTemp=0.5f*(month[i].hTemp+month[i].lTemp);
        
    }
    int yrRain=0;//total rainfall in a year
    float aveRain=0;//average rainfall each month
    float aveTem=0;//average temperature of each average temperature of all months
    int hgstTem=month[0].hTemp;//highest temperature
    int lwstTem=month[0].lTemp;//lowest temperature
    int ihg=0,ilw=0;//the index of month
    for(int i=0;i<SIZE;i++) {
        //sum all total rainfall
        yrRain+=month[i].totRain;
        aveTem+=month[i].aveTemp;//average temperature
        if(month[i].hTemp>hgstTem) {
            hgstTem=month[i].hTemp;
            ihg=i;
        } else if(month[i].lTemp<lwstTem) {
            lwstTem=month[i].lTemp;
            ilw=i;
        }
    }
    //calculate average temperature and average rainfall
    aveTem=static_cast<float>(aveTem)/SIZE;
    aveRain=static_cast<float>(yrRain)/SIZE;
    
    //output the results
    cout<<setprecision(2)<<fixed;
    cout<<"The average monthly rainfall(mm) is "<<aveRain<<endl;
    cout<<"The total rainfall(mm) for the year is "<<yrRain<<endl;
    cout<<"Highest temperature(F) is "<<hgstTem<<" in "<<"Month "<<"#"<<(ihg+1)<<endl;
    cout<<"Lowest temperature(F) is "<<lwstTem<<" in "<<"Month "<<"#"<<(ilw+1)<<endl;
    cout<<"The average of all the monthly average temperatures(F) is "<<aveTem<<endl;
    //Exit stage right
    return 0;
}

