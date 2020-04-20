/* 
 * File:   Jeu.cpp
 * Author: bastien
 * 
 * Created on 11 mars 2020, 23:28
 */

#include "Jeu.h"
#include "Echiquier.h"
#include "Piece.h"
#include <regex>

/**
 * @brief Initialise un jeu. La couleur est initiaisé à noir car ce sont les 
 * blancs qui commencent.
 */
//Jeu::Jeu() : coup_(""){
Jeu::Jeu(){
	Echiquier echiquier;
	echiquier_ = echiquier;
	couleur_=Noir;
}


Echiquier Jeu::getEchiquier(){
	return echiquier_;
}

/**
 * @brief vérifie si un coup est légal 
 * 
 * @return 
 */

void Jeu::affiche(){
	(*this).getEchiquier().affiche();
}


bool Jeu::saisie_correcte(string const & cmd) {
	regex mouvmtpattern("[a-h][1-8][a-h][1-8]");
    return regex_match(cmd,mouvmtpattern);
}

/**
 * @brief 
 * Donne la couleur du pion de depart
 * @param mouvement
 * @return 
 */

Couleur Jeu::donneCouleur(string const & mouvement){
	
	string orig = mouvement.substr(0, 2);
	Square coordOrig (orig);
	int abs=coordOrig.getAbs(), ord=coordOrig.getOrd();
	return this->getEchiquier().getPiece(abs,ord)->getColor();
}

bool Jeu::est_mon_tour(Couleur & newCouleur){
	if (couleur_!=newCouleur)
		return true;
	
	cout << "Ce n'est pas ton tour !" << endl;
	return false;
}

void Jeu::changeCouleur(){
	couleur_ = (couleur_== Blanc) ? Noir : Blanc;
}

RetCode Jeu::estcasevide(string & mouvement){
	Square origInt(mouvement.substr(0, 2));
	
	if ((echiquier_.getPiece(origInt.getAbs(),origInt.getOrd())==NULL)){
		cout << "Il faut sélectionner un pion de départ" <<endl;
		return ERR_NOPIECE ;
	}
	
	return OK_SET;
}

void Jeu::deplace(string &mouvement){
	echiquier_.deplace(mouvement);
}

string Jeu::reverseMouvement(string &mouvement){
	return mouvement.substr(2, 4)+ mouvement.substr(0, 2);
}

bool Jeu::afficheJeuEtEchec(string &mouvement, Couleur &newCouleur){
	
	string reverse =  mouvement.substr(2, 4)+ mouvement.substr(0, 2);
	
	switch (echiquier_.est_en_echec()){
		
		case ROI_MORT :
			cout << "Un roi est mort" << endl;
			return false;	
			break;
		
		case NO_ECHEC :
			(*this).affiche();
			(*this).changeCouleur();
			return true;
			break;
			
		case ECHEC_BLANC :
			if (newCouleur == Noir){
				(*this).affiche();
				cout << "Le roi blanc est en échec" << endl;
				(*this).changeCouleur();
				return true;
			}
			//les blancs se sont mis en échec, il faut annuler le coup
			(*this).deplace(reverse);
			cout << "Les blancs se mettent en échec" <<endl;
			return true;
			break;
			
		case ECHEC_NOIR :
			
			if (newCouleur == Blanc){
				(*this).affiche();
				(*this).changeCouleur();
				cout << "Le roi noir est en échec" << endl;
				return true;
			}
			//les noirs se sont mis en échec, il faut annuler le coup
			(*this).deplace(reverse);
			cout << "Les Noirs se mettent en échec" <<endl;
			return true;	
			break;
			
		default :
			cout << "Une erreur inconnue est survenue" << endl;
			return false;
	}
	
	return false;
}

/*
Jeu::Jeu(const Jeu& orig) {
}

Jeu::~Jeu() {
}
*/

