/* 
 * File:   Roi.cpp
 * Author: bastien
 * 
 * Created on 10 mars 2020, 23:30
 */
#include "stdlib.h"
#include <string>
#include <cmath>
#include "Roi.h"
#include "Square.h"
#include "Echiquier.h"
#include "Piece.h"
#include "erreur.h"
using namespace std;

Roi::Roi(Couleur name, string color, Square position)
: Piece(name, color, position) {
}

RetCode Roi::est_mouvement_legal(Square newSquare, Echiquier &echiquier){
	
	Square oldSquare = (*this).getPosition();
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	int oldAbs = oldSquare.getAbs(), oldOrd = oldSquare.getOrd();
	
	return ( pow(newAbs-oldAbs, 2) + pow(newOrd-oldOrd,2) ==1) or 
		(pow(newAbs-oldAbs, 2) + pow(newOrd-oldOrd,2)==2 ) ?
		OK_SET : ERR_ILLMOVE ;
	
}


/*
 Roi::Roi(const Roi& orig) {
 }
 
 Roi::~Roi() {
 }
 */