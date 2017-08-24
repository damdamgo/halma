#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"


/*
######################## fonction premiermouvement######################
variable :

    plateau : recupere la variable plateau

    autorisation_deplacement : permet de voir si il y a un deplacement possible
	
	emplacement : permet de connaitre la colonne du pion
	
	choixnum : permet de connaitre la ligne du pion
###############################################################
*/


int premiermouvement(int plateau[][16],int autorisation_deplacement,int emplacement,int choixnum)
{
	//pour chaque case autour du pion et les cases d'apres pour effectuer un saut on regarde si il peut si deplacer. Si oui on met un X
	//il y a les conditions >=0 ou encore <= 15 pour eviter le probleme de decalage des pions
    if(plateau[choixnum-1][emplacement]==0  && choixnum-1>=0){plateau[choixnum-1][emplacement]='X';autorisation_deplacement=0;}
    else if(plateau[choixnum-2][emplacement]==0  && choixnum-2>=0){plateau[choixnum-2][emplacement]='X';autorisation_deplacement=0;}
    if(plateau[choixnum+1][emplacement]==0  && choixnum+1<=15){plateau[choixnum+1][emplacement]='X';autorisation_deplacement=0;}
    else if(plateau[choixnum+2][emplacement]==0   && choixnum+2<=15){plateau[choixnum+2][emplacement]='X';autorisation_deplacement=0;}
    if(plateau[choixnum][emplacement-1]==0 && emplacement-1>=0){plateau[choixnum][emplacement-1]='X';autorisation_deplacement=0;}
    else if (plateau[choixnum][emplacement-2]==0 && emplacement-2>=0){plateau[choixnum][emplacement-2]='X';autorisation_deplacement=0;}
    if(plateau[choixnum][emplacement+1]==0 && emplacement+1<=15){plateau[choixnum][emplacement+1]='X';autorisation_deplacement=0;}
    else if(plateau[choixnum][emplacement+2]==0 && emplacement+2<=15){plateau[choixnum][emplacement+2]='X';autorisation_deplacement=0;}
    if(plateau[choixnum+1][emplacement+1]==0 && emplacement+1<=15  && choixnum+1<=15){plateau[choixnum+1][emplacement+1]='X';autorisation_deplacement=0;}
    else if(plateau[choixnum+2][emplacement+2]==0 && emplacement+2<=15 && choixnum+2<=15){plateau[choixnum+2][emplacement+2]='X';autorisation_deplacement=0;}
    if(plateau[choixnum-1][emplacement-1]==0 && emplacement-1>=0 && choixnum-1>=0){plateau[choixnum-1][emplacement-1]='X';autorisation_deplacement=0;}
    else if(plateau[choixnum-2][emplacement-2]==0 && emplacement-2>=0 && choixnum-2>=0){plateau[choixnum-2][emplacement-2]='X';autorisation_deplacement=0;}
    if(plateau[choixnum-1][emplacement+1]==0 && emplacement+1<=15 && choixnum-1>=0){plateau[choixnum-1][emplacement+1]='X';autorisation_deplacement=0;}
    else if(plateau[choixnum-2][emplacement+2]==0 && emplacement+2<=15 && choixnum-2>=0){plateau[choixnum-2][emplacement+2]='X';autorisation_deplacement=0;}
    if(plateau[choixnum+1][emplacement-1]==0 && emplacement-1>=0 && choixnum+1<=15){plateau[choixnum+1][emplacement-1]='X';autorisation_deplacement=0;}
    else if(plateau[choixnum+2][emplacement-2]==0 && emplacement-2>=0 && choixnum+2<=15){plateau[choixnum+2][emplacement-2]='X';autorisation_deplacement=0;}
    return autorisation_deplacement;
}


/*
######################## fonction second_saut######################
variable :

	plateau : recupere le tableau du jeu
	
	bouger : permet de verifier si il le joueur peut effectuer un second saut
	
	emplacement : permet de connaitre la colonne du pion
	
	choixnum : permet de connaitre la ligne du pion	
###############################################################

*/

int second_saut(int plateau[][16],int bouger,int emplacement,int choixnum)
{
    if(plateau[choixnum-1][emplacement]!=0 && choixnum-1>=0 && plateau[choixnum-2][emplacement]==0 && choixnum-2>=0){plateau[choixnum-2][emplacement]='X';bouger=1;}
    if(plateau[choixnum+1][emplacement]!=0 && choixnum+1<=15 && plateau[choixnum+2][emplacement]==0 && choixnum+2<=15){plateau[choixnum+2][emplacement]='X';bouger=1;}
    if(plateau[choixnum][emplacement-1]!=0 && emplacement-1>=0 && plateau[choixnum][emplacement-2]==0 && emplacement-2>=0){plateau[choixnum][emplacement-2]='X';bouger=1;}
    if(plateau[choixnum][emplacement+1]!=0 && emplacement+1<=15 && plateau[choixnum][emplacement+2]==0 && emplacement+2<=15){plateau[choixnum][emplacement+2]='X';bouger=1;}
    if(plateau[choixnum+1][emplacement+1]!=0 && choixnum+1<=15 && emplacement+1<=15 && plateau[choixnum+2][emplacement+2]==0 && choixnum+2<=15 && emplacement+2<=15){plateau[choixnum+2][emplacement+2]='X';bouger=1;}
    if(plateau[choixnum-1][emplacement-1]!=0 && choixnum-1>=0 && emplacement-1>=0 && plateau[choixnum-2][emplacement-2]==0 && choixnum-2>=0 && emplacement-2>=0){plateau[choixnum-2][emplacement-2]='X';bouger=1;}
    if(plateau[choixnum-1][emplacement+1]!=0 && choixnum-1>=0 && emplacement+1<=15 && plateau[choixnum-2][emplacement+2]==0 && choixnum-2>=0 && emplacement+2<=15){plateau[choixnum-2][emplacement+2]='X';bouger=1;}
    if(plateau[choixnum+1][emplacement-1]!=0 && choixnum+1<=15 && emplacement-1>=0 && plateau[choixnum+2][emplacement-2]==0 && choixnum+2<=15 && emplacement-2>=0){plateau[choixnum+2][emplacement-2]='X';bouger=1;}
    return bouger;
}


/*
######################## fonction bloquer######################
variable :

    plateau : recupere le tableau

    joueur : permet de connaitre le joueur qui joue
###############################################################
*/

int bloquer(int plateau[][16],int joueur)
{
    int deplace=1,i,j;
    for(j=0;j<16;j++)
    {
        for(i=0;i<16;i++)//on verifie pour chaque pion du joueur si il peut au moins en bouger un 
        {
			if(joueur==plateau[j][i]) deplace=premiermouvement(plateau,deplace,i,j);//si il peut se deplacer alors deplace prendra 0 comme valeur
        }
    }
    for(j=0;j<16;j++)// comme on se sert de la fonction premiermouvement alors il faut supprimer les X inscris dans la tableau
    {
        for(i=0;i<16;i++)
        {
            if(plateau[j][i]=='X')plateau[j][i]=0;
        }
    }
     return deplace;
}


/*
######################## fonction mouvement######################
variable :

    plateau : recupere le tableau de jeu

    nbjoueurs : permet de connaitre le nombre de joueurs
	
	joueur : permet de connaitre le numero du joueur
	
	tableau_fin : permet de recupere pour la version joueurs les joueurs qui ont terminé

	tableau_deplacement : permet de recupere le tableau du nombre de deplacements pour chaque joueurs
###############################################################
*/

int mouvement(int plateau[][16],int joueur,int nbjoueurs,int tableau_deplacement[],int tableau_fin[])
{
    int choixnum=0,emplacement=0,i,j,pioncara,pionnum,autorisation_deplacement,bouger=1,deplacement_obligatoire=0, bloque=0;
    char choixcara,tabord[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //pour deux joueurs on verifie que un joueur ne soit pas bloqué
    if(nbjoueurs<3)bloque=bloquer(plateau,joueur);//option de partie deux joueurs
    if(nbjoueurs>2)//option de partie a quatre joueurs
    {
        if(tableau_fin[joueur-1]==1)//jouer a la place du coequipier si celui ci a terminé
        {
            if(joueur==1)joueur=3;
            if(joueur==2)joueur=4;
            if(joueur==3)joueur=1;
            if(joueur==4)joueur=2;
        }
    }
    if(bloque==0)//pour deux joueurs si il n'y a pas de blocage
    {
        //---------------------------------------------------------------------------
        //---------------------------------------------------------------------------
        //jusqu'a qu'il joue
        while(bouger==1)
        {
        //---------------------------------------------------------------------------
        //---------------------------------------------------------------------------
        //ici le joueur choisit un pion : tout d'abord il choisit un pion dans le plateau puis on verifie si il est bien son pion et si on peut le bouger
         do
        {
            emplacement=0;
            printf("\njoueur %d a toi de jouer\n",joueur);
            do
            {
                  printf("choisissez le caractere puis le nombre :");
                  scanf("%c",&choixcara);
                  scanf("%d",&choixnum);
                  while(getchar() != '\n');
            }
            while(((choixcara<'a' || choixcara>'p') && (choixcara<'A' || choixcara>'P')) || (16<choixnum || choixnum<1 ));
            while(toupper(choixcara)!=tabord[emplacement])emplacement++;
            choixnum=choixnum-1;
        }
        while(plateau[choixnum][emplacement]!=joueur);/*attention joueur 1 peut pas choisir 2*/

        //---------------------------------------------------------------------------
        //---------------------------------------------------------------------------
        // ici on verifie si le joueur peut bouger le pion si il peut alors on insere des croix et on met autorisation_deplacement =1
        autorisation_deplacement=1;
        autorisation_deplacement=premiermouvement(plateau,autorisation_deplacement,emplacement,choixnum);
        //---------------------------------------------------------------------------
        //---------------------------------------------------------------------------
        //si il peut bouger
        if(autorisation_deplacement==0)
        {
            //---------------------------------------------------------------------------
            //---------------------------------------------------------------------------
            //prend la valeur 1 car il faut au moin un deplacement
            deplacement_obligatoire=1;
            //---------------------------------------------------------------------------
            //---------------------------------------------------------------------------
            //1 parce que il doit faire un deplacement obligatoire et apres il a le choix si il a effectué au saut de refaire un saut
            bouger=1;
            while(bouger==1)
            {
                //---------------------------------------------------------------------------
                //---------------------------------------------------------------------------
                // on affiche ou il peut jouer
                afficheplateau(plateau);
                //---------------------------------------------------------------------------
                //---------------------------------------------------------------------------
                // on met en memoire l'emplacement du pion avant mouvement pour ne pas faire des sauts a l'infini
                pioncara=emplacement;
                pionnum=choixnum;
                //---------------------------------------------------------------------------
                //---------------------------------------------------------------------------
                //ici on propose au joueur si il peut faire un autre deplacement apres un premier deplacement
                if(deplacement_obligatoire==0)
                {
                    do
                    {
                        printf("voulez vous bouger votre pion 1 oui 0 non :");
                        scanf("%d",&deplacement_obligatoire);
                        while(getchar() != '\n');
                    }
                    while(deplacement_obligatoire!=1 && deplacement_obligatoire!=0);

                }
                //---------------------------------------------------------------------------
                //---------------------------------------------------------------------------
                //ici on gere le deplacement du joueur
                if(deplacement_obligatoire==1)
                {
                    //---------------------------------------------------------------------------
                    //---------------------------------------------------------------------------
                    //ici le joueur choisie sur qu'elle x il veut se deplacer
                    do
                    {
                        emplacement=0;
                        printf("\njoueur %d saisir case deplacement\n",joueur);
                        do
                        {
                              printf("choisissez le caractere puis le nombre :");
                              scanf("%c",&choixcara);
                              scanf("%d",&choixnum);
                              while(getchar() != '\n');
                        }
                        while(((choixcara<'a' || choixcara>'p') && (choixcara<'A' || choixcara>'P')) || (16<choixnum || choixnum<1 ));
                        while(toupper(choixcara)!=tabord[emplacement])emplacement++;
                        choixnum=choixnum-1;
                    }
                    while(plateau[choixnum][emplacement]!='X');
                    //---------------------------------------------------------------------------
                    //---------------------------------------------------------------------------
                    //on supprime les x du plateau du dernier deplacement
                    for(j=0;j<16;j++)
                    {
                        for(i=0;i<16;i++)
                        {
                            if(plateau[j][i]=='X')plateau[j][i]=0;
                        }
                    }
                    //---------------------------------------------------------------------------
                    //---------------------------------------------------------------------------
                    //on bouge le pion du plateau
                    plateau[choixnum][emplacement]=joueur;
                    //---------------------------------------------------------------------------
                    //---------------------------------------------------------------------------
                    //on regarde si il y a un autre deplacement possible bien sur si le joueur a sauté un pion
                    bouger=0;
                    if(choixnum>pionnum+1 || emplacement>pioncara+1 || choixnum<pionnum-1 || emplacement<pioncara-1)
                    {
                        bouger=second_saut(plateau,bouger,emplacement,choixnum);
                    }
                    //---------------------------------------------------------------------------
                    //---------------------------------------------------------------------------
                    //on met zero sur la case du pion qui a etait bouger precedement pour eviter le saut infinie et ajoute deplacement
                    plateau[pionnum][pioncara]=0;
                    tableau_deplacement[joueur-1]=tableau_deplacement[joueur-1]+1;
                    //---------------------------------------------------------------------------
                    //---------------------------------------------------------------------------
                    //pour montrer qu'il a fait un deplacement obligatoire et maintenant il a le choix
                    deplacement_obligatoire=0;
                }
                //---------------------------------------------------------------------------
                //---------------------------------------------------------------------------
                //indique que le joueur ne veut pas jouer la saut non obligatoire apres un premier deplacement ou il n'y a pas de possibilité de mouvement
                else bouger=0;
                }

                //---------------------------------------------------------------------------
                //---------------------------------------------------------------------------
                //on met a jour le plateau en enlevant les croix
                for(j=0;j<16;j++)
                {
                    for(i=0;i<16;i++)
                    {
                        if(plateau[j][i]=='X')plateau[j][i]=0;
                    }
                }
                //---------------------------------------------------------------------------
                //---------------------------------------------------------------------------

        }
        //---------------------------------------------------------------------------
        //---------------------------------------------------------------------------
        //si le joueur ne peut pas bouger le pion selectionné
        else printf("selectionner un pion bougeable et votre pion");/*il faut seletionner un pion bougeable*/
        }
    }
    return bloque;
}
