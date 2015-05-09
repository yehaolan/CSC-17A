/* 
 * File:   Inventory.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 8, 2015, 4:25 PM
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

class Inventory {
    private:
        int itemNum;
        int quanty;
        float cost;
        float totaCst;
    public:
        Inventory();
        Inventory(int,int,float);
        void setItmN(int);
        void setQuan(int);
        void setCost(float);
        void setTCst();
        int getItmN() const {return itemNum;}
        int getQuan() const {return quanty;}
        float getCost() const {return cost;}
        float getTCst() const {return totaCst;}
};

#endif	/* INVENTORY_H */

