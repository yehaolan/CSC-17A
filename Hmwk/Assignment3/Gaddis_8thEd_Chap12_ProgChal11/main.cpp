/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on April 2, 2015, 3:32 PM
 * Purpose: 12.11 Corporate Sales Data Output
 */

//system libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

//User Libraries
#include "Sales.h"

//global Constants

//Function Prototypes
Sales *filDiv(int);

//Execution begins here
int main(int argc, char** argv) {
    fstream out;
    out.open("Data.dat",ios::out|ios::binary);
    //allocate memory
    Sales *div=filDiv(16);
    //prompt user for each quarter sales
    for(int i=0;i<16;i++) {
        do {
            cout<<div[i].name<<"(quarter "<<div[i].quarter<<"): ";
            cin>>div[i].qrtSale;
            if(div[i].qrtSale<0)
                cout<<"Invalid input"<<endl;
        } while(div[i].qrtSale<0);
    }
    //write into file
    if(!out.fail()) {
        out.write()
    }
    for(int i=0;i<16;i++) {
        cout<<div[i].name<<" ";
        if(i%4==3) cout<<endl;
    }
    out.close;
    //deallocate memory
    delete [] div;
    div=0;
    //Exit stage right
    return 0;
}

//fill the name and quarter automatically
Sales *filDiv(int n) {
    Sales *div=new Sales[n];
    //element 0-3 is South, 4-7 West, 8-11 North, 12-15 South
    for(int i=0;i<n;i++) {
        if(i<4) div[i].name="East";
        else if(i<8) div[i].name="West";
        else if(i<12) div[i].name="North";
        else if(i<16) div[i].name="South";
        if(i%4==0) div[i].quarter=1;
        else if(i%4==1) div[i].quarter=2;
        else if(i%4==2) div[i].quarter=3;
        else if(i%4==3) div[i].quarter=4;
        
    }
    return div;
}