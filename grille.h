#include "elementGrille.h"
#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

ElementGrille** nouvelleGrille(int taille);
ElementGrille** remplirGrille(); //Cr�ation tableau de structure(ElementGrille)
void remplirGrilleAvecMine(ElementGrille** grille, int** mines, int taille); //Modif attribut "presenceMine" de chaque �l�ment selon le tableau de mines
void lireGrille(ElementGrille** grille, int taille); //afficher chaque �l�ment du tableau de structure
void remplirTab(char* tab, int taille, char c);
void definirLigneSeparatrice(char* ligne, int taille);
char afficherCase(ElementGrille e);
void afficherGrille(ElementGrille** grille, int taille);
int presenceMine(int x, int y, ElementGrille** grille, int taille);
void placerDrapeau(ElementGrille** grille, int* coordonnes);
void enleverDrapeau(ElementGrille** grille, int* coordonnes);
int revelerCase(ElementGrille** grille, int * coordonnes, int taille);
int existe(int x, int y, int taille);
void minesAdjacentes(ElementGrille** grille, int x, int y, int taille);

#endif // GRILLE_H_INCLUDED

