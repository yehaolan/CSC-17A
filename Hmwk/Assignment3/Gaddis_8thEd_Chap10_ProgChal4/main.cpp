/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 25, 2015, 3:35 PM
 * Purpose: 10.4 Number letter of words
 */

//System Libraries
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int wordNum(char *,vector<int> &);
int wordNum(string,vector<int> &);

//Execution begins here
int main(int argc, char** argv) {
    //char *sen=new char[1000];//sentence with c-string
    string sen;  //sentence with string
    float ave=0;
    vector<int> ltrNum;
    
    //prompt user for sentence
    cout<<"Input sentence: ";
    //cin.getline(sen,1000);
    getline(cin,sen);
    
    //Output the result
    //cout<<"(With c-string) The number of words is "<<wordNum(sen,ltrNum)<<endl;
    cout<<"(With string) The number of words is "<<wordNum(sen,ltrNum)<<endl;
    
    for(int i=0;i<ltrNum.size();i++) {
        ave+=ltrNum.at(i);
        //cout<<ltrNum.at(i)<<" ";
    }
    ave=ave/ltrNum.size();
    cout<<"The average number of letters in each word is "<<ave<<endl;
    //delete [] sen;
    //sen=0;
    
    //Exit stage right
    return 0;
}

int wordNum(char *arr,vector<int> &ltrNum) {
    int wrdCnt=0;//count of the words
    int ltrCnt=0;//count of number of letters in the word
    bool isWord=false;
    for(int i=0;i<strlen(arr);i++) {
        if(!isspace(arr[i])) {
            isWord=true;
            ltrCnt++;
        }
        if(isspace(arr[i])&&isWord) {
            wrdCnt++;
            isWord=false;
            ltrNum.push_back(ltrCnt);
            ltrCnt=0;
        }
    }
    if(!isspace(arr[strlen(arr)-1])) {
        wrdCnt++; 
        ltrNum.push_back(ltrCnt);
    }
    return wrdCnt;
}

int wordNum(string str,vector<int> &ltrNum) {
    int wrdcnt=0;//count of the words
    int ltrCnt=0;//count of number of letters in the word
    bool isWord=false;
    for(int i=0;i<str.length();i++) {
        if(!isspace(str.at(i))) {
            isWord=true;
            ltrCnt++;
        }
        if(isspace(str.at(i))&&isWord) {
            wrdcnt++;
            isWord=false;
            ltrNum.push_back(ltrCnt);
            ltrCnt=0;
        }
    }
    if(!isspace(str.at(str.length()-1))) {
        wrdcnt++;    
        ltrNum.push_back(ltrCnt);
    }
    return wrdcnt;
}