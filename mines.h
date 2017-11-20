#ifndef MINES_H_INCLUDED
#define MINES_H_INCLUDED

#include "elementGrille.h"

int coordonneesExisteDeja(int x, int y, ElementGrille** grille); //Verifier s'il y a une mine a l'endroit (x,y) de la grille
void genererMines(ElementGrille** grille, int taille, int nbMines);//Remplir la grille de mines

#endif // MINES_H_INCLUDED
