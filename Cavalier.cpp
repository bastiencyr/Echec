/* 
 * File:   Cavalier.cpp
 * Author: bastien
 * 
 * Created on 10 mars 2020, 17:47
 */
#include <string>
#include "Cavalier.h"
#include "Square.h"
#include "Piece.h"
#include "erreur.h"
#include <cmath>

using namespace std;

Cavalier::Cavalier(Couleur name, string color, Square position)
: Piece(name, color, position) {
}

/**
 * @brief Cette fonction vérifie si le mouvement du cavalier est légal
 * 
 * @param newSquare case sur la laquelle l'utilsateur souhaite déplacer son 
 * cavalier
 * 
 * @param echiquier
 * 
 * @return OK_SET si le mouvement est légal et ERR_ILLMOVE sinon.
 */

RetCode Cavalier::est_mouvement_legal(Square newSquare, Echiquier &echiquier){
			
	Square oldSquare = (*this).getPosition();
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	int oldAbs = oldSquare.getAbs(), oldOrd = oldSquare.getOrd();
	
	echiquier.getPiece(newAbs,newOrd);

	if (abs(newAbs-oldAbs)==2 && ((abs(newOrd-oldOrd))==1))
		return OK_SET;
	
	if (abs(newOrd-oldOrd)==2 && ((abs(newAbs-oldAbs))==1))
		return OK_SET;			
	
	return ERR_ILLMOVE;
}

/*
 Cavalier::Cavalier(const Cavalier& orig) {
 }
 
 Cavalier::~Cavalier() {
 }
 */