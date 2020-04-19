/* 
 * File:   Piece.cpp
 * Author: bastien
 * 
 * Created on 14 février 2020, 16:25
 */

#include "Piece.h"
#include "Square.h"
#include "Echiquier.h"
#include "erreur.h"

#include <cmath>
#include <string>
using namespace std;

Piece::Piece(Couleur color, string name, Square position) 
: color_(color), name_(name), position_(position) {
}

string Piece::getName() const{
	return name_;
}

Couleur Piece::getColor () const{
	return color_;
}

Square Piece::getPosition() const{
	return position_;
}

void const Piece::affiche(){
	cout <<name_;
}

void Piece::change(int abs, int ord){
	position_.change(abs, ord);
}


/**
 * @brief Vérifie la légalité d'un mouvement entre deux pièces situés sur 
 * une vertivale. C'est à la fonction appelante de s'assurer que les deux 
 * pièces sont bien sur une verticale.
 * 
 * @param newSquare est la pièce de destination
 * @param oldAbs
 * @param oldOrd
 * @param echiquier
 * @return OK_SET si le mouvement est légal, ERR_ON_WAY si une pièce est entre 
 * la pièce d'origine et celle de destination et ERR_UNKNOWN s'il est survenu
 * une erreur.
 */

RetCode Piece::verticale(Square newSquare,int oldAbs, int oldOrd, Echiquier &echiquier){
	
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	
	if (oldOrd<newOrd){
		while(oldOrd!=newOrd-1){
			oldOrd++;
			if((echiquier.getPiece(newAbs, oldOrd))!=NULL)
				return ERR_ON_WAY;
		}	
		return OK_SET;
	}
	else{
		while(oldOrd!=newOrd+1){
			oldOrd--;
			if((echiquier.getPiece(oldAbs, oldOrd))!=NULL)
				return ERR_ON_WAY;
		}
		return OK_SET;
	}
	
	return ERR_UNKNOWN;
}


/**
 * @brief Vérifie la légalité d'un mouvement entre deux pièces situés sur 
 * une ligne. C'est à la fonction appelante de s'assurer que les deux 
 * pièces sont bien sur une ligne.
 * 
 * @param newSquare est la pièce de destination
 * @param oldAbs
 * @param oldOrd
 * @param echiquier
 * @return OK_SET si le mouvement est légal, ERR_ON_WAY si une pièce est entre 
 * la pièce d'origine et celle de destination et ERR_UNKNOWN s'il est survenu
 * une erreur.
 */

RetCode Piece::horizontale(Square newSquare, int oldAbs, int oldOrd, Echiquier &echiquier){
	
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	
	if (oldAbs<newAbs){
		while(oldAbs!=newAbs-1){
			oldAbs++;
			if((echiquier.getPiece(oldAbs, oldOrd))!=NULL)
				return ERR_ON_WAY;
		}
		return OK_SET;
	}
	
	else{
		while(oldAbs!=newAbs+1){
			oldAbs--;
			if((echiquier.getPiece(oldAbs, oldOrd))!=NULL)
				return ERR_ON_WAY;
		}
		return OK_SET;
	}
	return ERR_UNKNOWN;
}


/**
 * @brief Vérifie la légalité d'un mouvement entre deux pièces situés sur 
 * une diagonale. C'est à la fonction appelante de s'assurer que les deux 
 * pièces sont bien sur une diagonale.
 * 
 * @param newSquare est la pièce de destination
 * @param oldAbs
 * @param oldOrd
 * @param echiquier
 * @return OK_SET si le mouvement est légal, ERR_ON_WAY si une pièce est entre 
 * la pièce d'origine et celle de destination et ERR_UNKNOWN s'il est survenu
 * une erreur.
 */

RetCode Piece::diagonale(Square newSquare, int oldAbs, int oldOrd, Echiquier &echiquier){
	
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	
	if (oldAbs<newAbs && oldOrd<newOrd){
		while (oldAbs!=newAbs-1){
			oldAbs++; oldOrd++;
			if((echiquier.getPiece(oldAbs, oldOrd))!=NULL)
				return ERR_ON_WAY;
		}
		return OK_SET;
	}
	
	if (oldAbs<newAbs && oldOrd>newOrd){
		while (oldAbs!=newAbs-1){
			oldAbs++; oldOrd--;
			if((echiquier.getPiece(oldAbs, oldOrd))!=NULL)
				return ERR_ON_WAY;
		}
		return OK_SET;
	}
	
	if (oldAbs>newAbs && oldOrd<newOrd){
		while (oldAbs!=newAbs+1){
			oldAbs--; oldOrd++;
			if((echiquier.getPiece(oldAbs, oldOrd))!=NULL)
				return ERR_ON_WAY;
		}
		return OK_SET;
	}
	
	if (oldAbs>newAbs && oldOrd>newOrd){
		while (oldAbs!=newAbs+1){
			oldAbs--; oldOrd--;
			if((echiquier.getPiece(oldAbs, oldOrd))!=NULL)
				return ERR_ON_WAY;
		}
		return OK_SET;
	}
	
	return ERR_UNKNOWN;
	
}
/**
 * @brief Cette fonction fait quelques vérifications d'ordre générale.
 *  
 * @param newSquare la case de destination.
 * @param echiquier
 * @return OK_SET si le ùouvement est légal et ERR_SAME_COLOR si le pièce 
 * d'origine est de la même couleur que la pièce de destination.
 */

RetCode Piece::est_mouvement_legal(Square newSquare, Echiquier &echiquier){
	
	Square oldSquare = (*this).getPosition();
	int newAbs = newSquare.getAbs(), newOrd = newSquare.getOrd();
	int oldAbs = oldSquare.getAbs(), oldOrd = oldSquare.getOrd();
	
	if(echiquier.getPiece(newAbs, newOrd) != NULL
			&& echiquier.getPiece(oldAbs, oldOrd)!=NULL 
			&& echiquier.getPiece(oldAbs, oldOrd)->getColor()
			== echiquier.getPiece(newAbs, newOrd)->getColor())
		return ERR_SAME_COLOR;
	
	return OK_SET; 
}



/*
 
 Piece::Piece(const Piece& orig) {
 }
 
 Piece::~Piece() {
 }
 */