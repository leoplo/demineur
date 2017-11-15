#include "elementGrille.h"
#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

ElementGrille** remplirGrille(); //Cr�ation tableau de structure(ElementGrille)
void remplirGrilleAvecMine(ElementGrille** grille, int** mines, int taille); //Modif attribut "presenceMine" de chaque �l�ment selon le tableau de mines
void lireGrille(ElementGrille** grille, int taille); //afficher chaque �l�ment du tableau de structure
ElementGrille** nouvelleGrille(int taille);
void remplirTab(char* tab, int taille, char c);
char afficherCase(ElementGrille e);
void definirLigneSeparatrice(char* ligne, int taille);
char afficherCase(ElementGrille e);
char afficherCase(ElementGrille e);
int presenceMine(int x, int y, ElementGrille** grille);


#endif // GRILLE_H_INCLUDED

