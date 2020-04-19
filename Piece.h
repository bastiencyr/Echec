/* 
 * File:   Piece.h
 * Author: bastien
 *
 * Created on 14 février 2020, 16:25
 */


#ifndef PIECE_H
#define PIECE_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Square.h"
#include "Echiquier.h"
#include "erreur.h"

class Echiquier ;
enum Couleur {Noir, Blanc};


class Piece {
public:  
    
    Piece(Couleur color, string name, Square position); 
    void const affiche(); 
    
    string getName() const;
    Couleur getColor()const ;
    Square getPosition() const;
    
    void change(int abs, int ord);
    
    virtual RetCode est_mouvement_legal(Square newSquare, Echiquier &echiquier);
    
    //renvoie true si aucune piece n'est entre (a,b) et (c,d) en sachant que la
    //droite passant par (a,b) et (c,d) est une diagonale de coeff 1 ou -1
    RetCode diagonale(Square newSquare, int oldAbs, int oldOrd, Echiquier &echiquier);
    
    
    //idem pour l'horizontale
    RetCode horizontale(Square newSquare, int oldAbs, int oldOrd, Echiquier &echiquier);
    
    //idem pour la verticale
    RetCode verticale(Square newSquare, int oldAbs, int oldOrd, Echiquier &echiquier);
    
    /*
     Piece(const Piece& orig);
     virtual ~Piece();
     */
    
protected:
    
    Couleur const color_;
    string const name_;
    Square position_;
    
};

#endif /* PIECE_H */

