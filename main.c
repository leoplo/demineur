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

int JeuGagne(ElementGrille** grille, int taille, int minesRestantes)
{
    int i, j;
    if(minesRestantes != 0)
        return 0;

    for(i=0;i<taille;i++){
        for(j=0;j<taille;j++){
            if(!grille[i][j].presenceDrapeau && !grille[i][j].caseRevelee)
                return 0;
        }
    }

    return 1;
}

int main()
{
    int i, taille=9, nbMines=2, choix, coordonnees[2], quitterJeu=0, minesRestantes;

    minesRestantes = nbMines;
    i=menu();

    if(i==JOUER)
    {
        ElementGrille** grille = nouvelleGrille(taille, nbMines);
        afficherGrille(grille, taille, minesRestantes);
        choix = choixDuJoueur(); //afficher les intéractions possibles avec le joueur
        while(choix != QUITTER){
            if(choix!=SAUVEGARDER) choisirCase(coordonnees, taille); //Ne pas choisir de case lorsque l'utilisateur choisit de sauvegarder
            switch(choix){
                case CHOISIR_CASE:
                    quitterJeu = revelerCase(grille, coordonnees, taille);
                    if(quitterJeu)
                        printf("Perdu\n");
                    if(JeuGagne(grille,taille,minesRestantes))
                    {
                        printf("Gagne !\n");
                        quitterJeu = 1;
                    }
                    break;

                case PLACER_DRAPEAU:
                    if(placerDrapeau(grille, coordonnees, taille))
                        minesRestantes--;

                    if(JeuGagne(grille,taille,minesRestantes))
                    {
                        printf("Gagne !\n");
                        quitterJeu = 1;
                    }
                    break;

                case ENLEVER_DRAPEAU:

                    if(enleverDrapeau(grille, coordonnees, taille))
                        minesRestantes++;
                    break;

                case SAUVEGARDER:
                    sauvegardeGrille("save.txt", grille,taille);
                    ElementGrille** grille = chargerGrille("save.txt",taille);
                    afficherGrille(grille,taille,minesRestantes);
                    quitterJeu = 1;
                    break;
            }
            if(quitterJeu)
                break;

            afficherGrille(grille, taille,minesRestantes);
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
        afficherGrille(grille,taille, minesRestantes);
                choix = choixDuJoueur(); //afficher les intéractions possibles avec le joueur
        while(choix != QUITTER){
            if(choix!=SAUVEGARDER) choisirCase(coordonnees, taille); //Ne pas choisir de case lorsque l'utilisateur choisit de sauvegarder
            switch(choix){
                case CHOISIR_CASE:
                    quitterJeu = revelerCase(grille, coordonnees, taille);

                    if(quitterJeu)
                        printf("Perdu\n");

                    if(JeuGagne(grille,taille,minesRestantes))
                    {
                        printf("Gagne !\n");
                        quitterJeu = 1;
                    }
                    break;

                case PLACER_DRAPEAU:
                    if(placerDrapeau(grille, coordonnees, taille))
                        minesRestantes--;

                    if(JeuGagne(grille,taille,minesRestantes))
                    {
                        printf("Gagne !\n");
                        quitterJeu = 1;
                    }
                    break;

                case ENLEVER_DRAPEAU:
                    if(enleverDrapeau(grille, coordonnees, taille))
                        minesRestantes++;
                    break;

                case SAUVEGARDER:
                    sauvegardeGrille("save.txt", grille,taille);
                    ElementGrille** grille = chargerGrille("save.txt",taille);
                    afficherGrille(grille,taille,minesRestantes);
                    quitterJeu = 1;
                    break;
            }
            if(quitterJeu)
                break;

            afficherGrille(grille, taille, minesRestantes);
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
