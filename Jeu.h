/* 
 * File:   Jeu.h
 * Author: bastien
 *
 * Created on 11 mars 2020, 23:28
 */

#ifndef JEU_H
#define JEU_H

#include <string.h>
#include "Echiquier.h"
#include "Piece.h"
#include "erreur.h"
using namespace std;

class Jeu {
public:
    Jeu();
    Echiquier getEchiquier();
    void affiche();
    bool saisie_correcte(string const & cmd);
    Couleur donneCouleur(string const & mouvement);
    bool est_mon_tour(Couleur & newCouleur);
    void changeCouleur();
    RetCode estcasevide(string & mouvement);
    void deplace(string &mouvement);
    Jeu(const Jeu& orig);
    //virtual ~Jeu();
private:
    Echiquier echiquier_;
    Couleur couleur_;
};

#endif /* JEU_H */

