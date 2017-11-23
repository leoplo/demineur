#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int affichageMenu()
{
     int choixMenu;

     printf("---Menu---\n\n");
     printf("1.Jouer !\n");
     printf("2.Reprendre!\n");
     printf("3.Quitter\n");
     printf("\nVotre choix?\n\n");

     scanf("%d", &choixMenu);
     return choixMenu;
}


int menu()
{
    int choix = affichageMenu();
    while(choix < 1 || choix > 3){
        printf("Veuillez choisir parmi les options proposées\n");
        choix = affichageMenu();
    }

    switch(choix)
    {
        case 1:
            printf("Vous avez choisi de jouer!\n");
            break;

        case 2:
            printf("Vous avez choisi de reprendre!\n");
            break;

        case 3:
            printf("Vous avez choisi de quitter\n");
            break;
    }


  return choix;
}

int affichageInteractionJoueur()
{
    int choix;
    printf("--------Actions possibles---------\n\n");
    printf("1.Reveler une case\n");
    printf("2.Placer un drapeau\n");
    printf("3.Supprimer un drapeau\n");
    printf("4.Sauvegarder la partie actuelle\n");
    printf("5.Quitter\n");
    printf("\nVotre choix?\n\n");

    scanf("%d",&choix);
    while(choix < 1 || choix > 5){
        printf("Veuillez choisir parmi les options proposées\n");
        scanf("%d",&choix);
    }

    return choix;
}

void choisirCase(int* coordonnees, int taille)
{
    int x,y;

    printf("--------Choisir une case---------\n\n");

    printf("-->Entrez x : ");
    scanf("%d", &x);
    while(x<1 || x>taille){
        printf("Veuillez entrer une coordonnee existante\n");
        printf("-->Entrez x : ");
        scanf("%d", &x);
    }

    printf("-->Entrez y : ");
    scanf("%d", &y);
    while(y<1 || y>taille){
        printf("Veuillez entrer une coordonnee existante\n");
        printf("-->Entrez y : ");
        scanf("%d", &y);
    }

    coordonnees[0] = x-1;
    coordonnees[1] = y-1;
}
