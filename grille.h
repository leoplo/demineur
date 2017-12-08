#include "elementGrille.h"
#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

ElementGrille** nouvelleGrille(int taille, int nbMines);
ElementGrille** remplirGrille(int taille);
void remplirTab(char* tab, int taille, char c);
void definirLigneSeparatrice(char* ligne, int taille);
char intToChar(int n);
char afficherCase(ElementGrille e);
void afficherGrille(ElementGrille** grille, int taille);
int presenceMine(int x, int y, ElementGrille** grille, int taille);
void placerDrapeau(ElementGrille** grille, int* coordonnes);
void enleverDrapeau(ElementGrille** grille, int* coordonnes);
int revelerCase(ElementGrille** grille, int * coordonnes, int taille);
int existe(int x, int y, int taille);
void minesAdjacentes(ElementGrille** grille, int x, int y, int taille);

void sauvegardeGrille(char* nomFichier, ElementGrille** grille, int tailleGrille);
ElementGrille** chargerGrille(char* nomFichier, int tailleGrille);

#endif // GRILLE_H_INCLUDED
