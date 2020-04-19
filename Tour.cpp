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

/**
 * @brief Cette fonction vérifie la légalité d'un mouvement de la dame. Elle
 * appelle les fonctions horizontale et verticale qui vérifient
 * le mouvement.
 *  
 * @param newSquare est la case sur laquelle la tour veut se déplacer
 * @param echiquier
 * @return OK_SET si le mouvement est légal et une des erreurs suivantes sinon :
 * ERR_ILLMOVE si le mouvement est illégale
 * ERR_ON_WAY si une pièce est sur le chemin
 */

RetCode Tour::est_mouvement_legal(Square newSquare, Echiquier &echiquier){
	
	Square oldSquare = (*this).getPosition();
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	int oldAbs = oldSquare.getAbs(), oldOrd = oldSquare.getOrd();
	
	//vérifie deplacements horizontaux
	if (newOrd==oldOrd){
		return (*this).horizontale(newSquare, oldAbs, oldOrd, echiquier);
	}
	
	//vérifie deplacements verticaux
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