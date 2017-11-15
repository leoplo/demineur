#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int affichageMenu()
{
     int choixMenu;

     printf("---Menu---\n\n");
     printf("1.Jouer !\n");
     printf("2.Reprendre!\n");
     printf("3.Vas y test\n");
     printf("4.Et le je ne sais pas quoi mettre\n\n\n");
     printf("\nVotre choix?\n\n");

     scanf("%d", &choixMenu);
     return choixMenu;
}


int menu()
{
    int i;
    switch(affichageMenu())
    {
                     case 1:
                          printf("Vous avez choisis de jouer!");
                          i=1;
                          break;
                     case 2:
                          printf("Vous avez choisis de reprendre!");
                          i=2;
                          break;
                     case 3:
                          printf("BAAAAAMMMMM!");
                          i=3;
                          break;
                     case 4:
                          printf("Vous n'auriez pas du choisir ca...");
                          i=4;
                          break;
                     default:
                             printf("Vous ne ferez rien du tout!");
                             break;
    }


  return i;
}

int affichageInteractionJoueur()
{
    int choix;
    int i;
    printf("--------Actions possibles---------\n\n");
    printf("1.Choisir une case\n");
    printf("2.Placer un drapeau\n");
    printf("3.Supprimer un drapeau\n");
    printf("0.Quitter\n");
    printf("\nVotre choix?\n\n");

    scanf("%d",&choix);
    switch(choix)
    {
                     case 1:
                        i=1;
                        break;
                     case 2:
                        i=2;
                        break;
                     case 3:
                        i=3;
                        break;
                    case 0:
                        i=0;
                        break;
    }
    return i;
}

int* choisirCase()
{
    int x,y;
    int* tab = malloc(2*sizeof(int));
    printf("--------Choisir une case---------\n\n");
    printf("-->Entrez x : ");
    scanf("%d", &x);
    printf("-->Entrez y : ");
    scanf("%d", &y);
    tab[0] = x-1;
    tab[1] = y-1;
    return tab;
}

void placerDrapeau()
{

}

void enleverDrapeau()
{

}

