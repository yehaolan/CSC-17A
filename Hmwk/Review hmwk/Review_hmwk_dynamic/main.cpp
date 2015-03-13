/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 27, 2015, 2:08 PM
 * Purpose: Review homework for C++ with dynamic array
 */

//system Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//user libraries

//Global Constants

//Function Prototypes
void filArr(int *,int);//Fill the array with random 2-digit number
void prtArr(int *,int,int);//display the array
void bubSrt(int *,int,int *);//Bubble sort
int bSearch(int *,int,int);//Binary search
int lSearch(int,int *,int,int);//Linear search
void fndNum(int *,int,int,int *);//find all number occurred in array
void pntFnd(int *,int,int);//print out the position array

//Execution begins here
int main(int argc, char** argv) {
    //Set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    int size=100;//size of array
    int perLine=10;//the number of elements in a line
    //create integer array
    int *arr=new int[size];//randomly filled array
    int *srt=new int[size];//sorted array
    int *fndPos=new int[size];//array that saves position of number 50
    filArr(arr,size);//Fill array
    cout<<"The array before sorting:"<<endl;
    prtArr(arr,size,perLine);//Print array
    cout<<"The array after sorting:"<<endl;
    bubSrt(arr,size,srt);//bubble sort
    prtArr(srt,size,perLine);//Print array
    fndNum(arr,size,50,fndPos);//find the position
    pntFnd(fndPos,size,perLine);//print the position array
    //Exit stage right
    delete [] arr;
    delete [] srt;
    delete [] fndPos;
    fndPos=0;
    srt=0;
    arr=0;
    return 0;
}
void fndNum(int *arr,int size,int num,int *fp) {
    int count=0,pos=0,index=0;
    do {
        index=lSearch(pos,arr,size,num);//get the index of number in the array
        fp[count++]=index;
        pos=index+1;
    }while(index>=0&&index<size);
}

//Fill the array
void filArr(int *arr,int size) {
    //fill the array with random 2-digit number
    for(int i=0;i<size;i++) {
        *(arr+i)=rand()%90+10;
    }
}
//Print the array
void prtArr(int *arr,int size,int pl) {
    for(int i=0;i<size;i++) {
        cout<<*(arr+i)<<" ";
        //10 numbers in a row
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl;
}

void bubSrt(int *arr,int size,int *srt) {
    //declare a boolean
    bool swap;
    //copy the array
    for(int i=0;i<size;i++) {
        srt[i]=arr[i];
    }
    //bubble sort
    do {
        swap=false;
        for(int i=0;i<size-1;i++) {
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
int bSearch(int *arr,int size,int num) {
    int beg=0;
    int end=size-1;
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
int lSearch(int start,int *arr,int size,int num) {
    //looking for the number from first element to last one in the array
    for(int i=start;i<size;i++) {
        if(arr[i]==num)
            return i;
    }
    return -1;
}

void pntFnd(int *fnd,int size,int pl) {
    //when the first number in the array is -1,means not found
    if(fnd[0]==-1) {
        cout<<"The number is not found in the array"<<endl;
        return;
    }
    cout<<"The number is in these position in original array"<<endl;
    for(int i=0;i<size;i++) {
        if(fnd[i]==-1) {
            cout<<endl;
            return;
        }
        cout<<fnd[i]<<" ";
        //10 numbers in a row
        if(i%pl==(pl-1)) cout<<endl;
    }
}