#include <stdlib.h>
#include "menu.h"
#include "grille.h"
#include "partie.h"






int main()
{
    int i, taille=10;
    char** partie;

    i=menu();
    if(i==1)
    {
        partie = nouvellePartie(taille);
        afficherGrille(taille, partie);

        for(i=0;i<taille;i++)
        {
            free(partie[i]);
        }
        free(partie);
    }

    return 0;
}


