/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 *
 * Created on March 30, 2015, 1:14 PM
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "student.h"

//Global Constants

//Function prototypes
Student *filStu(int);
void prntStu(Student *,int);
void wrtStu(char *,Student *,int);
void wrtStu1(char *,Student *,int);
Student *readStu(char *,int);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number 
    srand(static_cast<unsigned int>(time(0)));
    //fill the Student array
    int nStu=36;
    Student *stu=filStu(nStu);
    //write to a file all student in binary form
    char fn[]="data.dat";
    wrtStu(fn,stu,nStu);
    //print out student record
    cout<<"Size of a student record = "<<sizeof(Student)<<endl;
    cout<<"Size of all student record = "<<sizeof(stu)<<endl;
    prntStu(stu,nStu);
    //randomly choose a student
    int rStudent=rand()%nStu+1;
    //print the random student
    cout<<endl<<"Read back the "<<rStudent<<" st/nd/rd/th"<<endl;
    //find the 35th student
    Student *one=readStu(fn,35);
    //print 35th student
    prntStu(one,1);
    wrtStu1(fn,one,nStu);
    //deallocate memory
    delete [] stu;
    delete one;
    
    stu=one=0;
    //Exit stage right
    return 0;
}

Student *readStu(char *fn,int rec) {
    //open file for binary
    fstream in;
    in.open(fn,ios::in|ios::out|ios::binary);
    //allocate memory for 1 student
    Student *one=new Student;
    cout<<"Where pointer is "<<one<<endl;
    long position=(rec-1)*sizeof(Student);
    //position pointer
    in.seekg(position,ios::beg);
    //read to file
    in.read(reinterpret_cast<char *>(one),sizeof(Student)*rec);
    //close the file
    in.close();
    return one;
}

void wrtStu(char *fn,Student *a,int n) {
    //open file for binary
    fstream out;
    out.open(fn,ios::out|ios::binary);
    //write to file
    out.write(reinterpret_cast<char *>(a),sizeof(Student)*n);
    //close the file
    out.close();
}

void wrtStu1(char *fn,Student *a,int n) {
    //open file for binary
    fstream out;
    out.open(fn,ios::out|ios::binary);
    //write to file
    out.write(reinterpret_cast<char *>(a[n-1]),sizeof(Student));
    //close the file
    out.close();
}

void prntStu(Student *a,int n) {
    //open file for binary
    fstream out;
    
    //output results
    for(int rec=0;rec<n;rec++){
        cout<<"Student "<<(rec+1)<<"  ";
        cout<<"Student ID = "<<a[rec].sid<<" ";
        cout<<"Score = "<<a[rec].score<<" ";
        cout<<"Grade = "<<a[rec].grade<<endl;
    }
}

Student *filStu(int n) {
    //allocate memory
    Student *csc17a=new Student[n];
    //fill each record
    for(int rec=0;rec<n;rec++){
        csc17a[rec].sid=rand();
        csc17a[rec].score=rand()%30+70;
        if(csc17a[rec].score>89) csc17a[rec].grade='A';
        else if(csc17a[rec].score>79) csc17a[rec].grade='B';
        else csc17a[rec].grade='C';
    }
    //return the records
    return csc17a;
}

