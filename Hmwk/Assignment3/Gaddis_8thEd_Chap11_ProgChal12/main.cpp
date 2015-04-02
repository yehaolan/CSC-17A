/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 31, 2015, 11:35 PM
 * Purpose: 10.12 Course grade
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Class.h"

//Global Constants

//Function Prototypes
void pntScro(Class);

//Execution begins here
int main(int argc, char** argv) {
    int tstNum,//the number of test
        stuNum;//the number of student
    //prompt user for the number of test
    do {
        cout<<"The number of test: ";
        cin>>tstNum;
        if(tstNum<1)
            cout<<"Invalid input"<<endl;
    } while(tstNum<1);
    //prompt user for the number of student
    do {
        cout<<"The number of student: ";
        cin>>stuNum;
        if(stuNum<1)
            cout<<"Invalid input"<<endl;
    } while(stuNum<1);
    
    //dynamic allocate memory
    Class *stud=new Class[stuNum];
    
    for(int i=0;i<stuNum;i++) {
        stud[i].score=new int[tstNum];//allocate the test array
        bool valid;
        cout<<endl<<"Student #"<<(i+1)<<": "<<endl;
        
        //get the name
        cout<<"Name"<<": ";
        cin.ignore();
        getline(cin,stud[i].name);
        
        //get the id number
        do {
            valid=true;
            cout<<"Student ID: ";
            cin>>stud[i].id;
            //check the phone number
            for(int i=0;i<stud[i].id.length();i++) {
                if(stud[i].id.at(i)<48||stud[i].id.at(i)>57)
                    valid=false;
            }
            if(!valid)
                cout<<"Invalid input"<<endl;
        }while(!valid);
        
        //prompt user for all the test score for each student and add all test score
        for(int j=0;j<tstNum;j++) {
            do {
                cout<<"Test #"<<(j+1)<<": ";
                cin>>stud[i].score[j];
                if(stud[i].score[j]<0||stud[i].score[j]>100)
                    cout<<"Invalid input"<<endl;
            } while(stud[i].score[j]<0||stud[i].score[j]>100);
            stud[i].ave+=stud[i].score[j];
        }
        //calculate the average
        stud[i].ave=stud[i].ave/static_cast<float>(tstNum);
        //Grade
        if(stud[i].ave>=91) {
            stud[i].grade='A';
        } else if(stud[i].ave>=81) {
            stud[i].grade='B';
        } else if(stud[i].ave>=71) {
            stud[i].grade='C';
        } else if(stud[i].ave>=61) {
            stud[i].grade='D';
        } else {
            stud[i].grade='F';
        }
        
    }
    
    
    //deallocate memory
    for(int i=0;i<stuNum;i++) {
        delete stud[i].score;
        stud[i].score=0;
    }
    delete stud;
    stud=0;
    //Exit stage right
    return 0;
}
void pntScro(Class s) {
    cout<<""
}
