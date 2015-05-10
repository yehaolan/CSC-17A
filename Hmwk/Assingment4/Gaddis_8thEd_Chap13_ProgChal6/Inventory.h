/* 
 * File:   Inventory.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 8, 2015, 4:25 PM
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

class Inventory {
    private:
        int itemNum;//item number
        int quanty;//quantity of item
        float cost;//cost of cost
        float totaCst;//total cost of item
    public:
        Inventory();//Constructor 1
        Inventory(int,float,int);//Constructor 2
        void setItmN(int);//set item number
        void setQuan(int);//set item quantity
        void setCost(float);//set the cost
        void setTCst();//set the total cost
        int getItmN() const {return itemNum;}//get item number
        int getQuan() const {return quanty;}//get quantity of item
        float getCost() const {return cost;}//get the cost
        float getTCst() const {return totaCst;}//get the total cost
        void pntInfo() const;//print out the information of item
};

#endif	/* INVENTORY_H */

