#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

/*
######################## fonction affichage######################
variable :

    plateau : le tableau contenant l'emplacement des pions et des mouvements possibles
	
	i : indice
	
	j : indice
	
	tababs : pour numeroter les lignes
	
	tabord : indice des colonnes
###############################################################
*/


void afficheplateau(int plateau[][16])
{
   int i,j,tababs[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
   char tabord[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};

    printf("\n");
    printf("   ");
    for(i=0;i<16;i++)//on affcihe les lettres aux dessus des colonnes
    {
        printf("  %c ",tabord[i]);
    }
    printf("\n");
    printf("   ");
    for(i=0;i<16;i++)
    {
        printf(" ");
        printf("___");
    }
    printf("\n");
    printf("   ");
    for(i=0;i<17;i++)
    {
        printf("|");
        printf("   ");
    }
    printf("\n");
    printf("  1");
    for(i=0;i<17;i++)
    {
        printf("|");
        if(i<16)
        {

           if(plateau[0][i]==1)printf("\x1b[41m 1 \x1b[0m");//permet de mettre un arriere plan coloré
           else if(plateau[0][i]==2)printf("\x1b[42m 2 \x1b[0m");
           else if(plateau[0][i]==3)printf("\x1b[47m 3 \x1b[0m");
           else if(plateau[0][i]==4)printf("\x1b[44m 4 \x1b[0m");
           else if(plateau[0][i]=='X')printf(" X ");
            else printf("   ");
        }
    }
    printf("\n");
    printf("   ");
    for(j=0;j<15;j++)
    {
        for(i=0;i<17;i++)
        {
            printf("|");
            if(i<16)printf("___");
        }
        printf("\n");
        printf("   ");
        for(i=0;i<17;i++)
        {
            printf("|");
            printf("   ");
        }
        printf("\n");
        if(j<8)printf("  %d",tababs[j+1]);
        else printf(" %d",tababs[j+1]);
        for(i=0;i<17;i++)
        {
            printf("|");
            if(i<16)
            {

               if(plateau[j+1][i]==1)printf("\x1b[41m 1 \x1b[0m");
               else if(plateau[j+1][i]==2)printf("\x1b[42m 2 \x1b[0m");
               else if(plateau[j+1][i]==3)printf("\x1b[47m 3 \x1b[0m");
               else if(plateau[j+1][i]==4)printf("\x1b[44m 4 \x1b[0m");
                else if(plateau[j+1][i]=='X')printf(" X ");
                else printf("   ");
            }
        }
        printf("\n");
        printf("   ");
    }
    for(i=0;i<17;i++)
    {
        printf("|");
        if(i<16)printf("___");
    }
}
