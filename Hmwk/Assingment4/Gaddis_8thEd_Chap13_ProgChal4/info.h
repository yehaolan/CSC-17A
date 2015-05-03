/* 
 * File:   PsnInfo.h
 * Author: admin
 *
 * Created on May 2, 2015, 3:37 PM
 */

#ifndef INFO_H
#define	INFO_H

//System libraries
#include <cstring>

class info {
    private:
        char *name;
        char *address;
        char *number;
        int age;
    public:
        info(char *,char *,char *,int);//constructor
        ~info();//destructor
        void setName(char *);//set the name
        void setAddr(char *);//set the address
        void setNum(char *);//set the number
        void setAge(int);//set the age
        void pntInfo() const;//print out information
        char *getName() const {return name;}//get the name
        char *getAddr() const {return address;}//get the address
        char *getNum() const{return number;}//get the number
        int getAge() const {return age;}//get the age
};

#endif	/* INFO_H */

