/* 
 * File:   main.cpp
 * Author: Haolan Ye
 *
 * Created on May 9, 2015, 8:11 PM
 */

#include <iostream>
using namespace std;

#include "PayRoll.h"

int main(int argc, char** argv) {
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
    return 0;
}

