/* 
 * File:   Dame.cpp
 * Author: bastien
 * 
 * Created on 10 mars 2020, 23:30
 */

#include <cmath>
#include <string>
#include "Dame.h"
#include "Piece.h"
#include "math.h"
#include "Echiquier.h"
#include "erreur.h"

using namespace std;

Dame::Dame(Couleur name, string color, Square position)
: Piece(name, color, position) {
}

/**
 * @brief Cette fonction vérifie la légalité d'un mouvement de la dame. Elle
 * appelle les fonctions horizontale, verticale et diagonale qui vérifie
 * le mouvement.
 *  
 * @param newSquare est la case sur laquelle la dame veut se déplacer
 * @param echiquier
 * @return OK_SET si le mouvement est légal et une erreur appropriée sinon :
 * Les erreurs sont :
 * ERR_ILLMOVE si le mouvement est illégale
 * ERR_ON_WAY si une pièce est sur le chemin
 */

RetCode Dame::est_mouvement_legal(Square newSquare, Echiquier &echiquier){
	
	Square oldSquare = (*this).getPosition();
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	int oldAbs = oldSquare.getAbs(), oldOrd = oldSquare.getOrd();
	
	//deplacement horizontaux
	if (newOrd==oldOrd)
		return (*this).horizontale(newSquare, oldAbs, oldOrd, echiquier);
	
	//deplacement verticaux
	if (newAbs==oldAbs)
		return (*this).verticale(newSquare, oldAbs, oldOrd, echiquier);
	
	//deplacement diagonaux
	if (abs((double)(newOrd-oldOrd)/(newAbs-oldAbs))==1)
		return (*this).diagonale(newSquare, oldAbs, oldOrd, echiquier);
	
	return ERR_ILLMOVE;
}


/*
 Dame::Dame(const Dame& orig) {
 }
 
 Dame::~Dame() {
 }
 */
