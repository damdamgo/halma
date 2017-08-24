
/*
######################## fonction.h######################

permet de faire connaitre les fonctions aux autres fichiers

###############################################################
*/
void initialiseplateau(int plateau[][16],int nbjoueurs);
void afficheplateau(int plateau[][16]);
int mouvement(int plateau[][16],int joueur,int nbjoueurs,int tableau_deplacement[],int tableau_fin[]);
int verificationfin(int plateau[][16],int nbjoueurs);
void verification_fin4(int plateau[][16],int terminer[]);



