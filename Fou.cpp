/* 
 * File:   Fou.cpp
 * Author: bastien
 * 
 * Created on 10 mars 2020, 23:29
 */
#include <cmath>
#include <string>

#include "Fou.h"
#include "erreur.h"
using namespace std;

Fou::Fou(Couleur name, string color, Square position)
: Piece(name, color, position) {
}

RetCode Fou::est_mouvement_legal(Square newSquare, Echiquier &echiquier){
	
	Square oldSquare = (*this).getPosition();
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	int oldAbs = oldSquare.getAbs(), oldOrd = oldSquare.getOrd();
	
	//on evite la division par 0 ensuite
	if (newAbs==oldAbs)
		return ERR_ILLMOVE;
	
	//deplacement diagonaux
	if (abs(((double)(newOrd-oldOrd))/((double)(newAbs-oldAbs)))==1)
		return (*this).diagonale(newSquare, oldAbs, oldOrd, echiquier);
		
	return ERR_ILLMOVE;
}

/*
 Fou::Fou(const Fou& orig) {
 }
 
 Fou::~Fou() {
 }
 
 */