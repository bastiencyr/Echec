/* 
 * File:   Tour.cpp
 * Author: bastien
 * 
 * Created on 4 mars 2020, 18:42
 */
#include <math.h>  
#include <string>

#include "Tour.h"
#include "erreur.h"

using namespace std;

Tour::Tour(Couleur name, string color, Square position)
: Piece(name, color, position) {
}

RetCode Tour::est_mouvement_legal(Square newSquare, Echiquier &echiquier){
	
	Square oldSquare = (*this).getPosition();
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	int oldAbs = oldSquare.getAbs(), oldOrd = oldSquare.getOrd();
	
	//deplacement horizontaux
	if (newOrd==oldOrd){
		return (*this).horizontale(newSquare, oldAbs, oldOrd, echiquier);
	}
	
	//deplacement verticaux
	if (newAbs==oldAbs){
		return (*this).verticale(newSquare, oldAbs, oldOrd, echiquier);
	}
	
	return ERR_ILLMOVE;
}

/*

Tour::Tour(const Tour& orig) {
}

Tour::~Tour() {
}
*/