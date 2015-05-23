/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on May 22, 2015, 9:22 AM
 * Purpose: customer data
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#include "CustomerData.h"

int main(int argc, char** argv) {
    
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
    
    return 0;
}

