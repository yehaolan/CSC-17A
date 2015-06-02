/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on June 1, 2015, 1:26 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "SimpleVector.h"
int main(int argc, char** argv) {
    
    int size=10;
    SimpleVector<int> sv(size);
    //fill the vector
    for(int i=0;i<sv.size();i++) {
        sv[i]=i;
    }
    //add one element
    sv.push(size);
    for(int i=0;i<sv.size();i++) {
        cout<<sv[i]<<" ";
    }
    cout<<endl<<"The size is "<<sv.size()<<endl;
    return 0;
}

