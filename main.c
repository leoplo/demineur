#include "menu.h"
#include "grille.h"
#include "partie.h"






int main()
{
    int i;
    char** partie;

    i=menu();
    if(i==1)
    {
        partie = nouvellePartie(10);
        afficherGrille(10, partie);
    }

    return 0;
}


