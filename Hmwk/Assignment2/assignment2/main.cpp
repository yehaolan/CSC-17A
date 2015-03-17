/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 10, 2015, 09:50 AM
 * Purpose:Homework assignment2
 */

//System libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User libraries

//Global Constants

//Function prototypes
void pg1();//Gaddis_7thEd_Chap9_ProgChal2
void pg2();//Gaddis_7thEd_Chap9_ProgChal4
void pg3();//Gaddis_7thEd_Chap9_ProgChal6
void pg4();//Gaddis_7thEd_Chap9_ProgChal8
void pg5();//Gaddis_7thEd_Chap9_ProgChal10
void pg6();//Gaddis_7thEd_Chap9_ProgChal12
void mrkSrt(int *,int);
void prtArr(int *,int,int);
void average(int *,int);
void mrkSrt(int *,string *,int);
void prtArr(int *,string *,int,int);
void seltSrt(int *[], int);
void showAry(int *, int);
void pnArPtr(int *[], int);
void seltSrt(int *[], int);
void showAry(int *, int);
void pnArPtr(int *[], int);
int *mode(int *,int);//get the mode from the array
float mean(int *,int);
float median(int *,int);
int *Reverse(int *,int);
int *elmShft(int*,int);

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    string ans;
    char sel;
    do {    
        cout<<"**************Program Menu**************"<<endl;
        cout<<"1.Test score #1"<<endl;
        cout<<"2.Test score #2"<<endl;
        cout<<"3.Case Study Modification"<<endl;
        cout<<"4.Mode, Medium, Median"<<endl;
        cout<<"5.Reverse"<<endl;
        cout<<"6.Element Shifter"<<endl;
        cout<<"0.Exit the program"<<endl;
        //select program
        do {
            cout<<"Please select the program(0 to 6)"<<endl;
            cin>>ans;
            if(ans.at(0)<48||ans.at(0)>54||ans.length()>1)
                cout<<"Invalid input"<<endl;
        }while(ans.at(0)<48||ans.at(0)>54||ans.length()>1);
        sel=ans.at(0);
        switch(sel) {
            case '1': pg1(); break;
            case '2': pg2(); break;
            case '3': pg3(); break;
            case '4': pg4(); break;
            case '5': pg5(); break;
            case '6': pg6(); break;
            case '0': {
                cout<<"This is the end of the program"<<endl;
                break;
            }
        }
        if(sel!='0') {
            cout<<endl<<endl;
            cout<<"Press Enter to continue";
            cin.ignore();
            cin.ignore();
        }
    }while(sel!='0');



    return 0;
}
void pg1() {
    //Gaddis_7thEd_Chap9_ProgChal2
    int size;//size of dynamic array
    int num;//number that user input
    int pl=5;//per line
    //Prompt user for size
    do {
        cout<<"How many numbers would you like to input?"<<endl;
        cin>>size;
        if(size<1)
            cout<<"Invalid input"<<endl;
    } while(size<1);
    //declare the dynamic array
    int *arr=new int[size];
    //prompt user for the contents of array
    for(int i=0;i<size;i++) {
        do {
            cout<<"#"<<(i+1)<<": ";
            cin>>num;
            if(num<0)
                cout<<"Invalid input"<<endl;
            else
                *(arr+i)=num;
        }while(num<0);
    }
    cout<<endl;
    //Output the array before sorting
    cout<<"You'd already inputted:"<<endl;
    prtArr(arr,size,pl);
    
    //sorting and output array
    mrkSrt(arr,size);
    cout<<endl<<"After sorting"<<endl;
    prtArr(arr,size,pl);
    average(arr,size);//get the average
    delete [] arr;
    arr=0;

}

void pg2() {
    //Gaddis_7thEd_Chap9_ProgChal4
    int size;//size of dynamic array
    int num;//number that user input
    int pl=5;//per line
    string name;
    //Prompt user for size
    do {
        cout<<"How many numbers would you like to input?"<<endl;
        cin>>size;
        if(size<1)
            cout<<"Invalid input"<<endl;
    } while(size<1);
    //declare the dynamic array
    int *arr=new int[size];
    string *str=new string[size];
    //prompt user for the contents of array
    cout<<"First input score,then input last name"<<endl;
    for(int i=0;i<size;i++) {
        do {
            cout<<"#"<<(i+1)<<": ";
            cin>>num>>name;
            if(num<0) {
                cout<<"Invalid input"<<endl;
            } else {
                *(arr+i)=num;
                *(str+i)=name;
            }
        }while(num<0);
    }
    cout<<endl;
    //Output the array before sorting
    cout<<"You'd already inputted:"<<endl;
    prtArr(arr,str,size,pl);
    
    //sorting and output array
    mrkSrt(arr,str,size);
    cout<<endl<<"After sorting"<<endl;
    prtArr(arr,str,size,pl);
    average(arr,size);//get the average
    delete [] arr;
    delete [] str;
    str=0;
    arr=0;

}

void pg3() {
    //Gaddis_7thEd_Chap9_ProgChal6
    //declare variables
    int size;//size of array
    const int SIZE=1000;//size for new array
    //prompt user for size of array
    do {
        cout<<"Input the size of array"<<endl;
        cin>>size;
        if(size<1)
            cout<<"Invalid input"<<endl;
    }while(size<1);
    //dynamic allocate array
    int *arr=new int[size];
    int *arrPtr[SIZE]={};//array for pointer
    //Prompt user to input the number for the array
    cout<<"Input the numbers for the array"<<endl;
    for(int i=0;i<size;i++) {
        cout<<"#"<<(i+1)<<": ";
        cin>>*(arr+i);
    }
    
    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the array.
    for (int i=0;i<size;i++)
        arrPtr[i] = &(*(arr+i));

    // Sort the elements of the array of pointers.
    seltSrt(arrPtr, size);

    // Display the array using the array of pointers. This
    // will display them in sorted order.
    cout << "The array, sorted in ascending order are: \n";
    pnArPtr(arrPtr, size);

    // Display the array in their original order.
    cout << "The array, in their original order are: \n";
    showAry(arr, size);
    //delete the dynamic array
    delete [] arr;
    arr=0;

}

void pg4() {
    //Gaddis_7thEd_Chap9_ProgChal8
    //declare variables
    int size;//size of array
    //prompt user for size of array
    do {
        cout<<"Input the size of array"<<endl;
        cin>>size;
        if(size<2)
            cout<<"Invalid input"<<endl;
    }while(size<2);
    //dynamic allocate array
    int *numArr=new int[size];//the array from user
    
    //Prompt user to input the number for the array
    cout<<"Input the numbers for the array"<<endl;
    for(int i=0;i<size;i++) {
        cout<<"#"<<(i+1)<<": ";
        cin>>*(numArr+i);
    }
    //get the mode array
    int *modeArr=mode(numArr,size);//In this array, first element is number of mode
    //second is frequency of mode, the rest is the mode number
    
    cout<<"The mean of these number is "<<mean(numArr,size)<<endl;
    cout<<"The median of these number is "<<median(numArr,size)<<endl;
    //Output the mode
    if(*(modeArr+1)==1) { //when the frequency of mode is 1, means no mode
        cout<<"No mode in these numbers"<<endl;
    } else {
        cout<<"Number of mode in the array: "<<*modeArr<<endl;
        cout<<"Mode: ";
        for(int i=1;i<=*modeArr;i++) {
            cout<<*(modeArr+i+1)<<" ";
        }
        cout<<endl;
        cout<<"Frequency of mode: "<<*(modeArr+1)<<endl;
    }
    delete [] numArr;
    delete [] modeArr;
    numArr=0;
    modeArr=0;

}

void pg5() {
    //Gaddis_7thEd_Chap9_ProgChal10
    int size;//size of array
    //prompt user for size of array
    do {
        cout<<"Input the size of the array"<<endl;
        cin>>size;
        if(size<1)
            cout<<"Invalid input"<<endl;
    }while(size<1);
    int *arr=new int[size];//a dynamic array
    int *brr=new int[size];//another dynamic array
    //prompt user for contents of array
    for(int i=0;i<size;i++) {
        cout<<"#"<<(i+1)<<": ";
        cin>>*(arr+i);
    }
    //output the inputted array
    cout<<"You'd input:"<<endl;
    for(int i=0;i<size;i++) {
        cout<<*(arr+i)<<" ";
    }
    //Reverse
    brr=Reverse(arr,size);
    //Output the reversed array
    cout<<endl<<"After Reverse..."<<endl;
    for(int i=0;i<size;i++) {
        cout<<*(brr+i)<<" ";
    }
    delete [] arr;
    delete [] brr;
    brr=0;
    arr=0;
}

void pg6() {
    //Gaddis_7thEd_Chap9_ProgChal12
    //declare variables
    int size;//size of array
    //prompt user for size of array
    do {
        cout<<"Input the size of array"<<endl;
        cin>>size;
        if(size<2)
            cout<<"Invalid input"<<endl;
    }while(size<2);
    //dynamic allocate array
    int *numArr=new int[size];//the array from user
    
    //Prompt user to input the number for the array
    cout<<"Input the numbers for the array"<<endl;
    for(int i=0;i<size;i++) {
        cout<<"#"<<(i+1)<<": ";
        cin>>*(numArr+i);
    }
    //output the input
    cout<<endl<<"The numbers you input:"<<endl;
    for(int i=0;i<size;i++) {
        cout<<numArr[i]<<" ";
    }
    cout<<endl<<endl;
    int *newArr=elmShft(numArr,size);
    //output results
    cout<<"After element shifter, the numbers are: "<<endl;
    for(int i=0;i<=size;i++) {
        cout<<newArr[i]<<" ";
    }
    cout<<endl;
    
    //clear memory
    delete [] numArr;
    delete [] newArr;
    numArr=0;
    newArr=0;

}

//mark sort
void mrkSrt(int *a,int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(*(a+i)>*(a+j)) {
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
}

//print the array(5 numbers per line)
void prtArr(int *a,int n,int pl) {
    for(int i=0;i<n;i++) {
        cout<<setw(4)<<*(a+i);
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl;
}

//calculate the average of numbers 
void average(int *a,int n) {
    //declare ave
    float ave=0;
    //sum them
    for(int i=0;i<n;i++) {
        ave+=*(a+i);
    }
    //get the average
    ave=ave/n;
    cout<<setprecision(2)<<fixed;
    cout<<"The average of these number is "<<ave<<endl;
}

//mark sort both score and name
void mrkSrt(int *a,string *s,int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(*(a+i)>*(a+j)) {
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
                string tem=*(s+i);
                *(s+i)=*(s+j);
                *(s+j)=tem;
            }
        }
    }
}

//print the array(5 numbers per line)
void prtArr(int *a,string *s,int n,int pl) {
    for(int i=0;i<n;i++) {
        cout<<setw(4)<<*(a+i)<<" "<<*(s+i)<<endl;
    }
    cout<<endl;
}

//sort the pointer array
void seltSrt(int *arrPtr[], int size) {
    int strt, mxIndex; 
    int *maxElem;
    for (strt = 0; strt < (size - 1); strt++) {
        mxIndex = strt;
        maxElem = arrPtr[strt];
        for(int i=strt+1;i<size;i++) {
            if (*(arrPtr[i])<*maxElem) {
                maxElem = arrPtr[i];
                mxIndex = i;
            }
        }
        arrPtr[mxIndex] = arrPtr[strt];
        arrPtr[strt] = maxElem;
    }
}

//Output the original array
void showAry(int *arr, int size)
{
    for (int i=0;i<size;i++)
        cout<<*(arr+i) << " ";
    cout << endl;
}
//Output the sorted array
void pnArPtr(int *arr[], int size) {
    for (int i= 0;i<size;i++) 
        cout << *(*(arr+i)) << " ";
    cout << endl; 
}

int *mode(int *a,int size) {
    //declare variables
    int *m=new int[size];
    int num=*a;//initialize num to first number in array
    int count=0;//count the frequence
    *m=*a;
    *(m+1)=0;
    //mark sort with dynamic array
    for(int i=0;i<size-1;i++) {
        for(int j=i+1;j<size;j++) {
            if(*(a+i)>*(a+j)) {
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
    cout<<endl;
    //compare the numbers in the array
    for(int i=0;i<=size;i++) {
        //when this number equal to previous number
        if(*(a+i)==num&&i!=size) {
            count++;
        } else {
            //if not equal to previous number
            if(count>*(m+1)) { //if count > the previous largest frequency
                *m=1; //the number of mode is 1
                *(m+1)=count;//Frequency is count
                *(m+2)=*(a+i-1);//Save this number to third element of dynamic array
            } else if(count==*(m+1)) { //if count == the previous largest frequency
                *m+=1;//The number of mode +1
                *(m+(*m)+1)=*(a+i-1);//Save this number
            }
            num=*(a+i);//Get the temp number
            count=1;//count assigned to 1
        }
    }
    return m;
}

float mean(int *a,int size) {
    //declare value average in float
    float ave=0;
    //sum the array
    for(int i=0;i<size;i++) {
        ave+=*(a+i);
    }
    //divided by size of array
    ave/=size;
    return ave;
}

float median(int *a,int size) {
    //mark sort with dynamic array
    for(int i=0;i<size-1;i++) {
        for(int j=i+1;j<size;j++) {
            if(*(a+i)>*(a+j)) {
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
    if(size%2==1) {
        return *(a+size/2);
    } else {
        //declare variables
        float res;//result
        res=*(a+size/2-1)+*(a+size/2);
        res/=2;
        return res;
    }
    
}

//Reverse
int *Reverse(int *a,int n) {
    int *b=new int[n];
    for(int i=0;i<n;i++) {
        *(b+i)=*(a+n-i-1);
    }
    return b;
}

//element shifter(shift one element)
int *elmShft(int *a,int size) {
    //allocate dynamic array
    int *n=new int[size+1];
    for(int i=0;i<=size;i++) {
        if(i==0) {
            n[i]=0;
        } else {
            n[i]=a[i-1];
        }    
    }
    return n;
}