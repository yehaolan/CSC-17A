/* 
 * File:   PersonalData.h
 * Author: Haolan Ye (Benjamin)
 * Created on May 22, 2015, 9:22 AM
 * Purpose: Base class PersonalData
 */

#ifndef PERSONALDATA_H
#define	PERSONALDATA_H

class PersonalData {
    protected:
        string lastNm;//last name
        string firstNm;//first name
        string address;
        string city;
        string state;
        string phone;
        string zip;
    public:
        //Default constructor
        PersonalData() {lastNm=firstNm=address=city=state=phone=zip="";}
        //Constructor
        PersonalData(string,string,string,string,string,string,string);
        //setter
        void setLN(string ln) {lastNm=ln;}
        void setFN(string fn) {firstNm=fn;}
        void setAddr(string a) {address=a;}
        void setCity(string c) {city=c;}
        void setStat(string s) {state=s;}
        void setPhon(string p) {phone=p;}
        void setZip(string z) {zip=z;}
        //getter
        string getLN() const {return lastNm;}
        string getFN() const {return firstNm;}
        string getAddr() const {return address;}
        string getCity() const {return city;}
        string getStat() const {return state;}
        string getPhon() const {return phone;}
        string getZip() const {return zip;}
        void pntInfo() const;//print out information
};

#endif	/* PERSONALDATA_H */

