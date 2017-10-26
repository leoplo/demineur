#include "elementGrille.h"
#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

char* ligneSeparatrice(int);
void afficherGrille(int, char**);
ElementGrille** remplirGrille(); //Création tableau de structure(ElementGrille)
void remplirGrilleAvecMine(ElementGrille** grille, int** mines, int taille); //Modif attribut "presenceMine" de chaque élément selon le tableau de mines
void lireGrille(ElementGrille** grille, int taille); //afficher chaque élément du tableau de structure

#endif // GRILLE_H_INCLUDED

