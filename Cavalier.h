/* 
 * File:   Cavalier.h
 * Author: bastien
 *
 * Created on 10 mars 2020, 17:47
 */


#ifndef CAVALIER_H
#define CAVALIER_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Piece.h"
#include "Square.h"
#include "erreur.h"
//#include "Echiquier.h"

class Cavalier : public Piece {
    public:
        Cavalier(Couleur name, string color, Square position );
        //virtual bool est_mouvement_legal(int new_abs, int new_ord, Echiquier &echiquier);
        
        //Cavalier(const Cavalier& orig);
        //virtual ~Cavalier();
        RetCode est_mouvement_legal(Square newSquare, Echiquier &echiquier);
        private:
            
};

#endif /* CAVALIER_H */

