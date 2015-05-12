/* 
 * File:   Numbers.h
 * Author: Haolan Ye (Benjamin)
 *
 * Created on May 10, 2015, 12:03 PM
 */

#include <iostream>
#include <string>
using namespace std;
#include "Numbers.h"

string Numbers::res="";

//Constructor 1
Numbers::Numbers() {
    number=0;
    trans(number);
    cout<<"HIIH"<<endl;
}

//Constructor 2
Numbers::Numbers(int n) {
    if(n<0||n>9999) {
        cout<<"Out of range and set the number to 0"<<endl;
        number=0;
        trans(0);
    } else {
        number=n;
        trans(number);
    }
}

//translate into English
void Numbers::trans(int num) {
    res="";
    string lessThan20[20]={"zero","one","two","three","four","five","six",
    "seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
    "fifteen","sixteen","seventeen","eighteen","nineteen"};
    string tens[10]={" ","ten","twenty","thirty","forty","fifty",
                        "sixty","seventy","eighty","ninety"};
    string hundred="hundred";
    string thous="thousand";
    int s,//single digit
        t,//tens digit
        h,//hundred digit
        th;//thousand digit
    s=num%10;
    num/=10;
    t=num%10;
    num/=10;
    h=num%10;
    num/=10;
    th=num%10;
    if(th!=0) res=res+lessThan20[th]+" "+thous+" ";
    if(h!=0) res=res+lessThan20[h]+" "+hundred+" ";
    if(t<2) res=res+lessThan20[t*10+s]+" ";
    else {
        res=res+tens[t]+" "+lessThan20[s]+" ";
    }
}

//print out result
void Numbers::print() {
    cout<<"The result is "<<res<<endl;
}