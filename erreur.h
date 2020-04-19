/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   erreur.h
 * Author: bastien
 *
 * Created on 6 avril 2020, 18:41
 */

#ifndef ERREUR_H
#define ERREUR_H

typedef enum { 
    OK_SET,                     // pose piece ok
            ERR_NOPIECE,        // pas de piece dans la case de départ
            ERR_OCCUPIED,       // case destination déjà occupée 
            ERR_ON_WAY,         // case occupée sur le chemin
            ERR_DIAG_MOVE,      // mouvement pion en diagonale
            ERR_ILLMOVE,        // mouvement illégal
            ERR_SAME_COLOR,     // mange une pièce de son propre camp
            ERR_UNKNOWN,        // erreur inconnu
            
} RetCode;

#endif /* ERREUR_H */

