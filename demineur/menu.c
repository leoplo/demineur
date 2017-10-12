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
    switch(affichageMenu())
    {
                     case 1:
                          printf("Vous avez choisis de jouer!");
                          break;
                     case 2:
                          printf("Vous avez choisis de reprendre!");
                          break;
                     case 3:
                          printf("BAAAAAMMMMM!");
                          break;
                     case 4:
                          printf("Vous n'auriez pas du choisir ca...");
                          break;
                     default:
                             printf("Vous ne ferez rien du tout!");
                             break;
    }


  return 0;
}
