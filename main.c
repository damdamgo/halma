#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"


/*
######################## fonction main######################
variable :

    plateau : c'est un tableau qui permettra de gerer les pions comme sur un plateau

    nbjoueurs : c'est le nombres de joueurs soit 2 ou 4

    fin : permet de recuperer le joueur ou l'equipe qui a gagné

    joueur : ca indique le joueur qui joue

    choix : permet de recuperer l'option choisi par l'utilisateur

    bloquer : permet de recuperer le joueur qui reste dans son camps et qui peut plus jouer

    tableau_deplacement : permet de sauvegarder nombre deplacement
	
	tableau_fin : permet pour la version 4 joueurs de recuperer les joueurs qui ont terminé

    i : indice de deplacement
###############################################################
*/


int main()
{
    //initialisation des variables
    int plateau[16][16]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                         }
                         ,nbjoueurs,fin=0,joueur=1,choix,bloquer=0,tableau_deplacement[4]={0,0,0,0},i,tableau_fin[4]={0,0,0,0};

   do
   {
       //presentation du menu
        printf("------------------------------------\n");
        printf("--    Bonjour bienvenue sur       --\n");
        printf("--              HALMA             --\n");
        printf("------------------------------------\n");
        printf("saisir 1 pour jouer\n");
        printf("saisir 2 pour voir les regles\n");
        printf("saisir 3 pour quitter\n");
        //choix de l'option
        do
        {
            scanf("%d",&choix);
            while(getchar() != '\n');
        }
        while(choix<1 || choix>3);
        //permet d'acceder au different option
       switch (choix)
       {
            //acceder a une partie
           case 1:
            //choix du nombre de joueurs
             do
            {
               printf("pour jouer a deux joueurs taper 2 \n");
               printf("pour jouer a quatre joueurs taper 4 \n");
               scanf("%d",&nbjoueurs);
               while(getchar() != '\n');
            }
            while(nbjoueurs!=2 && nbjoueurs!=4);

           printf("\033[2J");//faire un espace dans la console pour plus de visibilité

            //partie a dux joueurs
            if(nbjoueurs==2)
            {
                initialiseplateau(plateau,nbjoueurs);//on initialise le plateau pour deux joueurs
                while(fin==0)//tant qu'il n'y a pas de gagnant
                {
                    for(i=0;i<2;i++)//affiche deplacement
                    {
                        printf("--joueur %d : nombre de deplacement %d",i+1,tableau_deplacement[i]);
                    }
                    afficheplateau(plateau);//affiche le plateau pour le joueur
                    bloquer=mouvement(plateau,joueur,nbjoueurs,tableau_deplacement,tableau_fin);//permet le mouvement du joueur ainsi que voir si celui ci bloque la partie
                    if(bloquer==0)//si aucun blocage
                    {
                        joueur++;
                        if(joueur>nbjoueurs)joueur=1;
                        fin=verificationfin(plateau,nbjoueurs);//verifie si il n'y a pas un joueur qui a gagné
                    }
                    else//si il y a blocage
                    {
                        joueur++;
                        if(joueur>nbjoueurs)joueur=1;
                        fin=joueur;//fin prend la valeur du joueur
                    }
                }
            }


            if(nbjoueurs==4)// si il y a 4 joueurs
            {
                initialiseplateau(plateau,nbjoueurs);//initialise le tableau pour 4 joueurs
                while(fin==0)//tant que il n'y a pas de gagnant
                {
                    afficheplateau(plateau);// on affiche le plateau
                    mouvement(plateau,joueur,nbjoueurs,tableau_deplacement,tableau_fin);//un joueur bouge un pion
                    for(i=0;i<4;i++)//affiche deplacement
                    {
                        printf("--joueur %d : nombre de deplacement %d",i+1,tableau_deplacement[i]);
                    }
                    joueur++;
                    if(joueur>nbjoueurs)joueur=1;
                    verification_fin4(plateau,tableau_fin);//verifie si un des joueurs a terminé
                    if(tableau_fin[0]==1 && tableau_fin[2]==1)fin=1;//verifie si l'equipe 1 a gagné
                    if(tableau_fin[1]==1 && tableau_fin[3]==1)fin=2;//verifie si l'equipe 2 a gagné
                }
            }
            //affiche le gagnant
            if(fin==1 && nbjoueurs<3)printf("bravo au joueur 1 qui gagne\n");
            if(fin==2 && nbjoueurs<3)printf("bravo au joueur 2 qui gagne\n");
            if(fin==1 && nbjoueurs>2)printf("bravo aux joueurs 1 et 3 qui gagnent\n");
            if(fin==2 && nbjoueurs>2)printf("bravo aux joueurs 2 et 4 qui gagnent\n");

           break;
           //les regles du jeu
           case 2:
		printf("voici l'adresse : http://jeuxstrategie1.free.fr/jeu_halma/regle.pdf\n");
		printf("pour deux joueurs une option de blocage a ete ajoute : \nsi un joueur bloque le jeu il perd\n");
		printf("pour quatre joueurs :\nil y a deux equipes joueur 1 avec le 3 et joueur 2 avec le 4\nsi un joueur de l'equipe a reussi a mettre tous ses pions dans le camp oppose alors il peut jouer a la place de son coequipier.\n");
           break;
       }
   }
    while(choix!=3);

}
