/* 
 * File:   Pion.h
 * Author: bastien
 *
 * Created on 11 mars 2020, 00:06
 */

#ifndef PION_H
#define PION_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Piece.h"                                                                                                                                                                                                                                                                                                                           
#include"Square.h"
#include "Echiquier.h"
#include "erreur.h"

class Pion : public Piece {
    public:
        Pion(Couleur name, string color, Square position);
        // Pion(const Pion& orig);
        //virtual ~Pion();
        
        RetCode est_mouvement_legal(Square newSquare, Echiquier &echiquier);
       
    private:
            bool first_move;
            
};

#endif /* PION_H */

