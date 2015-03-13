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
void fromBin(int);//Input with binary
void fromOct(int);//Input with octonary
void fromDec(int);//Input with decimal
void fromHex(string);//Input with hexadecimal
void decToBi(int);//decimal to binary
void decToOc(int);//decimal to octonary
void decToHe(int);//decimal to hexadecimal
char conv(int);//Convert a 1-digit number to char

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    int choice;//choice to convert
    string str;//number user want to convert for hexadecimal
    int num;//number user want to convert for other 3 types
    do {
        //Prompt user for choice of convert
        do {
            cout<<"   This program can convert a number between "<<endl;
            cout<<"   Binary, octonary, decimal, and hexadecimal"<<endl;
            cout<<"  Once you input a number with one of four type"<<endl;
            cout<<" We can convert this number to other three type"<<endl;
            cout<<"  Which type of number you would like to input?"<<endl;
            cout<<"1.Binary"<<endl;
            cout<<"2.Octonary"<<endl;
            cout<<"3.Decimal"<<endl;
            cout<<"4.Hexadecimal"<<endl;
            cout<<"5.Exit the program"<<endl;
            cin>>choice;
            if(choice<1||choice>5)
                cout<<"Invalid input"<<endl<<endl;
        }while(choice<1||choice>5);
        //Prompt user for number
        if(choice!=5) {
            if(choice>=1&&choice<=3) {
                cout<<"Input the number you would like to input"<<endl;
                cin>>num;
            } else if(choice==4){
                cout<<"Input the number you would like to input"<<endl;
                cin>>str;
            }
            switch(choice) {
                case 1: fromBin(num); break;
                case 2: fromOct(num); break;
                case 3: fromDec(num); break;
                case 4: fromHex(str); break;
                default:;
            }
            cout<<"Press Enter to continue"<<endl;
            cin.ignore();
            cin.ignore();
        } else {
            cout<<"This is the end of the program"<<endl;
        }
    }while(choice!=5);
    //Exit stage rights
    return 0;
}

//Input with binary
void fromBin(int num) {
    //declare variables
    int rem;//remainder
    int dec=0;//result of conversion
    vector<int> sep;//store each digit of the number
    bool wrg=false;//wrong format
    //Check whether the number is correct input, if yes, save each digit to vector
    while(num!=0) {
        rem=num%10;//separate each digit
        num/=10;
        if(rem>1) { //means invalid input
            wrg=true;
            break;
        } else { //correct input
            sep.push_back(rem);//save to vector
        }
    }
    if(wrg) {
        cout<<"Invalid input"<<endl;
    } else {
        //calculate the result of changing to decimal
        for(int i=0,mut=1;i<sep.size();i++,mut*=2) {
            dec+=sep[i]*mut;
        }
        //Output decimal result
        cout<<"The number you input in decimal is "<<dec<<endl;
        decToOc(dec);//convert decimal result to octonary
        decToHe(dec);//convert decimal result to hexadecimal
    }
}

//decimal to binary
void decToBi(int dec) {
    vector<int> sep;
    string res="";//result
    while(dec!=0) {
        sep.push_back(dec%2);
        dec/=2;
    }
    for(int i=0;i<sep.size();i++){
        res=static_cast<char>(sep[i]+48)+res;
    }
    cout<<"The number you input in binary is "<<res<<endl;
}

//decimal to octonary
void decToOc(int dec) {
    vector<int> sep;
    string res="";//result
    while(dec!=0) {
        sep.push_back(dec%8);
        dec/=8;
    }
    for(int i=0;i<sep.size();i++){
        res=static_cast<char>(sep[i]+48)+res;
    }
    cout<<"The number you input in octonary is "<<res<<endl;
}

//decimal to hexadecimal
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

//Convert a 1-digit number to char
char conv(int num) {
    if(num<10)
        return (num+48);
    else
        return (num+55);
}

//Input with octonary
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

//Input with decimal
void fromDec(int num) {
    decToBi(num);
    decToOc(num);
    decToHe(num);
}

//Input with hexadecimal
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
    decToBi(dec);
    decToOc(dec);
}