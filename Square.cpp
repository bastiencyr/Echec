/* 
 * File:   Square.cpp
 * Author: bastien
 * 
 * Created on 14 février 2020, 16:26
 */

#include "Square.h"
using namespace std;

Square::Square(int abs, int ord) 
: abs_(abs), ord_(ord) {
}


Square::Square(string position){
	abs_=(int (position[0])) -97;
	ord_=(int (position[1])) -49;
}

int Square::getAbs() const{
	return abs_;
}

int Square::getOrd() const{
	return ord_;
}

string Square::toString() const{
	char strString[2];
	strString[0]=((*this).getAbs()+97);
	strString[1]=((*this).getOrd()+49);
	return strString;
}
void Square::change(int abs, int ord){
	abs_=abs;
	ord_=ord;
}



/*
 Square::Square(const Square& orig) {
 }
 
 Square::~Square() {
 }
 */