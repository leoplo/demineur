<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
#include "menu.c"
#include "grille.c"
#include "mines.c"
#include "partie.c"

int main()
{
int i, taille=10;
char** partie;
i=menu();
=======
#include "menu.h"
#include "grille.h"
#include "partie.h"






int main()
{
    int i, taille=10;
    char** partie;

    i=menu();
>>>>>>> Stashed changes
    if(i==1)
    {
        partie = nouvellePartie(taille);
        ElementGrille** grille = remplirGrille();
        afficherGrille(taille, partie);
        int** mines = genererMines(10);
        afficherMines(mines, 10);
        remplirGrilleAvecMine(grille, mines,10);
        lireGrille(grille, 10);
        for(i=0;i<taille;i++)
        {
            free(partie[i]);
        }
        free(partie);
    }

    return 0;
}


