<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "mines.h"

ElementGrille** remplirGrille()
=======
#include "grille.h"

const int MARGE = 5;

const int TAILLE_CASE = 3;

/*void RemplirGrille()
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
}
=======
    fclose(file);
}*/

// initialise toutes les cases d'un tableau avec le caractère c
void remplirTab(char* tab, int taille, char c)
{
    int i;
>>>>>>> Stashed changes

    for(i=0;i<taille;i++)
    {
        tab[i]=c;
    }
}

//séparation horizontale entre les cases de la grille
void definirLigneSeparatrice(char* ligne, int taille)
{
    int i;
    char marge[MARGE], separateurCase[TAILLE_CASE];

    remplirTab(marge, MARGE, ' ');
    remplirTab(separateurCase, TAILLE_CASE, '-');

    strcat(ligne, marge);
    strcat(ligne, "+");
    strcat(ligne, separateurCase);

    for(i=0;i<taille-1;i++)
    {
        strcat(ligne, separateurCase);
        // caractère '-' placé sous les séparateurs verticaux '|'
        strcat(ligne, "-");
    }
    strcat(ligne, "+");
}

//imprime sur la sortie standard l'état actuel de la partie
void afficherGrille(int taille, char** partie)
{
    int i, j;
    char *ligne, *ligneSeparatrice, marge[MARGE];

    remplirTab(marge, MARGE, ' ');
    ligne = malloc((MARGE + (TAILLE_CASE+1)*(taille+1)) * sizeof(char));

    //  taille+1 -> nombre de séparateurs verticaux '|' entre les cases
    ligneSeparatrice = malloc((MARGE + TAILLE_CASE*taille + taille+1) * sizeof(char));
    definirLigneSeparatrice(ligneSeparatrice, taille);

    printf("\n");

    strcat(ligne, marge);
    strcat(ligne, "  ");
    for(i=0;i<taille;i++)
    {
        sprintf(ligne+MARGE+2+(TAILLE_CASE+1)*i, "%d   ", i+1);
    }
    printf("%s\n%s\n", ligne, ligneSeparatrice);

    for(i=0;i<taille;i++)
    {
        sprintf(ligne, "  %d  ", i+1);
        for(j=0;j<taille;j++)
        {
            sprintf(ligne+MARGE+(TAILLE_CASE+1)*j, "| %c ", partie[i][j]);
        }
        printf("%s|\n%s\n", ligne, ligneSeparatrice);
    }
    printf("\n");

    free(ligne);
    free(ligneSeparatrice);
}
