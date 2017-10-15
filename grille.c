#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "elementGrille.h"

void RemplirGrille()
{
    int taille =10;
    ElementGrille grille[taille][taille];
    int i =0;
    int j =0;
    FILE* file = fopen("grille.txt", "r+");
    while(i<taille)
    {
        while(j<taille)
        {
            fprintf(file, " {%d %d %d %d %d} ", i,j,0,0,0); //format : {x, y, presenceMine, presenceDrapeau, caseRévélée}
            j++;
        }
        i++;
        j=0;
    }
    fclose(file);
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
