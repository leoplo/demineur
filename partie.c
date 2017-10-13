#include <stdlib.h>
#include "partie.h"

char** nouvellePartie(int taille)
{
    char** partie;
    int i, j;

    partie = malloc(taille * sizeof(char*));
    for(i=0;i<taille;i++)
    {
        partie[i] = malloc(taille * sizeof(char));
        for(j=0;j<taille;j++)
        {
            partie[i][j] = ' ';
        }
    }
    return partie;
}
