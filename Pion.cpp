/* 
 * File:   Pion.cpp
 * Author: bastien
 * 
 * Created on 11 mars 2020, 00:06
 */

#include <cmath>
#include <string>

#include "Pion.h"
#include "Piece.h"  
#include"Square.h"
#include "erreur.h"

using namespace std;

Pion::Pion(Couleur name, string color, Square position)
: Piece(name, color, position), first_move(true) {
}

RetCode Pion::est_mouvement_legal(Square newSquare, Echiquier &echiquier){
	
	Square oldSquare = (*this).getPosition();
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	int oldAbs = oldSquare.getAbs(), oldOrd = oldSquare.getOrd();
	
	//vérifie mouvement devant
	if(newAbs==oldAbs){
		
		if (color_== Blanc){
			if (echiquier.getPiece(newAbs,newOrd)==NULL){
				
				if (newOrd==oldOrd+1)
					return OK_SET;
				
				if (newOrd==oldOrd+2 && first_move == true){
					first_move= false;
					return OK_SET;
				}
			}
			
			return ERR_ILLMOVE;
		}
		
		
		if (color_== Noir){
			if (echiquier.getPiece(newAbs,newOrd)==NULL){
				
				if(newOrd==oldOrd-1)
					return OK_SET;
				
				if( newOrd==oldOrd-2 && first_move == true){
					first_move =false;
					return OK_SET;
				}
			}
			return ERR_ILLMOVE;
		}
		
		//le pion a avancé de plus qu'une case
		return ERR_ILLMOVE;	
	}
	
	//vérifie mouvement diagonal blanc
	if (color_ == Blanc)
		if ((newOrd == oldOrd +1 && (newAbs==oldAbs+1 or newAbs == oldAbs-1))){
			
			if (echiquier.getPiece(newAbs, newOrd)!=NULL)
				return OK_SET;
			
			//Déplacement diag sur une case vide
			return ERR_ILLMOVE;
		}
	
	//vérifie mvt diagonale noir
	if (color_ == Noir)
		if ((newOrd == oldOrd -1 && (newAbs==oldAbs+1 or newAbs == oldAbs-1))){
			
			if (echiquier.getPiece(newAbs, newOrd)!=NULL)
				return OK_SET;
			
			//deplacement diagonale sur une case vide
			return ERR_ILLMOVE;
		}
	
	return ERR_ILLMOVE;
}

/**
 Pion::Pion(const Pion& orig) {
 }
 
 Pion::~Pion() {
 }
 **/
