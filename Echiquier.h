/* 
 * File:   echiquier.h
 * Author: bastien
 *
 * Created on 4 mars 2020, 18:28
 */

#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"
#include "erreur.h"
#include"Square.h"

using namespace std;
class Piece ;

class Echiquier {
public:
    Echiquier();
    //Echiquier(const echiquier& orig);
    //virtual ~echiquier();
    
    Piece * getPiece (int abs, int ord) const;
    void affiche () const;
    bool deplace(string coup);
    RetCode est_en_echec();
    RetCode affiche_mouvement_legal(string coup);
    
private:
    Piece * echiquier[8][8];
    //Square roi_b;
    //Square roi_n;
};

#endif /* ECHIQUIER_H */

