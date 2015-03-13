/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 24, 2015, 16:40 PM
 * Purpose: Review homework for C++ with 2D array
 */

//system Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//user libraries

//Global Constants
const int COL=10;

//Function Prototypes
void filArr(int [][COL],int);//Fill the array with random 2-digit number
void prtArr(const int [][COL],int);//display the array
void prtArr(const int [],int,int);//display the array
void bubSrt(const int [][COL],int,int [],int);//Bubble sort
int bSearch(const int [],int,int);//Binary search
int lSearch(int,const int [],int,int);//Linear search
void fndNum(const int [],int,int,int []);//find all number occurred in array
void pntFnd(const int [],int,int);//print out the position array

//Execution begins here
int main(int argc, char** argv) {
    //Set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    const int SIZE=100;
    const int ROW=10;//size of array
    int perLine=10;//the number of elements in a line
    //create integer array
    int arr[ROW][COL]={};//randomly filled array
    int srt[SIZE]={};//sorted array
    int fndPos[ROW]={};//array that saves position of number 50
    filArr(arr,ROW);//Fill array
    cout<<"The array before sorting:"<<endl;
    prtArr(arr,ROW);//Print array
    cout<<"The array after sorting:"<<endl;
    bubSrt(arr,ROW,srt,SIZE);//bubble sort
    prtArr(srt,SIZE,perLine);//Print array
    //fndNum(arr,ROW,50,fndPos);//find the position
    //pntFnd(fndPos,ROW,perLine);//print the position array
    //Exit stage right
    return 0;
}
void fndNum(const int arr[],int ROW,int num,int fp[]) {
    int count=0,pos=0,index=0;
    do {
        index=lSearch(pos,arr,ROW,num);//get the index of number in the array
        fp[count++]=index;
        pos=index+1;
    }while(index>=0&&index<ROW);
}

//Fill the 2D array
void filArr(int arr[][COL],int ROW) {
    //fill the array with random 2-digit number
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            arr[i][j]=rand()%90+10;
        }
    }
}
//Print the array
void prtArr(const int arr[][COL],int ROW) {
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prtArr(const int a[],int SIZE,int pl) {
    for(int i=0;i<SIZE;i++) {
        cout<<a[i]<<" ";
        //10 numbers in a row
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl;
}

void bubSrt(const int arr[][COL],int ROW,int srt[],int SIZE) {
    //declare a boolean
    bool swap;
    int count=0;
    //copy the array
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            srt[count++]=arr[i][j];
        }
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
int bSearch(const int arr[],int ROW,int num) {
    int beg=0;
    int end=ROW-1;
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
int lSearch(int start,const int arr[],int ROW,int num) {
    //looking for the number from first element to last one in the array
    for(int i=start;i<ROW;i++) {
        if(arr[i]==num)
            return i;
    }
    return -1;
}

void pntFnd(const int fnd[],int ROW,int pl) {
    //when the first number in the array is -1,means not found
    if(fnd[0]==-1) {
        cout<<"The number is not found in the array"<<endl;
        return;
    }
    cout<<"The number is in these position in original array"<<endl;
    for(int i=0;i<ROW;i++) {
        if(fnd[i]==-1) {
            cout<<endl;
            return;
        }
        cout<<fnd[i]<<" ";
        //10 numbers in a row
        if(i%pl==(pl-1)) cout<<endl;
    }
}