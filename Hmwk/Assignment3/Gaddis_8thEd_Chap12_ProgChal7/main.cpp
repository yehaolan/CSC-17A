/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on April 2, 2015, 12:49 PM
 * Purpose: 12.7 File decryption filter
 */

//system libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    ifstream input;
    ofstream output;
    string inFileN;//input file name
    string otFileN;//output file name
    char ch;
    int count=0;
    //get the input file name
    cout<<"Enter the file(for input) name: ";
    cin>>inFileN;
    //get the output file name
    cout<<"Enter the file(for output) name: ";
    cin>>otFileN;
    cout<<"Now, open the file..."<<endl;
    input.open(inFileN);//open the input file
    if(!input.fail()) { //if open successfully
        cout<<"Open the input file successfully"<<endl;
        output.open(otFileN);
        if(!output.fail()) {
            cout<<"Open the output file successfully"<<endl;
            input.get(ch);
            while(input) {
                if(count==0) output.put(toupper(ch)); 
                else    output.put(tolower(ch));
                count++;
                if(ch=='.') count=0;
                input.get(ch);
                
            }
            cout<<"Finish copy a sentence from input file to output file"<<endl;
        } else { //if it's fail to open output file
            cout<<"Cannot open the output file"<<endl;
        }
    } else { //if fail to open input file
        cout<<"Cannot open the input file"<<endl;
    }
    input.close();
    output.close();
    //Exit stage right
    return 0;
}

