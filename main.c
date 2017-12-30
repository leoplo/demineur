#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "grille.h"
#include "mines.h"

#define JOUER 1
#define REPRENDRE 2
#define QUITTER_MENU 3

#define CHOISIR_CASE 1
#define PLACER_DRAPEAU 2
#define ENLEVER_DRAPEAU 3
#define SAUVEGARDER 4
#define QUITTER 5

int choixDuJoueur()
{
    int choix = affichageInteractionJoueur();

    while(choix < CHOISIR_CASE || choix > QUITTER){
        printf("Veuillez choisir parmi les options possibles\n");
        choix = affichageInteractionJoueur();
    }

    return choix;
}

int JeuGagne(int nbMines)
{
    if(nbMines == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int i, taille=9, nbMines=2, choix, coordonnees[2], quitterJeu=0;

    i=menu();

    if(i==JOUER)
    {
        ElementGrille** grille = nouvelleGrille(taille, nbMines);
        afficherGrille(grille, taille);
        choix = choixDuJoueur(); //afficher les intéractions possibles avec le joueur
        while(choix != QUITTER){
            if(choix!=SAUVEGARDER) choisirCase(coordonnees, taille); //Ne pas choisir de case lorsque l'utilisateur choisit de sauvegarder
            switch(choix){
                case CHOISIR_CASE:
                    quitterJeu = revelerCase(grille, coordonnees, taille);
                    if(quitterJeu)
                        printf("Perdu\n");
                    break;

                case PLACER_DRAPEAU:
                    placerDrapeau(grille, coordonnees, taille, &nbMines);
                    if(JeuGagne(nbMines))
                    {
                        printf("Gagne !\n");
                        quitterJeu = 1;
                        break;
                    }
                    break;

                case ENLEVER_DRAPEAU:
                    enleverDrapeau(grille, coordonnees, taille, &nbMines);
                    break;

                case SAUVEGARDER:
                    sauvegardeGrille("save.txt", grille,taille);
                    ElementGrille** grille = chargerGrille("save.txt",taille);
                    afficherGrille(grille,taille);
                    quitterJeu = 1;
                    break;
            }
            if(quitterJeu)
                break;

            afficherGrille(grille, taille);
            choix = choixDuJoueur();
        }

        for(i=0;i<taille;i++)
        {
            free(grille[i]);
        }
        free(grille);
    }

    /* REPRENDRE UNE PARTIE */
    if (i == REPRENDRE)
    {
        ElementGrille** grille = chargerGrille("save.txt",taille);
        afficherGrille(grille,taille);
                choix = choixDuJoueur(); //afficher les intéractions possibles avec le joueur
        while(choix != QUITTER){
            if(choix!=SAUVEGARDER) choisirCase(coordonnees, taille); //Ne pas choisir de case lorsque l'utilisateur choisit de sauvegarder
            switch(choix){
                case CHOISIR_CASE:
                    quitterJeu = revelerCase(grille, coordonnees, taille);
                    if(quitterJeu)
                        printf("Perdu\n");
                    break;

                case PLACER_DRAPEAU:
                    placerDrapeau(grille, coordonnees, taille, &nbMines);
                    if(JeuGagne(nbMines))
                    {
                        printf("Gagne !\n");
                        quitterJeu = 1;
                        break;
                    }
                    break;

                case ENLEVER_DRAPEAU:
                    enleverDrapeau(grille, coordonnees, taille, &nbMines);
                    break;

                case SAUVEGARDER:
                    sauvegardeGrille("save.txt", grille,taille);
                    ElementGrille** grille = chargerGrille("save.txt",taille);
                    afficherGrille(grille,taille);
                    quitterJeu = 1;
                    break;
            }
            if(quitterJeu)
                break;

            afficherGrille(grille, taille);
            choix = choixDuJoueur();
        }

        for(i=0;i<taille;i++)
        {
            free(grille[i]);
        }
        free(grille);
    }

    return 0;
}
