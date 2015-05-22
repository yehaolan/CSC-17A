/* 
 * File:   main.cpp
 * Author: Haolan Ye
 * Created on May 22, 2015, 3:02 AM
 * Purpose: Essay
 */

#include <iostream>
using namespace std;

#include "Essay.h"

int main(int argc, char** argv) {
    int gram;
    int spel;
    int corL;
    int cont;
    //Prompt user for the score of Essay
    do {
        cout<<"Grammar(30 points): ";
        cin>>gram;
        if(gram<0||gram>30) cout<<"Invalid grammar score"<<endl;
    } while(gram<0||gram>30);
    
    do {
        cout<<"Spelling(20 points): ";
        cin>>spel;
        if(spel<0||spel>20) cout<<"Invalid spelling score"<<endl;
    } while(spel<0||spel>20);
    
    do {
        cout<<"Correct length(20 points): ";
        cin>>corL;
        if(corL<0||corL>20) cout<<"Invalid length score"<<endl;
    } while(corL<0||corL>20);
    
    do {
        cout<<"Content(30 points): ";
        cin>>cont;
        if(cont<0||cont>30) cout<<"Invalid content score"<<endl;
    } while(cont<0||cont>30);
    
    //declare a Essay Object
    Essay ee(gram,spel,corL,cont);
    cout<<"He/She got "<<ee.getScore()<<"    "<<ee.getLetterGrade();
    return 0;
}

