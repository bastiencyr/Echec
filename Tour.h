/* 
 * File:   Tour.h
 * Author: bastien
 *
 * Created on 4 mars 2020, 18:42
 */



#ifndef TOUR_H
#define TOUR_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Piece.h"
#include "Square.h"
#include "erreur.h"

class Tour : public Piece {
    public:
        Tour(Couleur name, string color, Square position);
        //Tour(const Tour& orig);
        //virtual ~Tour();
        RetCode est_mouvement_legal(Square newSquare, Echiquier &echiquier);
        private:
};

#endif /* TOUR_H */

