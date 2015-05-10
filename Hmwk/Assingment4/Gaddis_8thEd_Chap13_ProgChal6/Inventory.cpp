/* 
 * File:   Inventory.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 8, 2015, 4:25 PM
 */

#include "Inventory.h"
#include <iostream>
using namespace std;

//Constructor1
Inventory::Inventory() {
    //Initialize the variables to 0
    itemNum=0;
    quanty=0;
    cost=0;
    totaCst=0;
}

//Constructor2
Inventory::Inventory(int num,float c,int q) {
    itemNum=num;
    quanty=q;
    cost=c;
    setTCst();
}

//set the item number
void Inventory::setItmN(int num) {
    if(num>=0) itemNum=num;
    else cout<<"Invalid item number"<<endl;
    
}

//set the quantity of items
void Inventory::setQuan(int q) {
    if(q>=0) {
        quanty=q;
        setTCst();
    }
    else cout<<"Invalid quantity of item"<<endl;
}

//set the cost of item
void Inventory::setCost(float c) {
    if(c>=0) {
        cost=c;
        setTCst();
    }
    else cout<<"Invalid cost of item"<<endl;
}

//set the total cost
void Inventory::setTCst() {
    totaCst=quanty*cost;
}

//print the information of item
void Inventory::pntInfo() const {
    cout<<"Item number: #"<<getItmN()<<endl;
    cout<<"Quantity: "<<getQuan()<<endl;
    cout<<"Cost: $"<<getCost()<<endl;
    cout<<"Total Cost: $"<<getTCst()<<endl<<endl;
}
