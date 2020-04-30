# Introduction

Ce projet permet de créer un jeu d'échec virtuel pour deux joueurs.

# Compilation et execution

1. Se placer dans le répertoire principal
2. ouvrir un terminal dans ce dossier
3. Entrez "make" pour compiler le code
4. Puis entrez "./echecs/dist/Debug/GNU-Linux/echec"

Pour quitter le jeu, tapez "/quit".

Les fonctionnalités suivantes ne sont pas supportées : 

* le roque
* la prise en passant du pion 

# Description du code :

## Structure du code

Le code comporte les classes principales suivantes : 

* Jeu.cpp
* Echiquier.cpp
* Piece.cpp
* Square.cpp

Piece.cpp contient d'autres classes héritées qui sont les pièces du jeu telles que roi.cpp, fou.cpp...
