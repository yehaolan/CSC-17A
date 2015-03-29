/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 25, 2015, 3:35 PM
 * Purpose: 10.4 Test Test
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int wordNum(char *);
int wordNum(string);

//Execution begins here
int main(int argc, char** argv) {
    char *arr=new char[1000];
    string str="";
    cout<<"Input sentence: ";
    getline(cin,str);
    
    cout<<"You input: "<<str<<endl;
    cout<<"The length is "<<str.length()<<endl;
    cout<<"The size is "<<str.size()<<endl;
    cout<<"The first digit is :"<<str.at(0)<<endl;
    cout<<"The number of words is "<<wordNum(str)<<endl;
    delete [] arr;
    arr=0;
    //cout<<"The last char is :"<<arr[strlen(arr)-1]<<endl;
    //Exit stage right
    return 0;
}

int wordNum(char *arr) {
    int wrdcnt=0;//count of the words
    bool isWord=false;
    for(int i=0;i<=strlen(arr);i++) {
        if(!isspace(arr[i]))
            isWord=true;
        if(isspace(arr[i])&&isWord) {
            wrdcnt++;
            isWord=false;
        }
    }
    if(!isspace(arr[strlen(arr)-1])) 
        wrdcnt++;    
    return wrdcnt;
}

int wordNum(string str) {
    int wrdcnt=0;//count of the words
    bool isWord=false;
    for(int i=0;i<str.length();i++) {
        if(!isspace(str.at(i)))
            isWord=true;
        if(isspace(str.at(i))&&isWord) {
            wrdcnt++;
            isWord=false;
        }
    }
    if(!isspace(str.at(str.length()-1)))
        wrdcnt++;    
    return wrdcnt;
}