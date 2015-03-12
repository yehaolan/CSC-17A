/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 20, 2015, 7:42 AM
 * Purpose: Homework assignment1 (Gaddis_7thEd_Chap7_ProgChal6)
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes


//Execution begins here
int main(int argc, char** argv) {
    //Open the file
    ifstream input;
    input.open("Number.txt");
    //declare variables
    const int SIZE=50;
    int num;//number from file
    int ln;//lowest number
    int hn;//highest number
    int sum=0;//Sum
    float ave;//Average
    int arr[SIZE]={};
    //Read the number in file to an array
    if(!input.fail()) {
        for(int i=0;i<SIZE&&input>>num;i++) {
            arr[i]=num;
        }
    }
    //initialize the variables
    ln=arr[0];
    hn=arr[0];
    //Check the number
    for(int i=0;i<SIZE;i++) {
        //when number < lowest number
        if(arr[i]<ln)
            ln=arr[i];
        //when number > highest number
        if(arr[i]>hn)
            hn=arr[i];
        sum+=arr[i];
    }
    //calculate the average
    ave=static_cast<float>(sum)/SIZE;
    //Output the results
    cout<<setprecision(1)<<fixed;
    cout<<"There are 50 2-digit number(between 10 and 99) in the file"<<endl;
    cout<<"The lowest number           is "<<ln<<endl;
    cout<<"The highest number          is "<<hn<<endl;
    cout<<"The sum of these number     is "<<sum<<endl;
    cout<<"The average of these number is "<<ave<<endl;
    input.close();//close the file
    //Exit stage right
    return 0;
}


