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
