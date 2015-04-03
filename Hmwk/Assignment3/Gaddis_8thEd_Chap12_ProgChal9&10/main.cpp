/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 3, 2015, 9:49 AM
  * Purpose: 12.9&10 File Encryption Filter
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
    string ans;
    char ch;
    int count;
    cout<<"1. Encryption"<<endl;
    cout<<"2. Decryption"<<endl;
    do {
        cout<<"Your Choice(1-2): ";
        cin>>ans;
        if(ans!="1"&&ans!="2") 
            cout<<"Invalid input"<<endl;
    } while(ans!="1"&&ans!="2");
    if(ans=="1") {
        fstream in;
        fstream out;
        char ofn[]="EnFile.dat";//output file name
        char ifn[]="Original.dat";//original file name
        count=0;
        in.open(ifn,ios::in);
        out.open(ofn,ios::out);
        if(!in.fail()) { //if open successfully
            cout<<"Open the input file successfully"<<endl;
            if(!out.fail()) {
                cout<<"Open the output file successfully"<<endl;
                /*
                do {
                    if(in.get(ch)) {
                        in.get(ch);
                        ch+=count;
                        count++;
                        out.put(ch);
                        if(count==10) count=0;
                    }
                }while(!in);
                */
                //Encryption digit%10 if it's 1 add 1 to ch, if 2,add 2...
                in.get(ch);
                ch+=count;
                while(in) {
                    out.put(ch);
                    count++;
                    if(count==10) count=0;
                    in.get(ch);
                    ch+=count;
                }
                cout<<"Finish Encryption"<<endl;
            } else { //if it's fail to open output file
                cout<<"Cannot open the output file"<<endl;
            }
        } else { //if fail to open input file
            cout<<"Cannot open the input file"<<endl;
        }
        out.close();
        in.close();
    } else if(ans=="2") {
        fstream in;
        fstream out;
        char ofn[]="DeFile.dat";//output file name
        char ifn[]="Enfile.dat";//original file name
        count=0;
        in.open(ifn,ios::in);
        out.open(ofn,ios::out);
        if(!in.fail()) { //if open successfully
            cout<<"Open the input file successfully"<<endl;
            if(!out.fail()) {
                cout<<"Open the output file successfully"<<endl;
                /*
                do {
                    if(in.get(ch)) {
                        in.get(ch);
                        ch+=count;
                        count++;
                        out.put(ch);
                        if(count==10) count=0;
                    }
                }while(!in);
                */
                //Decryption digit%10 if it's 1 minus 1 to ch, if 2,minus 2...
                in.get(ch);
                ch-=count;
                while(in) {
                    out.put(ch);
                    count++;
                    if(count==10) count=0;
                    in.get(ch);
                    ch-=count;
                }
                cout<<"Finish Encryption"<<endl;
            } else { //if it's fail to open output file
                cout<<"Cannot open the output file"<<endl;
            }
        } else { //if fail to open input file
            cout<<"Cannot open the input file"<<endl;
        }
        out.close();
        in.close();
    }
    
    return 0;
}

