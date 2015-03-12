/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 11, 2015, 5:24 PM
 * Purpose: Assignment 1 for Review
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
//User Libraries

//Global Constants
const char CONVPT=100;//Convert to Percent
const char SALETAX=4;//State Sales Tax(Percent)
const char CONTTAX=2;//County Sales Tax(Percent)
const char ASESPT=60;//Assessment value in percent
const char PPTAX=64;//Property tax in cents

//Function prototypes
void pg1();//Gaddis_7thEd_Chap3_ProgChal12
void pg2();//Gaddis_7thEd_Chap3_ProgChal13
void pg3();//Gaddis_7thEd_Chap4_ProgChal10
void pg4();//Gaddis_7thEd_Chap5_ProgChal11
void pg5();//Gaddis_7thEd_Chap6_ProgChal7
void pg6();//Gaddis_7thEd_Chap7_ProgChal6
void pg7();//Gaddis_7thEd_Chap8_ProgChal7
float celsius(int);//convert f to c
void markSrt(string [],int); //Mark sort for string array
int bSearch(string,const string [],int);//Binary search

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    char ans;
    do {    
        cout<<"**************Program Menu**************"<<endl;
        cout<<"1.Miles Per Gallon"<<endl;
        cout<<"2.Miles Per Gallon2"<<endl;
        cout<<"3.Inflation rate"<<endl;
        cout<<"4.Gravitational attractive force"<<endl;
        cout<<"5.Clothing size"<<endl;
        cout<<"6.New House After-tax cost"<<endl;
        cout<<"7.Caloric Requirement"<<endl;
        cout<<"0.Exit the program"<<endl;
        //select program
        do {
            cout<<"Please select the program(0 to 7)"<<endl;
            cin>>ans;
            if(ans<48||ans>55)
                cout<<"Invalid input"<<endl;
        }while(ans<48||ans>55);

        switch(ans) {
            case '1': pg1(); break;
            case '2': pg2(); break;
            case '3': pg3(); break;
            case '4': pg4(); break;
            case '5': pg5(); break;
            case '6': pg6(); break;
            case '7': pg7(); break;
            case '0': {
                cout<<"This is the end of the program"<<endl;
                break;
            }
        }
        if(ans!='0') {
            cout<<endl<<endl;
            cout<<"Press Enter to continue";
            cin.ignore();
            cin.ignore();
        }
    }while(ans!='0');

    //Exit stage right
    return 0;
}

//Gaddis_7thEd_Chap3_ProgChal12
void pg1() {
    //declare variables
    string month;//Month
    float tc;//Total Collected
    float sales;//Sales
    float cst;//County Sales Tax
    float sst;//State Sales Tax
    float tst;//Total Sales Tax
    //Prompt user for month
    do {
        cout<<"Input the name of month(Such as March)"<<endl;
        cout<<"Month: ";
        cin>>month;
        if(month!="January"&&month!="February"&&month!="March"&&month!="April"&&
           month!="May"&&month!="June"&&month!="July"&&month!="August"&&
           month!="September"&&month!="October"&&month!="November"&&month!="December")
            cout<<"Invalid input"<<endl;
    } while(month!="January"&&month!="February"&&month!="March"&&month!="April"&&
           month!="May"&&month!="June"&&month!="July"&&month!="August"&&
           month!="September"&&month!="October"&&month!="November"&&month!="December");        
    cout<<"--------------------------"<<endl;
    //Prompt user for Total Collected
    do {
        cout<<"Total Collected:     $";
        cin>>tc;
        if(tc<0)
            cout<<"Invalid input"<<endl;
    } while(tc<0);
    //Calculate the results
    sales=tc/(static_cast<float>(100+SALETAX+CONTTAX)/CONVPT);
    cst=static_cast<float>(sales)*CONTTAX/CONVPT;
    sst=static_cast<float>(sales)*SALETAX/CONVPT;
    tst=cst+sst;
    cout<<setprecision(2)<<fixed;
    cout<<"Sales:               $"<<setw(10)<<sales<<endl;
    cout<<"County Sales Tax:    $"<<setw(10)<<cst<<endl;
    cout<<"State Sales Tax:     $"<<setw(10)<<sst<<endl;
    cout<<"Total Sales Tax:     $"<<setw(10)<<tst<<endl;
}

//Gaddis_7thEd_Chap3_ProgChal13
void pg2() {
    //Declare variables
    float acVal;//actual value of a piece of property
    float asVal;//assessment value of property
    float tax;//property taxes
    //Prompt user for actual value
    do {
        cout<<"Input the actual value of a piece of property(in dollar)"<<endl;
        cin>>acVal;
        if(acVal<0)
            cout<<"Invalid input"<<endl;
    } while(acVal<0);
    //Calculate the results
    asVal=acVal*ASESPT/CONVPT;
    tax=asVal*PPTAX/CONVPT/CONVPT;
    //Print the results
    cout<<setprecision(2)<<fixed;
    cout<<"The assessment value is $"<<asVal<<endl;
    cout<<"The property tax   is   $"<<tax<<endl;
}

//Gaddis_7thEd_Chap4_ProgChal10
void pg3() {
    //declare variables
    short retail = 99;//the retail of a package($)
    short unit;//the number of units sold
    float cost;//total cost of the purchase
    char dscnt;//quantity discount
    //Prompt user for the number of units
    do {
      cout << "How many unit of package have been sold?" <<endl;
      cin >> unit;
      if(unit<=0)
          cout << "Please input the positive number" << endl;
    } while(unit<=0);//make sure the number of unit is positive
    //determine the discount
    if(unit>=100) {
        dscnt = 50;
    } else if(unit>=50) {
        dscnt = 40;
    } else if(unit>=20) {
        dscnt = 30;
    } else if(unit>=10) {
        dscnt = 20;
    } else {
        dscnt = 0;
    }
    //calculate the total cost
    cost = retail*unit*(1-static_cast<float>(dscnt)/CONVPT);
    //Output the result
    cout << setprecision(2) << fixed;
    cout << "The total cost of the purchase is $" << cost << endl;
}

//Gaddis_7thEd_Chap5_ProgChal11
void pg4() {
    //declare variables
    short size;//size of the population
    short dPoInc;//daily population increase(in percentage)
    short day;//number of day will multiply
    //Prompt user for original size of pop
    do {
        cout<<"Input the original population"<<endl;
        cin>>size;
        if(size<2)
            cout<<"Invalid input"<<endl;
    }while(size<2);
    //Prompt user for population increase percent
    do {
        cout<<"Input the average daily population increase (as a percentage)"<<endl;
        cin>>dPoInc;
        if(dPoInc<0)
            cout<<"Invalid input"<<endl;
    }while(dPoInc<0);
    //Prompt user for number of day
    do {
        cout<<"Input the number of day that will multiply"<<endl;
        cin>>day;
        if(day<1)
            cout<<"Invalid input"<<endl;
    }while(day<1);
    //Print out the results
    cout<<"  Day  "<<"Population"<<endl;
    for(int i=1;i<=day;i++) {
        size=size*(100+dPoInc)/100;
        cout<<setw(4)<<i<<setw(10)<<size<<endl;
    }
}

//Gaddis_7thEd_Chap6_ProgChal7
void pg5() {
    //formatted Output the results with a table
    cout<<setprecision(1)<<fixed;
    cout<<"Fahrenheit"<<"   "<<"Celsius"<<endl;
    for(int f=0;f<=20;f++) {
        cout<<setw(5)<<f<<setw(13)<<celsius(f)<<endl;
    }
}

//Gaddis_7thEd_Chap7_ProgChal66
void pg6() {
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
}

//Gaddis_7thEd_Chap8_ProgChal7
void pg7() {
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
}

//convert f to c
float celsius(int f) {
    return (f-32)*5.0f/9;
}

//mark sort
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