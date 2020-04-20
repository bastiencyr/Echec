/* 
 * File:   main.cpp
 * Author: bastien
 *
 * Created on 14 février 2020, 14:31
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "Square.h"
#include "Piece.h"
#include"Echiquier.h"
#include "Jeu.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	
	Jeu monjeu;  // initialise le jeu jeu
    string mouvement;
    bool stop(true);
    monjeu.affiche();
	Couleur newCouleur=Noir;
	bool new_ec = false;
	bool old_ec = false;
	
    while (stop==true){
		
		cout << "Coup (eg. a1a8) ? " ;
		cin >> mouvement ;
		
		while( mouvement != "/quit" and 
				(stop = monjeu.saisie_correcte(mouvement))==false){
			cout << "Entrez un coup correct !" << endl;
			cout << "Coup (eg. a1a8) ? " ;
			cin >> mouvement ;
		}
		
		
		if (mouvement == "/quit")
			stop = false;
		
        else {
			
			//verfie si la case de départ n'est pas vide et affiche une erreur
			//si la case de départ est vide
			if (monjeu.estcasevide(mouvement)!=true){
				//newCouleur est la couleur de la nouvelle pièce
				newCouleur = monjeu.donneCouleur(mouvement);
				
				//vérifie si c'est bien le tour du joueur
				if (monjeu.est_mon_tour(newCouleur)==true && 
						monjeu.getEchiquier().affiche_mouvement_legal(mouvement)==OK_SET){
					
					monjeu.deplace(mouvement);	
					
					if(monjeu.getEchiquier().est_en_echec()==NO_ECHEC){
						monjeu.affiche();
						monjeu.changeCouleur();
					}
					
					if(monjeu.getEchiquier().est_en_echec()==ECHEC_BLANC &&
							newCouleur==Blanc){
						string reverse = monjeu.reverseMouvement(mouvement);
						monjeu.deplace(reverse);
						cout << "Les blancs se mettent en échec" <<endl;
					}
					
				}
			}
		}
	}
	
	cout << "Jeu Terminé !!"<<endl;
}

