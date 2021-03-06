#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "mines.h"

const int MARGE = 5;
const int TAILLE_CASE = 3;


ElementGrille** nouvelleGrille(int taille, int nbMines)
{
    ElementGrille** grille = remplirGrille(taille);
    genererMines(grille, taille, nbMines);

    return grille;
}

ElementGrille** remplirGrille(int taille)
{
    int i =0;
    int j =0;
    ElementGrille** grille = malloc(taille * sizeof(ElementGrille*));
    for(i=0;i<taille;i++)
    {
        grille[i] = malloc(taille * sizeof(ElementGrille));
        for(j=0;j<taille;j++)
        {
            ElementGrille* e = malloc(sizeof(ElementGrille));
            e->caseRevelee = 0;
            e->presenceDrapeau =0;
            e->presenceMine = 0;
            e->minesAdjacentes = 0;
            grille[i][j] = *e;
        }
    }
    return grille;
}

// initialise toutes les cases d'un tableau avec le caract�re c
void remplirTab(char* tab, int taille, char c)
{
    int i;

    for(i=0;i<taille;i++)
    {
        tab[i]=c;
    }
    tab[i] = '\0';
}

//s�paration horizontale entre les cases de la grille
void definirLigneSeparatrice(char* ligne, int taille)
{
    int i;
    char marge[MARGE+1], separateurCase[TAILLE_CASE];

    remplirTab(marge, MARGE, ' ');
    remplirTab(separateurCase, TAILLE_CASE, '-');

    strcpy(ligne, marge);
    strcat(ligne, "+");
    strcat(ligne, separateurCase);

    for(i=0;i<taille-1;i++)
    {
        strcat(ligne, separateurCase);
        // caract�re '-' plac� sous les s�parateurs verticaux '|'
        strcat(ligne, "-");
    }
    strcat(ligne, "+");
}


char intToChar(int n)
{
    return n+48;
}

char afficherCase(ElementGrille e)
{
    if(e.caseRevelee)
        return intToChar(e.minesAdjacentes);

    if(e.presenceDrapeau)
        return 'd';

    if(e.presenceMine)
        return 'x';

    return ' ';
}

//imprime sur la sortie standard l'�tat actuel de la partie
void afficherGrille(ElementGrille** grille, int taille, int minesRestantes)
{
    int i, j;
    char *ligne, *ligneSeparatrice, marge[MARGE+1];

    printf("\n mines restantes: %d \n", minesRestantes);

    remplirTab(marge, MARGE, ' ');
    ligne = malloc((MARGE + (TAILLE_CASE+1)*(taille+1)) * sizeof(char));

    //  taille+1 -> nombre de s�parateurs verticaux '|' entre les cases
    ligneSeparatrice = malloc((MARGE + TAILLE_CASE*taille + taille+1) * sizeof(char));
    definirLigneSeparatrice(ligneSeparatrice, taille);

    printf("\n");

    strcpy(ligne, marge);
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
            sprintf(ligne+MARGE+(TAILLE_CASE+1)*j, "| %c ", afficherCase(grille[j][i]));
        }
        printf("%s|\n%s\n", ligne, ligneSeparatrice);
    }
    printf("\n");

    free(ligne);
    free(ligneSeparatrice);
}

int presenceMine(int x, int y, ElementGrille** grille, int taille)
{
    if(x<0 || y<0 || x>taille-1 || y>taille-1)
        return 0;

    return grille[x][y].presenceMine;
}

int placerDrapeau(ElementGrille** grille, int* coordonnes, int taille)
{
    if(!grille[coordonnes[0]][coordonnes[1]].caseRevelee && !grille[coordonnes[0]][coordonnes[1]].presenceDrapeau)//S'il n'y a pas de drapeau et que la case n'a pas d�j� �t� r�v�l�e
    {
        grille[coordonnes[0]][coordonnes[1]].presenceDrapeau = 1;
        return 1;
    }
    return 0;

}

int enleverDrapeau(ElementGrille** grille, int* coordonnes, int taille)
{
    if(grille[coordonnes[0]][coordonnes[1]].presenceDrapeau)//S'il y a un drapeau
    {
        grille[coordonnes[0]][coordonnes[1]].presenceDrapeau = 0;
        return 1;
    }
    return 0;
}

//retourne 1 si la partie est perdue, 0 sinon
int revelerCase(ElementGrille** grille, int* coordonnes, int taille){
    if(grille[coordonnes[0]][coordonnes[1]].caseRevelee)
        return 0;

    if(grille[coordonnes[0]][coordonnes[1]].presenceDrapeau)
        return 0;

    if(grille[coordonnes[0]][coordonnes[1]].presenceMine)
        return 1;

    minesAdjacentes(grille, coordonnes[0], coordonnes[1], taille);

    return 0;
}

int existe(int x, int y, int taille){
    if(x<0 || y<0 || x>taille-1 || y>taille-1)
        return 0;

    return 1;
}

void minesAdjacentes(ElementGrille** grille, int x, int y, int taille){
    if(!existe(x, y, taille) || grille[x][y].caseRevelee)
        return;

    if(!grille[x][y].presenceDrapeau)
        grille[x][y].caseRevelee = 1;


    grille[x][y].minesAdjacentes =
        presenceMine(x-1, y, grille, taille)
        + presenceMine(x-1, y+1, grille, taille)
        + presenceMine(x, y+1, grille, taille)
        + presenceMine(x+1, y+1, grille, taille)
        + presenceMine(x+1, y, grille, taille)
        + presenceMine(x+1, y-1, grille, taille)
        + presenceMine(x, y-1, grille, taille)
        + presenceMine(x-1, y-1, grille, taille);

    if(grille[x][y].minesAdjacentes == 0){
        minesAdjacentes(grille, x-1, y, taille);
        minesAdjacentes(grille, x, y+1, taille);
        minesAdjacentes(grille, x+1, y, taille);
        minesAdjacentes(grille, x, y-1, taille);
    }
}

void sauvegardeGrille(char* nomFichier, ElementGrille** grille, int tailleGrille)
{
    FILE* fichier = NULL;
    fichier = fopen(nomFichier, "w");
    int i,j;
    if(fichier == NULL)
    {
        printf("fichier inexistant");
    }
    else
    {
        for(i=0;i<tailleGrille;i++)
        {
            for(j=0;j<tailleGrille;j++)
            {
                ElementGrille* e = malloc(sizeof(ElementGrille));
                e->caseRevelee = grille[i][j].caseRevelee;
                e->minesAdjacentes = grille[i][j].minesAdjacentes;
                e->presenceDrapeau = grille[i][j].presenceDrapeau;
                e->presenceMine = grille[i][j].presenceMine;
                fprintf(fichier," %d %d %d %d %d %d \n", i, j,  e->presenceMine, e->presenceDrapeau,  e->caseRevelee, e->minesAdjacentes);
                free(e);
            }

        }
    }
    fclose(fichier);
}

ElementGrille** chargerGrille(char* nomFichier, int tailleGrille)
{
    FILE* fichier = NULL;
    ElementGrille** grille = remplirGrille(tailleGrille);
    int presenceMine,presenceDrapeau,caseRevelee,minesAdjacentes;
    fichier = fopen(nomFichier, "r+");
    int i,j;
    if(fichier == NULL)
    {
        printf("fichier inexistant");
    }
    else
    {
        while(fscanf(fichier," %d %d %d %d %d %d \n", &i, &j, &presenceMine,&presenceDrapeau,&caseRevelee,&minesAdjacentes)!=EOF)
        {
            grille[i][j].caseRevelee = caseRevelee;
            grille[i][j].presenceMine = presenceMine;
            grille[i][j].presenceDrapeau = presenceDrapeau;
            grille[i][j].minesAdjacentes = minesAdjacentes;
        }
    }
    fclose(fichier);
    return grille;
}
