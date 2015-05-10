/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 8, 2015, 4:22 PM
 */

#include <iostream>
using namespace std;

#include "Inventory.h"

int main(int argc, char** argv) {
    Inventory product(1064,5.5f,10);//declare a product
    product.pntInfo();//display the information 
    cout<<"After Changing the cost to $15..."<<endl;
    product.setCost(15.0f);//set the cost to $15
    product.pntInfo();//output again
    Inventory prod;//declare another product without argument
    prod.pntInfo();//display the information 
    //Exit stage right
    return 0;
}

