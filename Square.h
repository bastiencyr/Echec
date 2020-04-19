/* 
 * File:   Square.h
 * Author: bastien
 *
 * Created on 14 février 2020, 16:26
 */



#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Square {
public:
    
    Square(int abs, int ord);
    Square(string position);
    //Square(const Square& orig);
    //virtual ~Square();
    
    int getAbs() const;
    int getOrd() const;
    
    string toString() const;
    void change(int abs, int ord);
    
private:
    
    int abs_;
    int ord_;
};

#endif /* SQUARE_H */