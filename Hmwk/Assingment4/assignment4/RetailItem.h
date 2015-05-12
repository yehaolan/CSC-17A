/* 
 * File:   RetailItem.h
 * Author: admin
 *
 * Created on May 8, 2015, 12:03 AM
 */

#ifndef RETAILITEM_H
#define	RETAILITEM_H
#include <string>
using namespace std;

class RetailItem {
    private:
        string desc;//description of item
        int numUnit;//An integer that holds the number of units currently in inventory.
        float price;//retail price
    public:
        RetailItem(string,int,float);
        void setDesc(string);//set the description
        void setUnit(int);//set the unit in stock
        void setPric(float);//set the price
        string getDesc() const {return desc;}//get description
        int getUnit() const {return numUnit;}//get number of stock
        float getPric() const {return price;}//get price
        void pntItem() const;//print item info
};

#endif	/* RETAILITEM_H */

