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

/**
 * @brief Cette fonction vérifie la légalité d'un mouvement du fou. Elle
 * appelle la fonction diagonale qui vérifie le mouvement.
 *  
 * @param newSquare est la case sur laquelle le fou veut se déplacer
 * @param echiquier
 * @return OK_SET si le mouvement est légal et une erreur appropriée sinon :
 * Les erreurs sont :
 * ERR_ILLMOVE si le mouvement est illégale
 * ERR_ON_WAY si une pièce est sur le chemin
 */

RetCode Fou::est_mouvement_legal(Square newSquare, Echiquier &echiquier){
	
	Square oldSquare = (*this).getPosition();
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	int oldAbs = oldSquare.getAbs(), oldOrd = oldSquare.getOrd();
	
	//on evite la division par 0 qui peut survenir après
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