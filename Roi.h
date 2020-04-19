/* 
 * File:   Roi.h
 * Author: bastien
 *
 * Created on 10 mars 2020, 23:30
 */


#ifndef ROI_H
#define ROI_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Piece.h"
#include "Echiquier.h"
#include "Square.h"
#include "erreur.h"

class Roi : public Piece{
    public:
        Roi(Couleur name, string color, Square position );
        //Roi(const Roi& orig);
        //virtual ~Roi();
        RetCode est_mouvement_legal(Square newSquare, Echiquier &echiquier);
        
        private:
            
};

#endif /* ROI_H */

