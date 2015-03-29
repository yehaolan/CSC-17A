/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 25, 2015, 3:35 PM
 * Purpose: 10.4 Number letter of words
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int wordNum(char *);

//Execution begins here
int main(int argc, char** argv) {
    char *arr=new char[1000];
    cout<<"Input sentence: ";
    cin.ignore();
    cin.getline(arr,1000);
    
    cout<<"You input: ";
    cout<<"The length is "<<strlen(arr)<<endl;
    cout<<"The number of words is "<<wordNum(arr)<<endl;
    delete [] arr;
    arr=0;
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
            cout<<"+1 in it"<<endl;
            isWord=false;
        }
    }
    if(!isspace(arr[strlen(arr)])) {
        cout<<"+1 in the end(1)"<<endl;
        wrdcnt++;
    } 
    if(isalnum(arr[strlen(arr)])) {
        cout<<"+1 in the end(2)"<<endl;
        wrdcnt++;
    }
    return wrdcnt;
}