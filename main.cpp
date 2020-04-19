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
	
	Jeu monjeu;  // initialise le jeu
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
			
			//verfie si la case de départ n'est pas vide
			if (monjeu.estcasevide(mouvement)!=true){
				newCouleur = monjeu.donneCouleur(mouvement);
				
				//vérifie si c'est bien le tour du joueur
				if (monjeu.est_mon_tour(newCouleur)==true && 
						monjeu.getEchiquier().affiche_mouvement_legal(mouvement)==OK_SET){
					
					monjeu.deplace(mouvement);
					monjeu.affiche();
					monjeu.getEchiquier().est_en_echec();
					monjeu.changeCouleur();
				}
			}
		}
	}
	
	cout << "Jeu Terminé !!"<<endl;
}

