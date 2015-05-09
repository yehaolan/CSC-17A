/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 8, 2015, 12:01 AM
 */

#include <iostream>
#include <string>
using namespace std;

//User libraries
#include "RetailItem.h"

int main(int argc, char** argv) {
    RetailItem item1("Jacket",12,59.95);
    RetailItem item2("Jeans",40,34.95);
    RetailItem item3("Shirt",20,24.95);
    cout<<"Description"<<"   "<<"Units on hand"<<"   Price"<<endl;
    item1.pntItem();
    item2.pntItem();
    item3.pntItem();
    cout<<"Change the price of item1 to $67.89"<<endl;
    item1.setPric(67.89);
    cout<<"Change the number of unit of item2 to 70"<<endl;
    item2.setUnit(70);
    cout<<"Change the Description of item3"<<endl;
    item3.setDesc("Pants");
    cout<<"After changing the information of 3 items"<<endl<<endl;
    cout<<"Description"<<"   "<<"Units on hand"<<"   Price"<<endl;
    item1.pntItem();
    item2.pntItem();
    item3.pntItem();
    return 0;
}

