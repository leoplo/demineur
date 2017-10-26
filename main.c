#include <stdlib.h>
#include "menu.h"
#include "grille.h"

int main()
{
    int i, taille=10;

    i=menu();

    if(i==1)
    {
        ElementGrille** grille = nouvelleGrille(taille);
        afficherGrille(grille, taille);

        for(i=0;i<taille;i++)
        {
            free(grille[i]);
        }
        free(grille);
    }

    return 0;
}


