/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 *
 * Created on May 10, 2015, 1:17 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

#include "DayOfYear.h"
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    int n=rand()%365+1;
    cout<<"Randomly choose a day"<<endl;
    cout<<"It is day #"<<n<<endl;
    
    DayOfYear dd(n);
    DayOfYear::print();
    
    return 0;
}

