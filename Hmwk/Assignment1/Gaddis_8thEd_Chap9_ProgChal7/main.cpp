/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 9, 2015, 01:50 PM
 * Purpose:Homework assignment1 (Gaddis_8thEd_Chap9_ProgChal7)
 */

//System libraries
#include <iostream>
using namespace std;

//User libraries

//Global Constants

//Function prototypes
void arrSelectSort(int *[], int);
void showArray(int *, int);
void showArrPtr(int *[], int);


//Execution begins here
int main(int argc, char** argv) {
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
    arrSelectSort(arrPtr, size);

    // Display the array using the array of pointers. This
    // will display them in sorted order.
    cout << "The array, sorted in ascending order are: \n";
    showArrPtr(arrPtr, size);

    // Display the array in their original order.
    cout << "The array, in their original order are: \n";
    showArray(arr, size);
    //delete the dynamic array
    delete [] arr;
    arr=0;
    return 0;
}

//sort the pointer array
void arrSelectSort(int *arrPtr[], int size) {
    int strt, mxIndex; 
    int *maxElem;
    for (strt = 0; strt < (size - 1); strt++) {
        mxIndex = strt;
        maxElem = arrPtr[strt];
        for(int i=strt+1;i<size;i++) {
            if (*(arrPtr[i])>*maxElem) {
                maxElem = arrPtr[i];
                mxIndex = i;
            }
        }
        arrPtr[mxIndex] = arrPtr[strt];
        arrPtr[strt] = maxElem;
    }
}

//Output the original array
void showArray(int *arr, int size)
{
    for (int i=0;i<size;i++)
        cout<<*(arr+i) << " ";
    cout << endl;
}
//Output the sorted array
void showArrPtr(int *arr[], int size) {
    for (int i= 0;i<size;i++) 
        cout << *(*(arr+i)) << " ";
    cout << endl; 
}
