/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 29, 2015, 2:35 PM
 * Purpose: 10.8 Sum of digits in a string
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    bool valid;//whether or not input is valid
    int sum=0;//sum of all digit
    string str;//string of digit
    //prompt user for numbers
    do {
        valid=true;
        cout<<"Input the number without separation: ";
        cin>>str;
        for(int i=0;i<str.length();i++) {
            if(str.at(i)<48||str.at(i)>57)
                valid=false;
        }
        if(!valid)
            cout<<"Invalid input"<<endl;
    }while(!valid);
    //sum all digit
    for(int i=0;i<str.length();i++) {
        sum+=static_cast<int>(str.at(i)-48);
    }
    //sort
    for(int i=0;i<str.length()-1;i++) {
        for(int j=i+1;j<str.length();j++) {
            if(str.at(i)<str.at(j)) {
                char temp=str.at(i);
                str.at(i)=str.at(j);
                str.at(j)=temp;
            }
        }
    }
    //output result
    cout<<"The sum of all the single digit numbers is "<<sum<<endl;
    cout<<"The sorted numbers(From highest to lowest is "<<str<<endl;
    
    //Exit stage right
    return 0;
}

