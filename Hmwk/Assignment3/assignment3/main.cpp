/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 3, 2015, 10:33 AM
 * Purpose:Homework assignment2
 */

//System libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User libraries
#include "Weather.h"

//Global Constants

//Function prototypes
void pg1();//Gaddis_8thEd_Chap10_ProgChal4
void pg2();//Gaddis_8thEd_Chap10_ProgChal6
void pg3();//Gaddis_8thEd_Chap10_ProgChal8
void pg4();//Gaddis_8thEd_Chap11_ProgChal4
void pg5();//Gaddis_8thEd_Chap11_ProgChal9
void pg6();//Gaddis_8thEd_Chap11_ProgChal12
void pg7();//Gaddis_8thEd_Chap12_ProgChal7
void pg8();//Gaddis_8thEd_Chap9_ProgChal8
void pg9();//Gaddis_8thEd_Chap9_ProgChal11
void pg10();//Gaddis_8thEd_Chap9_ProgChal9&10
int wordNum(char *,vector<int> &);
int wordNum(string,vector<int> &);
int vwCount(char *);//count vowel
int csCount(char *);//count consonant

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    string ans;
    int sel;
    do {    
        cout<<"**************Program Menu**************"<<endl;
        cout<<"1.  10.4 Number letter of words"<<endl;
        cout<<"2.  10.6 Vowels and Consonants"<<endl;
        cout<<"3.  10.8 Sum of digits in a string"<<endl;
        cout<<"4.  11.4 Weather Statistics"<<endl;
        cout<<"5.  11.9"<<endl;
        cout<<"6.  11.12"<<endl;
        cout<<"7.  12.7"<<endl;
        cout<<"8.  12.8"<<endl;
        cout<<"9.  12.11"<<endl;
        cout<<"10. 12.9&10"<<endl;
        cout<<"0.Exit the program"<<endl;
        //select program
        bool invalid;
        do {
            invalid=false;
            cout<<"Please select the program(0 to 10)"<<endl;
            cin>>ans;
            if(ans.length()>2) {
                invalid=true;
                cout<<"Invalid input"<<endl;
            }
            if(ans.length()==1) {
                if(ans.at(0)<48||ans.at(0)>57) {
                    cout<<"Invalid input"<<endl;
                    invalid=true;
                }
            }
            if(ans.length()==2) {
                if(ans!="10") {
                    cout<<"Invalid input"<<endl;
                    invalid=true;
                }
            }
        }while(invalid);
        if(ans.length()==1) sel=static_cast<int>(ans.at(0)-48);
        if(ans.length()==2) sel=10;
        switch(sel) {
            case 1: pg1(); break;
            case 2: pg2(); break;
            case 3: pg3(); break;
            case 4: pg4(); break;
            case 5: pg5(); break;
            case 6: pg6(); break;
            case 7: pg7(); break;
            case 8: pg8(); break;
            case 9: pg9(); break;
            case 10: pg10(); break;
            case 0: {
                cout<<"This is the end of the program"<<endl;
                break;
            }
            default:;
        }
        if(sel!=0) {
            cout<<endl<<endl;
            cout<<"Press Enter to continue";
            cin.ignore();
        }
    }while(sel!=0);



    return 0;
}

//Gaddis_8thEd_Chap10_ProgChal4
void pg1() {
    char *sen=new char[1000];//sentence with c-string
    //string sen;  //sentence with string
    float ave=0;//The average number of letters in each word
    vector<int> ltrNum;//vector to store the number of letters of each word
    
    cout<<"Welcome to Word Counter"<<endl;
    cout<<"Press Enter to continue..."<<endl;
    cin.ignore();
    cin.ignore();
    //prompt user for sentence
    cout<<"Input sentence: ";
    cin.getline(sen,1000);
    //getline(cin,sen);
    
    //Output the result
    cout<<"The number of words is "<<wordNum(sen,ltrNum)<<endl;
    
    //calculate the number of letter
    for(int i=0;i<ltrNum.size();i++) {
        ave+=ltrNum.at(i);
        //cout<<ltrNum.at(i)<<" ";
    }
    //get the average 
    ave=ave/ltrNum.size();
    cout<<"The average number of letters in each word is "<<ave<<endl;
    delete [] sen;
    sen=0;
}

//Gaddis_8thEd_Chap10_ProgChal6
void pg2() {
    cout<<"Welcome to counter of vowels and consonants"<<endl;
    //allocate the dynamic array
    char *arr=new char[1000];//sentence with c-string

    //prompt user for sentence
    cout<<"Input sentence: ";
    cin.ignore();
    cin.getline(arr,1000);

    //output the result
    cout<<"The length is "<<strlen(arr)<<endl;
    cout<<"The number of vowel is "<<vwCount(arr)<<endl;
    cout<<"The number of consonant is "<<csCount(arr)<<endl;
    
    delete [] arr;
    arr=0;
}

//Gaddis_8thEd_Chap10_ProgChal8
void pg3() {
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
    cin.ignore();
}

//Gaddis_8thEd_Chap11_ProgChal4
void pg4() {
    
}

//Gaddis_8thEd_Chap11_ProgChal9
void pg5() {
    
}

//Gaddis_8thEd_Chap11_ProgChal12
void pg6() {
    
}

//Gaddis_8thEd_Chap12_ProgChal7
void pg7() {
   
}

//Gaddis_8thEd_Chap12_ProgChal8
void pg8() {
    
}

//Gaddis_8thEd_Chap12_ProgChal11
void pg9() {
    
}

//Gaddis_8thEd_Chap12_ProgChal9&10
void pg10() {
    
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

int vwCount(char *arr) {
    int count=0;//counter
    for(int i=0;i<strlen(arr);i++) {
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||
           arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U')  {
            count++;
        }
    }
    return count;
}

int csCount(char *arr) {
    int count=0;//counter
    for(int i=0;i<strlen(arr);i++) {
        //when char is in alphabet
        if(isalpha(arr[i])) {
            if(!(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||
               arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U'))  {
                count++;
            }
        }
    }
    return count;
}