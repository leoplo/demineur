#include "elementGrille.h"
#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elementGrille.h"

void remplirTab(char* , int, char);

void definirLigneSeparatrice(char*, int);

void afficherGrille(int, char**);

<<<<<<< Updated upstream
char* ligneSeparatrice(int);
void afficherGrille(int, char**);
ElementGrille** remplirGrille(); //Cr�ation tableau de structure(ElementGrille)
void remplirGrilleAvecMine(ElementGrille** grille, int** mines, int taille); //Modif attribut "presenceMine" de chaque �l�ment selon le tableau de mines
void lireGrille(ElementGrille** grille, int taille); //afficher chaque �l�ment du tableau de structure
=======
void RemplirGrille();
>>>>>>> Stashed changes

#endif // GRILLE_H_INCLUDED

