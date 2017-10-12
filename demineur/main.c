#include <stdio.h>
#include <stdlib.h>
#include "menu.c"
#include "grille.c"






int main()
{
    int i;
    i=menu();
    if(i==1) AfficherGrille();

    return 0;
}


