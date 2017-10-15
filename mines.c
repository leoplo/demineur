#include <stdlib.h>
#include "mines.h"

int coordonneesExisteDeja(int x, int y, int tableau[10][10]) //renvoie 1 si le couple x,y existe d�j� dans le tableau
{
    if(tableau[x][y] == 1) // S'il y a une mine alors le couple x,y existe
    {
        return 1;
    }
    else{
        return 0;
    }
}

int** GenererMines(int taille)//renvoie un tableau de mines (1 : il y a une bombe / 0 : il n'y a rien)
{
    int** mines;
    int nbBombes = 15;
    int i, j, nbAleaX, nbAleaY;

    mines = malloc(taille * sizeof(int*));
    for(i=0;i<taille;i++)
    {
        mines[i] = malloc(taille * sizeof(int));
        for(j=0;j<taille;j++)
        {
            mines[i][j] = 0;//remplir le tableau de 0
        }
    }
    while(nbBombes>0)
    {
        nbAleaX = rand()%10; //coordonn�e x al�atoire
        nbAleaY = rand()%10; //coordonn�e y al�atoire

        if(coordonneesExisteDeja(nbAleaX, nbAleaY, mines)) // Gestion des doublons
        {
            while(coordonneesExisteDeja(nbAleaX, nbAleaY, mines))
            {
                nbAleaX = rand()%10; //coordonn�e x al�atoire
                nbAleaY = rand()%10; //coordonn�e y al�atoire
            }
        }
        mines[nbAleaX][nbAleaY] = 1;//remplir le tableau de mines
        nbBombes--;
    }
    return mines;
}

