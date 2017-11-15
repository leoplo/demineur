#include <stdlib.h>
#include "menu.h"
#include "grille.h"
#include "mines.h"
#include "partie.h"

int main()
{
    int i, taille=10;

    i=menu();

    if(i==1)
    {
        ElementGrille** grille = nouvelleGrille(taille);
        afficherGrille(grille, taille);
        int j = affichageInteractionJoueur(); //afficher les intéractions possibles avec le joueur
        if(j == 1) //Choisir une case
        {
            int* tab = choisirCase();
            if(presenceMine(tab[0], tab[1], grille))
            {
                printf("mine");
            }

        }
        if(j == 2) //Placer drapeau
        {

        }
        if(j==3)//Enlever drapeau
        {

        }

        for(i=0;i<taille;i++)
        {
            free(grille[i]);
        }
        free(grille);
    }

    return 0;
}
