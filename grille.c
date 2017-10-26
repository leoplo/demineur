#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "mines.h"

ElementGrille** remplirGrille()
{
    int taille = 10;
    int i =0;
    int j =0;
    ElementGrille** grille = malloc(taille * sizeof(ElementGrille*));
    for(i=0;i<taille;i++)
    {
        grille[i] = malloc(taille * sizeof(ElementGrille));
        for(j=0;j<taille;j++)
        {
            ElementGrille * e = malloc(sizeof(ElementGrille));
            e->caseRevelee = 0;
            e->presenceDrapeau =0;
            e->presenceMine = 0;
            grille[i][j] = *e;
        }
    }
    return grille;
}

void remplirGrilleAvecMine(ElementGrille** grille,int** mines, int taille)
{
    int i,j;
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            if(mines[i][j] == 1)
            {
                grille[i][j].presenceMine = 1;
            }
        }
    }
}

void lireGrille(ElementGrille** grille, int taille)
{
    int i,j;
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            ElementGrille e = grille[i][j];
            printf("\nElement [%d,%d] : Drapeau : %d, Mine : %d, CaseRevelee : %d", i,j,e.presenceDrapeau,e.presenceMine,e.caseRevelee);
        }
    }
}

char* ligneSeparatrice(int taille)
{
    int i;
    char* ligne;
    ligne = malloc((5 + 3*taille + taille+1) * sizeof(char));

    strcpy(ligne, "     +---");
    for(i=0;i<taille-1;i++)
    {
        strcpy(ligne+9+4*i, "----");
    }
    ligne[5 + 3*taille + taille] = '+';

    return ligne;
}

void afficherGrille(int taille, char** partie)
{
    int i, j;
    char* ligne;
    ligne = malloc((5 + 4*(taille+1)) * sizeof(char));

    printf("\n");

    strcpy(ligne, "       ");
    for(i=0;i<taille;i++)
    {
        sprintf(ligne+7+4*i, "%d   ", i+1);
    }
    printf("%s\n", ligne);
    printf("%s\n", ligneSeparatrice(taille));

    for(i=0;i<taille;i++)
    {
        sprintf(ligne, "  %d  ", i+1);
        for(j=0;j<taille;j++)
        {
            sprintf(ligne+5+4*j, "| %c ", partie[i][j]);
        }
        printf("%s|\n", ligne);
        printf("%s\n", ligneSeparatrice(taille));
    }
    printf("\n");

    free(ligne);
}
