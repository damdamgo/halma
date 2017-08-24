#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

/*
######################## fonction verificationfin######################
variable :

    plateau : tableau contenant les pions

    nbjoueurs : permet de connaitre le nombre de joueurs
	
	fin : permet de connaitre si un joueur a placé tous ses pions
###############################################################
*/
int verificationfin(int plateau[][16],int nbjoueurs)
{
    int fin;
    if(nbjoueurs==2)//verification pour deux joueurs
    {
        fin=2;
        if(plateau[0][0]!=2)fin=0;
        if(plateau[0][1]!=2)fin=0;
        if(plateau[0][2]!=2)fin=0;
        if(plateau[0][3]!=2)fin=0;
        if(plateau[0][4]!=2)fin=0;
        if(plateau[1][0]!=2)fin=0;
        if(plateau[1][1]!=2)fin=0;
        if(plateau[1][2]!=2)fin=0;
        if(plateau[1][3]!=2)fin=0;
        if(plateau[1][4]!=2)fin=0;
        if(plateau[2][0]!=2)fin=0;
        if(plateau[2][1]!=2)fin=0;
        if(plateau[2][2]!=2)fin=0;
        if(plateau[2][3]!=2)fin=0;
        if(plateau[3][0]!=2)fin=0;
        if(plateau[3][1]!=2)fin=0;
        if(plateau[3][2]!=2)fin=0;
        if(plateau[4][0]!=2)fin=0;
        if(plateau[4][1]!=2)fin=0;

        if(fin==0)
        {
            fin=1;
            if(plateau[11][14]!=1)fin=0;
            if(plateau[11][15]!=1)fin=0;
            if(plateau[12][13]!=1)fin=0;
            if(plateau[12][14]!=1)fin=0;
            if(plateau[12][15]!=1)fin=0;
            if(plateau[13][12]!=1)fin=0;
            if(plateau[13][13]!=1)fin=0;
            if(plateau[13][14]!=1)fin=0;
            if(plateau[13][15]!=1)fin=0;
            if(plateau[14][11]!=1)fin=0;
            if(plateau[14][12]!=1)fin=0;
            if(plateau[14][13]!=1)fin=0;
            if(plateau[14][14]!=1)fin=0;
            if(plateau[14][15]!=1)fin=0;
            if(plateau[15][11]!=1)fin=0;
            if(plateau[15][12]!=1)fin=0;
            if(plateau[15][13]!=1)fin=0;
            if(plateau[15][14]!=1)fin=0;
            if(plateau[15][15]!=1)fin=0;
        }	 
        return fin;

    }
}
/*
######################## fonction verification_fin4######################
variable :

    plateau : tableau contenant les pions

    terminer : recupere le tableau pour indiquer si un joueur a terminé
	
	fin : permet de connaitre si un joueur a placé tous ses pions
###############################################################
*/
void verification_fin4(int plateau[][16],int terminer[])
    {
            int fin;

            fin=2;
            if(plateau[0][0]!=2)fin=0;
            if(plateau[0][1]!=2)fin=0;
            if(plateau[0][2]!=2)fin=0;
            if(plateau[0][3]!=2)fin=0;
            if(plateau[1][0]!=2)fin=0;
            if(plateau[1][1]!=2)fin=0;
            if(plateau[1][2]!=2)fin=0;
            if(plateau[1][3]!=2)fin=0;
            if(plateau[2][0]!=2)fin=0;
            if(plateau[2][1]!=2)fin=0;
            if(plateau[2][2]!=2)fin=0;
            if(plateau[3][0]!=2)fin=0;
            if(plateau[3][1]!=2)fin=0;

            if(fin!=0)terminer[fin-1]=1;

            fin=1;
            if(plateau[12][14]!=1)fin=0;
            if(plateau[12][15]!=1)fin=0;
            if(plateau[13][13]!=1)fin=0;
            if(plateau[13][14]!=1)fin=0;
            if(plateau[13][15]!=1)fin=0;
            if(plateau[14][12]!=1)fin=0;
            if(plateau[14][13]!=1)fin=0;
            if(plateau[14][14]!=1)fin=0;
            if(plateau[14][15]!=1)fin=0;
            if(plateau[15][12]!=1)fin=0;
            if(plateau[15][13]!=1)fin=0;
            if(plateau[15][14]!=1)fin=0;
            if(plateau[15][15]!=1)fin=0;

            if(fin!=0)terminer[fin-1]=1;

            fin=3;
            if(plateau[12][0]!=3)fin=0;
            if(plateau[12][1]!=3)fin=0;
            if(plateau[13][0]!=3)fin=0;
            if(plateau[13][1]!=3)fin=0;
            if(plateau[13][2]!=3)fin=0;
            if(plateau[14][0]!=3)fin=0;
            if(plateau[14][1]!=3)fin=0;
            if(plateau[14][2]!=3)fin=0;
            if(plateau[14][3]!=3)fin=0;
            if(plateau[15][0]!=3)fin=0;
            if(plateau[15][1]!=3)fin=0;
            if(plateau[15][2]!=3)fin=0;
            if(plateau[15][3]!=3)fin=0;


            if(fin!=0)terminer[fin-1]=1;

            fin=4;
            if(plateau[0][12]!=4)fin=0;
            if(plateau[0][13]!=4)fin=0;
            if(plateau[0][14]!=4)fin=0;
            if(plateau[0][15]!=4)fin=0;
            if(plateau[1][12]!=4)fin=0;
            if(plateau[1][13]!=4)fin=0;
            if(plateau[1][14]!=4)fin=0;
            if(plateau[1][15]!=4)fin=0;
            if(plateau[2][13]!=4)fin=0;
            if(plateau[2][14]!=4)fin=0;
            if(plateau[2][15]!=4)fin=0;
            if(plateau[3][14]!=4)fin=0;
            if(plateau[3][15]!=4)fin=0;

            if(fin!=0)terminer[fin-1]=1;

    }


