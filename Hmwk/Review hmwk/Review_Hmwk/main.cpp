/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 24, 2015, 2:08 PM
 * Purpose: Review homework for C++
 */

//system Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//user libraries

//Global Constants

//Function Prototypes
void filArr(int [],int);//Fill the array with random 2-digit number
void prtArr(const int [],int,int);//display the array
void bubSrt(const int [],int,int []);//Bubble sort
int bSearch(const int [],int,int);//Binary search
int lSearch(int,const int [],int,int);//Linear search
void fndNum(const int [],int,int,int []);//find all number occurred in array
void pntFnd(const int [],int,int);//print out the position array

//Execution begins here
int main(int argc, char** argv) {
    //Set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    const int SIZE=100;//size of array
    int perLine=10;//the number of elements in a line
    //create integer array
    int arr[SIZE]={};//randomly filled array
    int srt[SIZE]={};//sorted array
    int fndPos[SIZE]={};//array that saves position of number 50
    filArr(arr,SIZE);//Fill array
    cout<<"The array before sorting:"<<endl;
    prtArr(arr,SIZE,perLine);//Print array
    cout<<"The array after sorting:"<<endl;
    bubSrt(arr,SIZE,srt);//bubble sort
    prtArr(srt,SIZE,perLine);//Print array
    fndNum(arr,SIZE,50,fndPos);//find the position
    pntFnd(fndPos,SIZE,perLine);//print the position array
    //Exit stage right
    return 0;
}
void fndNum(const int arr[],int SIZE,int num,int fp[]) {
    int count=0,pos=0,index=0;
    do {
        index=lSearch(pos,arr,SIZE,num);//get the index of number in the array
        fp[count++]=index;
        pos=index+1;
    }while(index>=0&&index<SIZE);
}

//Fill the array
void filArr(int arr[],int SIZE) {
    //fill the array with random 2-digit number
    for(int i=0;i<SIZE;i++) {
        arr[i]=rand()%90+10;
    }
}
//Print the array
void prtArr(const int arr[],int SIZE,int pl) {
    for(int i=0;i<SIZE;i++) {
        cout<<arr[i]<<" ";
        //10 numbers in a row
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl;
}

void bubSrt(const int arr[],int SIZE,int srt[]) {
    //declare a boolean
    bool swap;
    //copy the array
    for(int i=0;i<SIZE;i++) {
        srt[i]=arr[i];
    }
    //bubble sort
    do {
        swap=false;
        for(int i=0;i<SIZE-1;i++) {
            if(srt[i]>srt[i+1]) {
                int temp=srt[i];
                srt[i]=srt[i+1];
                srt[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}
//Binary search
int bSearch(const int arr[],int SIZE,int num) {
    int beg=0;
    int end=SIZE-1;
    int mid;
    do {
        mid=(beg+end)/2;
        if(arr[mid]==num) {
            return mid;
        } else if(arr[mid]>num) {
            end=mid-1;
        } else {
            beg=mid+1;
        }
    }while(beg<=end);
    return -1;
}
//Linear search
int lSearch(int start,const int arr[],int SIZE,int num) {
    //looking for the number from first element to last one in the array
    for(int i=start;i<SIZE;i++) {
        if(arr[i]==num)
            return i;
    }
    return -1;
}

void pntFnd(const int fnd[],int SIZE,int pl) {
    //when the first number in the array is -1,means not found
    if(fnd[0]==-1) {
        cout<<"The number is not found in the array"<<endl;
        return;
    }
    cout<<"The number is in these position in original array"<<endl;
    for(int i=0;i<SIZE;i++) {
        if(fnd[i]==-1) {
            cout<<endl;
            return;
        }
        cout<<fnd[i]<<" ";
        //10 numbers in a row
        if(i%pl==(pl-1)) cout<<endl;
    }
}