#ifndef MINES_H_INCLUDED
#define MINES_H_INCLUDED

int** genererMines();//G�n�rer tableau de mines
int coordonneesExisteDeja(int x, int y, int ** tableau); //Verifier s'il y a une mine a l'endroit (x,y) du tableau
void afficherMines(int** mines, int taille); //afficher les bombes sous le format : "Bombe[x][y]"

#endif // MINES_H_INCLUDED
