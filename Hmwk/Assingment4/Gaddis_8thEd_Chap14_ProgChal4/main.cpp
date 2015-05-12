/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 11, 2015, 10:26 PM
 */

#include <cstdlib>

using namespace std;

#include "NumDays.h"
int main(int argc, char** argv) {
    NumDays aa(12);
    aa.pntDays();
    NumDays bb(12);
    NumDays cc=aa+bb;
    cc.pntDays();
    return 0;
}

