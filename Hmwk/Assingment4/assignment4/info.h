/* 
 * File:   PsnInfo.h
 * Author: admin
 *
 * Created on May 2, 2015, 3:37 PM
 */

#ifndef INFO_H
#define	INFO_H


class info {
    private:
        string name;
        string address;
        string number;
        int age;
    public:
        info(string,string,string,int);//constructor
        void setName(string);//set the name
        void setAddr(string);//set the address
        void setNum(string);//set the number
        void setAge(int);//set the age
        void pntInfo() const;//print out information
        string getName() const {return name;}//get the name
        string getAddr() const {return address;}//get the address
        string getNum() const{return number;}//get the number
        int getAge() const {return age;}//get the age
};

#endif	/* INFO_H */

