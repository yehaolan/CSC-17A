/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 23, 2015, 12:54 PM
 * Purpose: Convert number to other types
 */

//System Libraries
#include <iostream>
#include <vector>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fromBin(int);
void fromOct(int);
void fromDec(int);
void fromHex(string);
void decToBi(int);
void decToOc(int);
void decToHe(int);
char conv(int);

//Execution begins here
int main(int argc, char** argv) {
    fromBin(1101011);
    cout<<endl<<endl;
    fromOct(234);
    cout<<endl<<endl;
    fromDec(987);
    cout<<endl<<endl;
    fromHex("4C");
    //Exit stage rights
    return 0;
}

void fromBin(int num) {
    //declare variables
    int rem;//remainder
    int dec=0;
    vector<int> sep;//store each digit of the number
    bool wrg=false;//wrong format
    while(num!=0) {
        rem=num%10;
        num/=10;
        if(rem>1) {
            wrg=true;
            break;
        } else {
            sep.push_back(rem);
        }
    }
    if(wrg) {
        cout<<"The number you input is wrong formatted"<<endl;
    } else {
        for(int i=0,mut=1;i<sep.size();i++,mut*=2) {
            dec+=sep[i]*mut;
        }
        cout<<"The number you input in decimal is "<<dec<<endl;
        decToOc(dec);
        decToHe(dec);
    }
}
void decToOc(int dec) {
    vector<int> sep;
    int oct=0;
    while(dec!=0) {
        sep.push_back(dec%8);
        dec/=8;
    }
    for(int i=0,mut=1;i<sep.size();i++,mut*=10){
        oct+=mut*sep[i];
    }
    cout<<"The number you input in octal is "<<oct<<endl;
}

void decToHe(int dec) {
    string hex="";
    vector<int> sep;
    while(dec!=0) {
        sep.push_back(dec%16);
        dec/=16;
    }
    for(int i=0;i<sep.size();i++) {
        hex=conv(sep[i])+hex;
    }
    cout<<"The number you input in hexadecimal is "<<hex<<endl;
}

void decToBi(int dec) {
    vector<int> sep;
    int bin=0;
    while(dec!=0) {
        sep.push_back(dec%2);
        dec/=2;
    }
    for(int i=0,mut=1;i<sep.size();i++,mut*=10){
        bin+=mut*sep[i];
    }
    cout<<"The number you input in binary is "<<bin<<endl;
}

char conv(int num) {
    if(num<10)
        return (num+48);
    else
        return (num+55);
}
void fromOct(int num) {
    //declare variables
    int rem;//remainder
    int dec=0;
    vector<int> sep;//store each digit of the number
    bool wrg=false;//wrong format
    while(num!=0) {
        rem=num%10;
        num/=10;
        if(rem>7) {
            wrg=true;
            break;
        } else {
            sep.push_back(rem);
        }
    }
    if(wrg) {
        cout<<"The number you input is wrong formatted"<<endl;
    } else {
        for(int i=0,mut=1;i<sep.size();i++,mut*=8) {
            dec+=sep[i]*mut;
        }
        cout<<"The number you input in decimal is "<<dec<<endl;
        decToBi(dec);
        decToHe(dec);
    }
}

void fromDec(int num) {
    decToBi(num);
    decToOc(num);
    decToHe(num);
}

void fromHex(string num) {
    bool wrg=false;
    int dec=0;
    vector<int> sep;
    for(int i=0;i<num.length();i++) {
        if(num.at(i)<48||(num.at(i)>57&&num.at(i)<65)||num.at(i)>70) {
            wrg=true;
            break;
        }
    }
    if(wrg) {
        cout<<"Invalid input"<<endl;
    } else {
        for(int i=num.length()-1;i>=0;i--) {
            if(num.at(i)>=48&&num.at(i)<=57)
                sep.push_back(num.at(i)-48);
            else
                sep.push_back(num.at(i)-55);
        }
        for(int i=0,mut=1;i<sep.size();i++,mut*=16) {
            dec+=sep[i]*mut;
        }
        cout<<"The number you input in decimal is "<<dec<<endl;
    }
    
}