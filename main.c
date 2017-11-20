#include <stdlib.h>
#include "menu.h"
#include "grille.h"
#include "mines.h"

int main()
{
    int i, taille=9, choix, coordonnees[2], quitterJeu=0;

    i=menu();

    if(i==1)
    {
        ElementGrille** grille = nouvelleGrille(taille);
        afficherGrille(grille, taille);
        choix = affichageInteractionJoueur(); //afficher les intéractions possibles avec le joueur

        while(choix!=4){
            choisirCase(coordonnees, taille);

            switch(choix){
                case 1://Choisir une case
                    quitterJeu = revelerCase(grille, coordonnees, taille);
                    break;

                case 2://Placer drapeau
                    placerDrapeau(grille, coordonnees);
                    break;

                case 3://Enlever drapeau
                    enleverDrapeau(grille, coordonnees);
                    break;
            }

            if(quitterJeu){
                printf("Perdu\n");
                break;
            }

            afficherGrille(grille, taille);
            choix = affichageInteractionJoueur();
        }

        for(i=0;i<taille;i++)
        {
            free(grille[i]);
        }
        free(grille);
    }

    return 0;
}
