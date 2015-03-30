/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on March 29, 2015, 12:35 pM
 * Purpose: 10.6 Vowels and Consonants
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int vwCount(char *);//count vowel
int csCount(char *);//count consonant
//Execution begins here
int main(int argc, char** argv) {
    string ans;//answer of exit or not
    int count=0;//count the run time
    do {
        if(count==0) {
            cout<<"Welcome to counter of vowels and consonants"<<endl;
            cout<<"Press Enter to Continue..."<<endl;
        }
        cin.ignore(1,'\n');
        
        //allocate the dynamic array
        char *arr=new char[1000];//sentence with c-string
        
        //prompt user for sentence
        cout<<"Input sentence: ";
        cin.getline(arr,1000);
        
        //output the result
        cout<<"The length is "<<strlen(arr)<<endl;
        cout<<"The number of vowel is "<<vwCount(arr)<<endl;
        cout<<"The number of consonant is "<<csCount(arr)<<endl;
        
        delete [] arr;
        arr=0;
        
        cout<<"Type \"E\" to exit the program, or type anything to continue"<<endl;
        cin>>ans;
        count++;
    } while(ans!="E"&&ans!="e");
    cout<<"you run this program "<<count<<" times"<<endl;
    //Exit stage right
    return 0;
}

int vwCount(char *arr) {
    int count=0;//counter
    for(int i=0;i<strlen(arr);i++) {
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||
           arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U')  {
            count++;
        }
    }
    return count;
}

int csCount(char *arr) {
    int count=0;//counter
    for(int i=0;i<strlen(arr);i++) {
        //when char is in alphabet
        if(isalpha(arr[i])) {
            if(!(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||
               arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U'))  {
                count++;
            }
        }
    }
    return count;
}
