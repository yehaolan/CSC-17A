/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 10, 2015, 11:45 AM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#include "Numbers.h"
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    int n=rand()%10000;
    cout<<"Random number is "<<n<<endl;
    Numbers num(n);
    Numbers::print();
    return 0;
}

