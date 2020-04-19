/* 
 * File:   echiquier.cpp
 * Author: bastien
 * 
 * Created on 4 mars 2020, 18:28
 */

#include "Piece.h"

#include "Echiquier.h"
#include "Tour.h"
#include "Piece.h"
#include "Cavalier.h"
#include "Fou.h"
#include"Roi.h"
#include"Dame.h"
#include"Pion.h"
#include "erreur.h"
#include "Square.h"

#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

Echiquier::Echiquier() {
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			echiquier[i][j] = NULL; 
		}
	}

    echiquier[0][0] = new Tour		(Blanc," \u2656 ",  Square(0,0));
	echiquier[1][0] = new Cavalier	(Blanc," \u2658 ",  Square(1,0));
    echiquier[2][0] = new Fou		(Blanc," \u2657 ",  Square(2,0));
    echiquier[3][0] = new Dame		(Blanc," \u2655 ",  Square(3,0));
    echiquier[4][0] = new Roi		(Blanc," \u2654 ",  Square(4,0));
    echiquier[5][0] = new Fou		(Blanc," \u2657 ",  Square(5,0));
    echiquier[6][0] = new Cavalier	(Blanc," \u2658 ",  Square(6,0));
    echiquier[7][0] = new Tour		(Blanc," \u2656 ",  Square(7,0));
	
	
	echiquier[0][7] = new Tour		(Noir," \u265C ",  Square(0,7));
	echiquier[1][7] = new Cavalier	(Noir," \u265E ",  Square(1,7));
    echiquier[2][7] = new Fou		(Noir," \u265D ",  Square(2,7));
    echiquier[3][7] = new Dame		(Noir," \u265B ",  Square(3,7));
    echiquier[4][7] = new Roi		(Noir," \u265A ",  Square(4,7));
    echiquier[5][7] = new Fou		(Noir," \u265D ",  Square(5,7));
    echiquier[6][7] = new Cavalier	(Noir," \u265E ",  Square(6,7));
    echiquier[7][7] = new Tour		(Noir," \u265C ",  Square(7,7));
	
	for (int j=0; j<8; j++){
		echiquier[j][1]=new Pion(Blanc, " \u2659 ", Square(j,1));
		echiquier[j][6]=new Pion(Noir, " \u265F ", Square(j,6));
		
	}
}

/**
 * @brief Cette fonction retourne la pièce demandée en argument. 
 * C'est à la fonction appelante de s'assurer que la pièce demandée est 
 * hors-jeu. Sinon, le programme est quitté (comportement non souhaité).
 * 
 * @param abs 
 * @param ord
 * @return La pièce de coordonnées (abs, ord) si elle existe et quitte le jeu
 * avec un EXIT_FAILURE si une erreur est arrivée. 
 */

Piece* Echiquier::getPiece(int abs, int ord) const {
	if (abs>=8 or abs <0 or ord >=8 or ord <0){
		cout << "Tentative d'accès à une pièce hors-jeu"<<endl;
		exit (EXIT_FAILURE);
	}
	return echiquier[abs][ord];
}

/**
 * @brie Cette fonction récupère le code de retour de la 
 * méthode est_mouvement_legal afin d'afficher une erreur appropriée.  
 * 
 * @param coup est une chaine de type "a1a2". C'est le mouvement entré 
 * par l'utilisateur.
 * @return Elle retourne OK_SET si le mouvement est légal et un code de 
 * retour appropprié sinon. Le code de retour est forcément un des cas 
 * du switch.
 */

RetCode Echiquier::affiche_mouvement_legal(string mouvement){
	string oldS = mouvement.substr(0, 2), newS = mouvement.substr(2, 4);
	
	Square oldSquare(oldS), newSquare(newS);
	int oldAbs=oldSquare.getAbs(), oldOrd=oldSquare.getOrd();
	int newAbs=newSquare.getAbs(), newOrd=newSquare.getOrd();
	
	RetCode ret = echiquier[oldAbs][oldOrd]->
			Piece::est_mouvement_legal(newSquare, *this);
	
	if (ret == OK_SET )
		ret = echiquier[oldAbs][oldOrd]->
				est_mouvement_legal(newSquare, *this);
	
	switch (ret){
		
		case ERR_NOPIECE:
			cout << "Vous n'avez sélectionné aucune pièce de départ"<< endl;
			break;
			
		case ERR_OCCUPIED :        
            cout << "Case destination déjà occupée"<< endl;
			break;
			
		case ERR_ON_WAY :         
            cout << "Une pièce est sur le chemin"<<endl;
			break;
			
		case ERR_DIAG_MOVE :     
			cout << "Erreur mouvement pion en diagonal" <<endl;
			break;
			
		case ERR_ILLMOVE : 
			cout << "Mouvement illégal"<<endl;
			break;
			
		case ERR_SAME_COLOR :
			cout << "Tu ne peux pas manger une pièce de ton propre camp" <<endl;
			break;
            
		case ERR_UNKNOWN :
			cout << "L'impossible est arrivée, erreur inconnue" << endl;
			break;
	}
	
	return ret;
}

/**
 * @brief Cette fonction deplace une pièce selon le mouvement donné. Pour cela,
 * la case d'arrivée pointe sur la case de départ et la case de 
 * départ sur NULL.
 * 
 * @param mouvement de type "a1a2". C'est à la fonction appelante de s'assurer
 * que le mouvement n'est pas hors-jeu.
 * 
 * @return true
 */
bool Echiquier::deplace(string mouvement){
	
	string oldS = mouvement.substr(0, 2), newS = mouvement.substr(2, 4);
	
	Square oldSquare(oldS), newSquare(newS);
	int oldAbs=oldSquare.getAbs(), oldOrd=oldSquare.getOrd();
	int newAbs=newSquare.getAbs(), newOrd=newSquare.getOrd();
	
	echiquier[newAbs][newOrd]=echiquier[oldAbs][oldOrd];
	echiquier[newAbs][newOrd]->change(newAbs, newOrd);
	echiquier[oldAbs][oldOrd]=NULL;
	
	return true;	
}

/**
 * @brief Cette fonction vérifie si un roi est en echec. Pour cela, elle simule
 * une attaque de tous les joueurs adverses sur chaque roi. 
 * 
 * @return 
 * ROI_MORT si le roi a été mangé.
 * ECHEC_BLANC si le roi blanc est en échec
 * ECHEC_NOIR si le roi noir est en échec
 * ERR_UNKNOWN si une erreur inconnue est survenue. C'est alors à la fonction 
 * appelante de mettre fin au jeu.
 *  
 */

RetCode Echiquier::est_en_echec(){
	
	int abs_roi_n=-1, ord_roi_n=-1;
	int abs_roi_b=-1, ord_roi_b=-1;
	
	for (int i=0 ; i<8; i++)
		for(int j=0 ; j<8; j++){
			if (echiquier[i][j]!=NULL 
					&& echiquier[i][j]->getName()== " \u265A "){
				abs_roi_n = i;
				ord_roi_n = j;
			}
			
			if (echiquier[i][j]!=NULL 
					&& echiquier[i][j]->getName()== " \u2654 "){
				abs_roi_b = i;
				ord_roi_b = j;
			}
		}
	
	if (abs_roi_n==-1 or abs_roi_b==-1 ){
		cout << "Le roi est mort ce soir"<<endl;
		return ROI_MORT;
	}
	
	for(int k=0 ; k<8; k++)
		for (int l=0; l<8 ; l++){
			if (echiquier[k][l]!=NULL 
					&& echiquier[k][l]->getColor()==Noir 
					&& echiquier[k][l]->
					est_mouvement_legal(echiquier[abs_roi_b][ord_roi_b]->getPosition(), *this)==OK_SET){
				cout << "Le roi blanc est en échec " << endl;
				return ECHEC_BLANC;
			}
			
			if (echiquier[k][l]!=NULL 
					&& echiquier[k][l]->getColor()==Blanc
					&& echiquier[k][l]->
					est_mouvement_legal(echiquier[abs_roi_n][ord_roi_n]->getPosition(), *this)==OK_SET){
				cout << "Le roi Noir est en échec" << endl;
				return ECHEC_NOIR;
			}
		}
	
	return NO_ECHEC;
	
}

void Echiquier::affiche () const{
	
	int NBCOL = 8;
	
	string space5 = string(6,' ');
	cout << endl;
	cout << "      a      b      c      d      e      f      g      h    "<< endl;
	cout << "  +------+------+------+------+------+------+------+------+" << endl;
	for (int i(NBCOL-1);i>=0;i--) {
		cout << i+1 << " "; // numérotation ligne dans affichage
		for (int j(0);j<NBCOL;j++) {
			cout << "|" ;
			if (echiquier[j][i]!=NULL) { 
				cout << "\u0020";  //U+0020 est un esapce utf-8 taille police
				echiquier[j][i]-> affiche();
				cout << "\u0020" << " ";
			}
			else 
				cout << space5 ;  // 2 ascii spaces
		}
		cout << "|\n  +------+------+------+------+------+------+------+------+";
		
		cout << endl;
	}
	cout << "     a      b      c      d      e      f      g      h    "<< endl;
}

/*
 echiquier::echiquier(const echiquier& orig) {
 }
 */

/*
 Echiquier::~echiquier() {
	 free (echiquier[7][0]);
 }
 */