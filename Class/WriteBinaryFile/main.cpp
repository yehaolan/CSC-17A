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
    //Initialize random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Fill the Student array
    int nStudents=36;
    Student *stu=filStu(nStudents);
    //Write to a file all the students in binary form
    char fn[]="stu.dat";
    cout<<endl<<"Generate the data file"<<endl;
    wrtStu(fn,stu,nStudents);
    //Print out the student records
    cout<<"Size of a student record = "<<sizeof(Student)<<endl;
    cout<<"Size of all student records = "<<sizeof(stu)<<endl;
    prntStu(stu,nStudents);
    //Randomly chose a student
    int rStudent=rand()%nStudents+1;
    cout<<endl<<"Read back the "<<rStudent<<" st/nd/rd/th student in the file"<<endl;
    Student *one=readStu(fn,rStudent);
    //Print the random student
    prntStu(one,nStudents);
    //Write this to a random position
    //rStudent=rand()%nStudents+1;
    //cout<<"The random position written = "<<rStudent<<endl;
    //wrtStu1(fn,one,rStudent);
    //Deallocate memory
    delete []stu;
    delete one;
    //Exit stage right
    return 0;
}

Student *readStu(char *fn,int rec){
    //Open file for binary
    fstream in;
    in.open(fn,ios::out|ios::in|ios::binary);
    //Allocate memory for 1 student;
    Student *one=new Student;
    //Position read pointer;
    long position=(rec-1)*sizeof(Student);
    in.seekg(position,ios::beg);
    //Read from the file
    in.read(reinterpret_cast<char *>(one),sizeof(Student));
    //Close and exit
    in.close();
    //Return the record
    return one;
}

void wrtStu1(char *fn,Student *a,int n){
    //Open file for binary
    fstream out;
    out.open(fn,ios::out|ios::binary);
    //Position read pointer;
    long position=(n-1)*sizeof(Student);
    out.seekp(position,ios::beg);
    //Write to the file
    out.write(reinterpret_cast<char *>(a),sizeof(Student));
    //Close and exit
    out.close();
}

void wrtStu(char *fn,Student *a,int n){
    //Open file for binary
    fstream out;
    out.open(fn,ios::out|ios::binary);
    //Write to the file
    out.write(reinterpret_cast<char *>(a),sizeof(Student)*n);
    //Close and exit
    out.close();
}

void prntStu(Student *a,int n){
    //Output the results
    for(int rec=0;rec<n;rec++){
        cout<<"Student "<<rec+1<<" ";
        cout<<"Student id = "<<a[rec].sid;
        cout<<" Score = "<<a[rec].score;
        cout<<" Grade = "<<a[rec].grade<<endl;
    }
}

void prntStu1(Student *a,int n){
    //Output the results
    cout<<"Student "<<n<<" ";
    cout<<"Student id = "<<a->sid;
    cout<<" Score = "<<a->score;
    cout<<" Grade = "<<a->grade<<endl;
}

Student *filStu(int n){
    //Allocate memory
    Student *csc17a=new Student[n];
    //Fill each record
    for(int rec=0;rec<n;rec++){
        csc17a[rec].sid=rand();
        csc17a[rec].score=rand()%30+70;
        if(csc17a[rec].score>89)csc17a[rec].grade='A';
        else if(csc17a[rec].score>79)csc17a[rec].grade='B';
        else csc17a[rec].grade='C';
    }
    //Return the records
    return csc17a;
}