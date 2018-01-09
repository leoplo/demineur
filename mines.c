#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mines.h"

int coordonneesExisteDeja(int x, int y, ElementGrille** grille) //renvoie 1 si le couple x,y existe déjà dans la grille
{
    if(grille[x][y].presenceMine == 1) // S'il y a une mine alors le couple x,y existe
    {
        return 1;
    }
    else{
        return 0;
    }
}

void genererMines(ElementGrille** grille, int taille, int nbMines)
{
    int i = nbMines, nbAleaX, nbAleaY;
    srand(time(NULL));

    while(i>0)
    {
        nbAleaX = rand()%taille; //coordonnée x aléatoire
        nbAleaY = rand()%taille; //coordonnée y aléatoire

        if(coordonneesExisteDeja(nbAleaX, nbAleaY, grille)) // Gestion des doublons
        {
            while(coordonneesExisteDeja(nbAleaX, nbAleaY, grille))
            {
                nbAleaX = rand()%taille; //coordonnée x aléatoire
                nbAleaY = rand()%taille; //coordonnée y aléatoire
            }
        }

        grille[nbAleaX][nbAleaY].presenceMine = 1;
        i--;
    }
}
