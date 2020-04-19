/* 
 * File:   Fou.h
 * Author: bastien
 *
 * Created on 10 mars 2020, 23:29
 */


#ifndef FOU_H
#define FOU_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Piece.h"
#include "Square.h"
#include "erreur.h"


class Fou : public Piece {
    public:
        Fou(Couleur name, string color, Square position );
        //Fou(const Fou& orig);
        //virtual ~Fou();
        RetCode est_mouvement_legal(Square newSquare, Echiquier &echiquier);
        private:
            
};

#endif /* FOU_H */

