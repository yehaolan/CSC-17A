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
        void setDesc(string);
        void setUnit(int);
        void setPric(float);
        string getDesc() const {return desc;}
        int getUnit() const {return numUnit;}
        float getPric() const {return price;}
        void pntItem() const;
};

#endif	/* RETAILITEM_H */

