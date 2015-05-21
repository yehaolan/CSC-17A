/* 
 * File:   AbsCard.h
 * Author: admin
 * Created on May 13, 2015, 12:52 PM
 * Purpose: abstract class
 */
#ifndef ABSDECK_H
#define	ABSDECK_H

class AbsDeck {
    public:
        virtual void shuffle()=0;
        virtual int *deal()=0;
};

#endif	/* ABSDECK_H */

