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
    char *sen=new char[1000];//sentence with c-string
    //string sen;  //sentence with string
    float ave=0;//The average number of letters in each word
    vector<int> ltrNum;//vector to store the number of letters of each word
    
    //prompt user for sentence
    cout<<"Input sentence: ";
    cin.getline(sen,1000);
    //getline(cin,sen);
    
    //Output the result
    cout<<"The number of words is "<<wordNum(sen,ltrNum)<<endl;
    
    for(int i=0;i<ltrNum.size();i++) {
        ave+=ltrNum.at(i);
        //cout<<ltrNum.at(i)<<" ";
    }
    ave=ave/ltrNum.size();
    cout<<"The average number of letters in each word is "<<ave<<endl;
    delete [] sen;
    sen=0;
    
    //Exit stage right
    return 0;
}

//return number of words with c-string
int wordNum(char *arr,vector<int> &ltrNum) {
    int wrdCnt=0;//count of the words
    int ltrCnt=0;//count of number of letters in the word
    bool isWord=false;
    //loop for every letter
    for(int i=0;i<strlen(arr);i++) {
        //if it not space
        if(!isspace(arr[i])) {
            isWord=true;
            ltrCnt++;
        }
        //if it is space and previous one is word
        if(isspace(arr[i])&&isWord) {
            wrdCnt++;
            isWord=false;
            ltrNum.push_back(ltrCnt);
            ltrCnt=0;
        }
    }
    //if the last char is not space, number of word+1
    if(!isspace(arr[strlen(arr)-1])) {
        wrdCnt++; 
        ltrNum.push_back(ltrCnt);
    }
    return wrdCnt;
}

//return number of words with string
int wordNum(string str,vector<int> &ltrNum) {
    int wrdcnt=0;//count of the words
    int ltrCnt=0;//count of number of letters in the word
    bool isWord=false;
    //loop for every letter
    for(int i=0;i<str.length();i++) {
        //if it not space
        if(!isspace(str.at(i))) {
            isWord=true;
            ltrCnt++;
        }
        //if it is space and previous one is word
        if(isspace(str.at(i))&&isWord) {
            wrdcnt++;
            isWord=false;
            ltrNum.push_back(ltrCnt);
            ltrCnt=0;
        }
    }
    //if the last char is not space, number of word+1
    if(!isspace(str.at(str.length()-1))) {
        wrdcnt++;    
        ltrNum.push_back(ltrCnt);
    }
    return wrdcnt;
}