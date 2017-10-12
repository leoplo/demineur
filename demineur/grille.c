#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

void AfficherGrille()
{

   char grille[10][10]={0};   // a modifier
   printf("\n\n");
   printf("   | 1 2 3 4 5 6 7 8 9 10\n");
   printf("___|______________________________\n");

   for(int i=0;i<10;i++)
      {
           if(i<9)
           printf(" %d | ",i+1);
           else
           printf("%d | ",i+1);

        for(int j=0;j<10;j++)
            {
                printf("%c ",grille[i][j]);
            }
        printf("\n");
      }
}
