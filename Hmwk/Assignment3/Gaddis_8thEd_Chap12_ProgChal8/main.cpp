/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on April 2, 2015, 2:35 PM
 * Purpose: 12.8 Array/File Function
 */

//system libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//User Libraries

//global Constants

//Function Prototypes
void arrayToFile(string,int *,int);
void fileToArray(string,int *,int);
int *filArr(int);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    int size;
    string fileN;//file name
    do {
        cout<<"Size of array: "<<endl;
        cin>>size;
        if(size<1)
            cout<<"Invalid input"<<endl;
    } while(size<1);
   
    cout<<"File name: "<<endl;
    cin>>fileN;
       
    //allocate the memory
    int *arr=filArr(size);
    int *arrIn=new int[size];
    
    //Before write to file,o output the array
    cout<<"Before writing to file"<<endl;
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
        if(i%5==4) cout<<endl;
    }
    cout<<endl<<endl;;
    
    arrayToFile(fileN,arr,size);//write the array to file
    fileToArray(fileN,arrIn,size);//get the array from the file
    
    //After write to file, output the array
    cout<<"Read the array from the file"<<endl;
    for(int i=0;i<size;i++) {
        cout<<arrIn[i]<<" ";
        if(i%5==4) cout<<endl;
    }
    //deallocate memory
    delete arr;
    delete arrIn;
    //Exit stage right
    return 0;
}

int *filArr(int n) {
    int *arr=new int[n];
    for(int i=0;i<n;i++) {
        arr[i]=rand()%90+10;
    }
    return arr;
}

void arrayToFile(string fileN,int *a,int n) {
    fstream file;
    file.open(fileN,ios::out|ios::binary);
    if(!file.fail())
        file.write(reinterpret_cast<char *>(a),sizeof(int)*n);
    file.close();
}

void fileToArray(string fileN,int *a,int n) {
    fstream file;
    file.open(fileN,ios::in|ios::binary);
    if(!file.fail()) {
        file.read(reinterpret_cast<char *>(a),sizeof(int)*n);
    }
    
    file.close();
}