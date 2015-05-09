/* 
 * File:   Inventory.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 8, 2015, 4:25 PM
 */

#include "Inventory.h"
#include <iostream>
using namespace std;
Inventory::Inventory() {
    itemNum=0;
    quanty=0;
    cost=0;
    totaCst=0;
}

Inventory::Inventory(int num, int q, float c) {
    itemNum=num;
    quanty=q;
    cost=c;
    setTCst(q*c);
}

void Inventory::setItmN(int num) {
    if(num>=0) itemNum=num;
    else {
        cout<<"Invalid item number"<<endl;
        exit(EXIT_FAILURE);
    }
}

void Inventory::setQuan(int q) {
    if(q>=0) quanty=q;
    else {
        cout<<"Invalid quantity of item"<<endl;
        exit(EXIT_FAILURE);
    }
}

void Inventory::setCost(float c) {
    if(c>=0) cost=c;
    else {
        cout<<"Invalid cost of item"<<endl;
        exit(EXIT_FAILURE);
    }
}

void Inventory::setTCst() {
    totaCst=quanty*cost;
}
