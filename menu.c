#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

#define JOUER 1
#define REPRENDRE 2
#define QUITTER_MENU 3

int getInt()
{
    int i;
    int res = scanf("%d", &i);

    if (res == 0)
        while (fgetc(stdin) != '\n');// lire jusqu'au '\n', utilisé si l'utilisateur rentre une chaîne de caractères

    return i;
}

int affichageMenu()
{
     printf("---Menu---\n\n");
     printf("1.Jouer\n");
     printf("2.Reprendre\n");
     printf("3.Quitter\n");
     printf("\nVotre choix?\n\n");

     return getInt();
}

int menu()
{
    int choix = affichageMenu();
    while(choix < JOUER || choix > QUITTER_MENU){
        printf("Veuillez choisir parmi les options proposées\n");
        choix = affichageMenu();
    }

    switch(choix)
    {
        case JOUER:
            printf("Vous avez choisi de jouer\n");
            break;

        case REPRENDRE:
            printf("Vous avez choisi de reprendre\n");
            break;

        case QUITTER_MENU:
            printf("Vous avez choisi de quitter\n");
            break;
    }


  return choix;
}

int affichageInteractionJoueur()
{
    printf("--------Actions possibles---------\n\n");
    printf("1.R�v�ler une case\n");
    printf("2.Placer un drapeau\n");
    printf("3.Supprimer un drapeau\n");
    printf("4.Sauvegarder la partie actuelle\n");
    printf("5.Quitter\n");
    printf("\nVotre choix?\n\n");

    return getInt();
}

void choisirCase(int* coordonnees, int taille)
{
    int x,y;

    printf("--------Choisir une case---------\n\n");

    printf("-->Entrez x : ");
    x = getInt();
    while(x<1 || x>taille){
        printf("Veuillez entrer une coordonnée existante\n");
        printf("-->Entrez x : ");
        x = getInt();
    }

    printf("-->Entrez y : ");
    y = getInt();
    while(y<1 || y>taille){
        printf("Veuillez entrer une coordonnée existante\n");
        printf("-->Entrez y : ");
        y = getInt();
    }

    coordonnees[0] = x-1;
    coordonnees[1] = y-1;
}
