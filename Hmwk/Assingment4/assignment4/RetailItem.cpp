/* 
 * File:   RetailItem.cpp
 * Author: admin
 *
 * Created on May 8, 2015, 12:16 AM
 */

#include <string>
#include <iostream>
#include "RetailItem.h"
using namespace std;

RetailItem::RetailItem(string d, int n, float p) {
    desc=d;
    numUnit=n;
    price=p;
}

void RetailItem::setDesc(string d) {
    desc=d;
}
void RetailItem::setUnit(int n) {
    numUnit=n;
}
void RetailItem::setPric(float p) {
    price=p;
}
void RetailItem::pntItem() const {
    cout<<getDesc()<<"          "<<getUnit()<<"           "<<"$"<<getPric()<<endl;
}
