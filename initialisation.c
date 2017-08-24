#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
/*
######################## fonction initialisation######################
variable :

    plateau : iniatialise le tableau en fonction du nombre joueurs

    nbjoueurs : permet de connaitre le nombre de joueurs
###############################################################
*/
void initialiseplateau(int plateau[][16],int nbjoueurs)
{
    /*pour deux joueurs*/
    if(nbjoueurs==2)
    {
        plateau[0][0]=1;
        plateau[0][1]=1;
        plateau[0][2]=1;
        plateau[0][3]=1;
        plateau[0][4]=1;
        plateau[1][0]=1;
        plateau[1][1]=1;
        plateau[1][2]=1;
        plateau[1][3]=1;
        plateau[1][4]=1;
        plateau[2][0]=1;
        plateau[2][1]=1;
        plateau[2][2]=1;
        plateau[2][3]=1;
        plateau[3][0]=1;
        plateau[3][1]=1;
        plateau[3][2]=1;
        plateau[4][0]=1;
        plateau[4][1]=1;

        plateau[11][14]=2;
        plateau[11][15]=2;
        plateau[12][13]=2;
        plateau[12][14]=2;
        plateau[12][15]=2;
        plateau[13][12]=2;
        plateau[13][13]=2;
        plateau[13][14]=2;
        plateau[13][15]=2;
        plateau[14][11]=2;
        plateau[14][12]=2;
        plateau[14][13]=2;
        plateau[14][14]=2;
        plateau[14][15]=2;
        plateau[15][11]=2;
        plateau[15][12]=2;
        plateau[15][13]=2;
        plateau[15][14]=2;
        plateau[15][15]=2;
    }
      if(nbjoueurs==4)//si il y 4 joueurs 
        {
            plateau[0][0]=1;
            plateau[0][1]=1;
            plateau[0][2]=1;
            plateau[0][3]=1;
            plateau[1][0]=1;
            plateau[1][1]=1;
            plateau[1][2]=1;
            plateau[1][3]=1;
            plateau[2][0]=1;
            plateau[2][1]=1;
            plateau[2][2]=1;
            plateau[3][0]=1;
            plateau[3][1]=1;


            plateau[12][14]=2;
            plateau[12][15]=2;
            plateau[13][13]=2;
            plateau[13][14]=2;
            plateau[13][15]=2;
            plateau[14][12]=2;
            plateau[14][13]=2;
            plateau[14][14]=2;
            plateau[14][15]=2;
            plateau[15][12]=2;
            plateau[15][13]=2;
            plateau[15][14]=2;
            plateau[15][15]=2;


            plateau[0][12]=3;
            plateau[0][13]=3;
            plateau[0][14]=3;
            plateau[0][15]=3;
            plateau[1][12]=3;
            plateau[1][13]=3;
            plateau[1][14]=3;
            plateau[1][15]=3;
            plateau[2][13]=3;
            plateau[2][14]=3;
            plateau[2][15]=3;
            plateau[3][14]=3;
            plateau[3][15]=3;


            plateau[12][0]=4;
            plateau[12][1]=4;
            plateau[13][0]=4;
            plateau[13][1]=4;
            plateau[13][2]=4;
            plateau[14][0]=4;
            plateau[14][1]=4;
            plateau[14][2]=4;
            plateau[14][3]=4;
            plateau[15][0]=4;
            plateau[15][1]=4;
            plateau[15][2]=4;
            plateau[15][3]=4;
        }
}
