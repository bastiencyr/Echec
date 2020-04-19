/* 
 * File:   Dame.h
 * Author: bastien
 *
 * Created on 10 mars 2020, 23:30
 */


#ifndef DAME_H
#define DAME_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Piece.h"
#include "Square.h"
#include "erreur.h"

class Dame : public Piece {
    public:
        Dame(Couleur name, string color, Square position );
        //Dame(const Dame& orig);
        //virtual ~Dame();
        RetCode est_mouvement_legal(Square newSquare, Echiquier &echiquier);
        private:
            
};

#endif /* DAME_H */

