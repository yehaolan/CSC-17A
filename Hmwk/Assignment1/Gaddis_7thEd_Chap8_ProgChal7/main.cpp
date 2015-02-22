/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 21, 2015, 7:50 PM
 * Purpose: Homework assignment1 (Gaddis_7thEd_Chap8_ProgChal7)
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void markSrt(string [],int); //Mark sort for string array
int bSearch(string,const string [],int);//Binary search

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    const int SIZE = 20;
    string str;
    //String array
     string names[SIZE] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                                "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                                "Taylor, Terri", "Johnson, Jill",
                                "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                                "James, Jean", "Weaver, Jim", "Pore, Bob",
                                "Rutherford, Greg", "Javens, Renee",
                                "Harrison, Rose", "Setzer, Cathy",
                                "Pike, Gordon", "Holland, Beth" } ;
    //Prompt user for string that they would like to search
    cout<<"Input a full name"<<endl;
    getline(cin,str);
    //Sort the array
    markSrt(names,SIZE);
    //Search the element
    int result=bSearch(str,names,SIZE);
    
    //Print the result 
    if(result==-1)
        cout<<"The name you searched is not in the array"<<endl;
    else
        cout<<"The name you searched is in the array"<<endl;
    //Exit stage right
    return 0;
}

void markSrt(string arr[],int SIZE) {
    for(int i=0;i<SIZE-1;i++) {
        for(int j=i+1;j<SIZE;j++) {
            if(arr[i]>arr[j]) {
                string temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
//Binary search
int bSearch(string str,const string arr[],int SIZE) {
    int beg=0;
    int end=SIZE-1;
    int mid;
    do {
        mid=(beg+end)/2;
        if(str==arr[mid])
            return mid;
        else if(str<arr[mid]) {
            end=mid-1;
        }
        else {
            beg=mid+1;
        }
    }while(beg<=end);
    return -1;
}