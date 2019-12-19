    /**************************************************************************************/
    /**************************************************************************************/
    /****************************************JEU.C*****************************************/
    /***********************************PROJET SNAKE 2019**********************************/
    /********************************IUT UPEC FONTAINEBLEAU********************************/
    /********************************** MATTHIEU CARRICO***********************************/
    /*************************************PAUL MINGUET*************************************/
    /**************************************************************************************/
    /**************************************************************************************/

    #include <stdio.h>
    #include <stdlib.h>
    #include <graph.h>
    #include <time.h>
    #include "serpent.h"
    #include "jeu.h"
    #define codeP1x 20
    #define codebP1y 26
    #define codeP2x 20
    #define codebP2y 28
    #define QUANTITEPOMMEMULTI 10


int score = 0;
int nvscore = 0;
unsigned int secondes = 0;
unsigned int minutes = 0;
unsigned long depart = 0;


    /*------------------------------------initSnake------------------------------------*/

Serpent *initSnake(){
 int t = 1;
 Coordonnees tete;
 Serpent *leSerpent = initialisation();
 ChoisirCouleurDessin(CouleurParNom("black"));
 tete = premier(leSerpent);
 for(; t<=9; t++){
  insertionFin(leSerpent, tete.x, tete.y+t);
}
RemplirRectangle(tete.x*proporpix,tete.y*proporpix,proporpix,proporpix);				
return leSerpent;

}

    /*------------------------------------checkMovSnake------------------------------------*/

Button checkMovSnake(Button buttonP){
    /*cette fonction a pour usage d'associer a la variable buttonP
    la valeur de la derniere touche préssée*/
 if(ToucheEnAttente()){
  switch(Touche()){			
   case XK_Left :
   if (buttonP.P1 == XK_Right)           /*cette condition permet d'eviter que le joeur ce retourne sur lui meme on retrouve*/
   {                                     /*des conditions similaires pour chaque touches*/
    buttonP.P1 = XK_Right;break;
  }else{
    buttonP.P1 = XK_Left;break;
  }

  case XK_Right :
  if (buttonP.P1 == XK_Left)
  {
    buttonP.P1= XK_Left;break;
  }else{
    buttonP.P1 = XK_Right;break;
  }

  case XK_Up :
  if (buttonP.P1 == XK_Down)
  {
    buttonP.P1 = XK_Down;break;
  }else{
    buttonP.P1 = XK_Up;break;
  }


  case XK_Down :
  if (buttonP.P1 == XK_Up)
  {
    buttonP.P1 = XK_Up;break;
  }else{
    buttonP.P1 = XK_Down;break;
  }
  case XK_q :
  if (buttonP.P2 == XK_d)
  {
    buttonP.P2 = XK_d;break;
  }else{
    buttonP.P2= XK_q;break;
  }

  case XK_d :
  if (buttonP.P2 == XK_q)
  {
    buttonP.P2 = XK_q;break;
  }else{
    buttonP.P2 = XK_d;break;
  }

  case XK_z :
  if (buttonP.P2 == XK_s)
  {
    buttonP.P2 = XK_s;break;
  }else{
    buttonP.P2 = XK_z;break;
  }


  case XK_s :
  if (buttonP.P2 == XK_z)
  {
    buttonP.P2 = XK_z;break;
  }else{
    buttonP.P2 = XK_s;break;
  }

  case XK_space :
  for(;;){
    if (Touche() == XK_space){
      break;
    }
  }

  case XK_Escape :
  FermerGraphique();
  exit(0);

}

}


return buttonP;
}
    /*------------------------------------movSnake------------------------------------*/

Coordonnees movSnake(Button buttonP,Coordonnees coactu){
    /*cette donction permet de changer la direction du serpent
    soustrayant/additionant les valeurs d'une variable de type coordoonnees*/

  if (buttonP.P1 == XK_Left)
  {   
    coactu.x--;

  }
  if (buttonP.P1 == XK_Right)
  {
    coactu.x++;
  }
  if (buttonP.P1 == XK_Up)
  {
    coactu.y--;
  }
  if (buttonP.P1 == XK_Down)
  {
    coactu.y++;     
  }

  return coactu;
}

Coordonnees movSnakeP2(Button buttonP ,Coordonnees coactu){
    /*cette donction permet de changer la direction du serpent
    soustrayant/additionant les valeurs d'une variable de type coordoonnees*/

  if (buttonP.P2 == XK_q)
  {   
    coactu.x--;

  }
  if (buttonP.P2 == XK_d)
  {
    coactu.x++;
  }
  if (buttonP.P2 == XK_z)
  {
    coactu.y--;
  }
  if (buttonP.P2 == XK_s)
  {
    coactu.y++;     
  }

  return coactu;
}


    /*------------------------------------initialise la Fenetre------------------------------------*/
void initAffichage(){
 ChoisirCouleurDessin(CouleurParNom("grey"));
 RemplirRectangle(proporpix,proporpix,colonneMax*proporpix,ligneMax*proporpix);
 ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
 RemplirRectangle(20,20,colonneMax*proporpix-20,ligneMax*proporpix-20);
}
    /*------------------------------------actualise l'affichage------------------------------------*/
void actuAffichageP1(Coordonnees tete,Coordonnees queue){
    /*actualise la position de la tete du snake*/
  ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(tete.x*proporpix,tete.y*proporpix,proporpix,proporpix);
    /*efface la derniere valeur de la queue du snake*/
  ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
  RemplirRectangle(queue.x*proporpix,queue.y*proporpix,proporpix,proporpix);



}
void actuAffichageP2(Coordonnees tete,Coordonnees queue){
    /*actualise la position de la tete du snake*/
  ChoisirCouleurDessin(CouleurParComposante(255,255,255));
  RemplirRectangle(tete.x*proporpix,tete.y*proporpix,proporpix,proporpix);
    /*efface la derniere valeur de la queue du snake*/
  ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
  RemplirRectangle(queue.x*proporpix,queue.y*proporpix,proporpix,proporpix);



}

    /*------------------------------------Collisions Mur----------------------------------*/
void collisionsmurs(Coordonnees tete){
 if(tete.x <= 1 || tete.x >= colonneMax || tete.y <= 1 || tete.y >= ligneMax){
    		/*fin = 1;*/
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte((colonneMax*proporpix+20)/2-TailleChaineEcran("Game Over", 2)/2, (ligneMax*proporpix+80)/2, "Game Over", 2);
  EcrireTexte((colonneMax*proporpix+20)/2-TailleChaineEcran("Appuyez sur 'q' pour quitter", 1)/2, (ligneMax*proporpix+80)/2+20, "Appuyez sur 'q' pour quitter", 1);
  while (1){
   if(Touche() == XK_q){

    FermerGraphique();
    exit(0);

  }
}

}
}

    /*------------------------------------Timer----------------------------------*/
void timer(){
  char tpssec[10];
  char tpsmin[10];
  if((Microsecondes()+CYCLE) - depart > 1000000L){
   depart = Microsecondes();
   ChoisirCouleurDessin(CouleurParNom("black"));
   RemplirRectangle(0, ligneMax*proporpix+10, (colonneMax*proporpix+20)/2, 80);
   ChoisirCouleurDessin(CouleurParNom("white"));
   sprintf(tpssec, " :%02d ", secondes);
   sprintf(tpsmin, "%02d", minutes);
   EcrireTexte(30,ligneMax*proporpix+10+45,tpssec, 2);
   EcrireTexte(17,ligneMax*proporpix+10+45,tpsmin, 2);
   secondes = secondes + 1;
   if(secondes == 60){
    secondes = 0;
    minutes++;
  }

}
}

	/*------------------------------------Score----------------------------------*/
void addscore(int nvscore){
  char nbscore[10];
  ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(colonneMax*8.5, ligneMax*proporpix+10, (colonneMax*proporpix+20)/2, 80);
  ChoisirCouleurDessin(CouleurParNom("white"));
  sprintf(nbscore, " %07d ", score);
  EcrireTexte(colonneMax*8.5,ligneMax*proporpix+10+45,nbscore, 2);
  score = score + nvscore;

}



    /*------------------------------------JEU EN SOLO------------------------------------*/
int jeu()
{
 Coordonnees tete, queue;
 int pommes[colonneMax][ligneMax];
 Button buttonP;
 buttonP.P1 = XK_Right;
 long suivant= Microsecondes()+CYCLE;
 int i,x,y, placepomme;
 srand(time(NULL));	
 tete.x = 20;
 tete.y = 26;

 for (x = 0; x < colonneMax; ++x)                                               /*initialise le tableau contenant les pommes a 0*/
 {
  for (y = 0; y < ligneMax; ++y)
  {
   pommes[x][y] = 0;
 }
}

InitialiserGraphique();
CreerFenetre(proporpix,proporpix,colonneMax*proporpix+20,ligneMax*proporpix+80); 		/*creation fenetre*/
EffacerEcran(CouleurParComposante(0, 0, 0));				                                /*coloration du fond en noir*/						
ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));			          	          /*selection de la couleur*/
RemplirRectangle(proporpix,proporpix,colonneMax*proporpix,ligneMax*proporpix);		/*RemplirRectangle(int x,int y,int l,int h);*/
Serpent *leSerpent = initSnake();
initAffichage();

for ( i = 0; i < QUANTITEPOMME; ++i)                                               /*place des pommes de maniere aléatoire dans le tableau*/
{ 		

  for (;;)
  {
   x = rand()%(colonneMax-2)+1;
   y = rand()%(ligneMax-2)+1;

   if (pommes[x][y] == 0 && x != 1 && y != 1)
   { 
    ChoisirCouleurDessin(CouleurParComposante(255, 0, 0));                      /*affiche les pommes graphiquement*/
    RemplirRectangle(x*proporpix,y*proporpix,proporpix,proporpix);
    pommes[x][y] = 1;

    break;
  }
}

}

for (;;)													                            /*début du jeu*/
{		
    		if (ToucheEnAttente())								                           /*verifie si il y a une touche dans le tampon*/
  {
    				buttonP = checkMovSnake(buttonP);				                     /*attribue a buttonP la derniere touche préssé*/
  }

  if (Microsecondes()>suivant)
  {	
   timer();                                                               /*calcul et affiche le temps ecoulé depuis le début de la patie*/
   addscore(0);                                                           /*gere le score et l'affiche*/
   tete = movSnake(buttonP,tete);                                         /*recupere les coordonnées actuelles de la tete*/
   serpentCannibale(leSerpent,tete.x,tete.y);                             /*verifie que le serpent ne ce mord pas si il ce mord le joueur perd*/
   queue = dernier(leSerpent);                                            /*prend les coordonnées de la queue */
   deplacement(leSerpent,tete.x,tete.y);                                  /*gère le deplacement du serpent (voir le rapport)*/
   collisionsmurs(tete);                                                  /*vérifie que le serpent ne heurte pas un mur*/



   if (pommes[tete.x][tete.y] == 1)                                       /*vérifie si la case sur laquelle ce situe la tete du serpent contient une pomme*/
   {
    insertionFin(leSerpent, queue.x, queue.y);                            /*ajoute 2 segment aux serpent*/
    insertionFin(leSerpent, queue.x, queue.y);
    pommes[tete.x][tete.y] = 0;                                           /*remet la case contenant la pomme a 0*/

    do
    { placepomme = 0;
     x = rand()%(colonneMax-2)+1;                                         /*replace une pomme apres qu'elle est été mangé de manière aléatoire*/
     y = rand()%(ligneMax-2)+1;

     if (pommes[x][y] == 0 && verifPommePasDansSerpent(leSerpent,x,y)&& x != 1 && y !=1)
     { 

      addscore(5);
      ChoisirCouleurDessin(CouleurParComposante(255, 0, 0));
      RemplirRectangle(x*proporpix,y*proporpix,proporpix,proporpix);
      pommes[x][y] = 1;
      placepomme = 1;


    }


  }while(placepomme != 1);
}

actuAffichageP1(tete,queue);                                              /*actualise l'affichage uniquement du seprent*/
suivant= Microsecondes()+CYCLE;
}
}
Touche();
return EXIT_SUCCESS;
}
/*------------------------------------JEU EN MULTIJOUEUR------------------------------------*/
/*fonctionne relativement de la meme maniére que jeu ormis la gestion des collisions entres les joueurs*/
int jeuM()
{
  long suivant= Microsecondes()+CYCLE;
  int i,x,y,placepomme;
  Coordonnees teteP1, queueP1,teteP2, queueP2;
  int pommes[colonneMax][ligneMax];
  Button key;
  key.P1 = XK_Right;
  key.P2 = XK_d;

  srand(time(NULL));  
  teteP1.x = 20;
  teteP1.y = 26;
  teteP2.x = 20;
  teteP2.y = 28;

  for (x = 0; x < colonneMax; ++x)
  {
    for (y = 0; y < ligneMax; ++y)
    {
      pommes[x][y] = 0;
    }
  }

  InitialiserGraphique();
  CreerFenetre(proporpix,proporpix,colonneMax*proporpix+20,ligneMax*proporpix+80);        /*creation fenetre*/
  EffacerEcran(CouleurParComposante(0, 0, 0));                                            /*coloration du fond en noir*/                      
  ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));                                /*selection de la couleur*/
  RemplirRectangle(proporpix,proporpix,colonneMax*proporpix,ligneMax*proporpix);          /*RemplirRectangle(int x,int y,int l,int h);*/
  Serpent *leSerpent = initSnake(codeP1x, codebP1y);
  Serpent *leConcurrent = initSnake(codeP2x, codebP2y);
  initAffichage();

  for ( i = 0; i < QUANTITEPOMMEMULTI; ++i)
  {       

    for (;;)
    {
      x = rand()%(colonneMax-2)+1;
      y = rand()%(ligneMax-2)+1;

      if (pommes[x][y] == 0 && x != 1 && y != 1)
      { 
        ChoisirCouleurDessin(CouleurParComposante(255, 0, 0));
        RemplirRectangle(x*proporpix,y*proporpix,proporpix,proporpix);
        pommes[x][y] = 1;
        break;
      }
    }

  }
    for (;;)                                                                       /*début du jeu*/
  {       
            if (ToucheEnAttente())                                                         /*verifie si il y a une touche dans le tampon*/
    {
                key = checkMovSnake(key);                                                  /*attribue a buttonP la derniere touche préssé*/
    }
        if (ToucheEnAttente())                                                         /*verifie si il y a une touche dans le tampon*/
    {
                key = checkMovSnake(key);                                                  /*attribue a buttonP la derniere touche préssé*/
    }

    if (Microsecondes()>suivant)
    {   
      timer();
      teteP1 = movSnake(key,teteP1);
      teteP2 = movSnakeP2(key,teteP2);

      serpentCannibale(leSerpent,teteP1.x,teteP1.y);
      serpentCannibale(leConcurrent,teteP2.x,teteP2.y);
      serpentCannibale(leSerpent,teteP2.x,teteP2.y);
      serpentCannibale(leConcurrent,teteP1.x,teteP1.y);

      queueP1 = dernier(leSerpent);
      queueP2 = dernier(leConcurrent);
      deplacement(leSerpent,teteP1.x,teteP1.y);
      deplacement(leConcurrent,teteP2.x,teteP2.y);
      collisionsmurs(teteP1);
      collisionsmurs(teteP2);



      if (pommes[teteP1.x][teteP1.y] != 0)
      {
        insertionFin(leSerpent, queueP1.x, queueP1.y);
        insertionFin(leSerpent, queueP1.x, queueP1.y);
        pommes[teteP1.x][teteP1.y] = 0;

        for (;;)
        {
          x = rand()%(colonneMax-2)+1;
          y = rand()%(ligneMax-2)+1;

          if (pommes[x][y] == 0 && verifPommePasDansSerpent(leSerpent,x,y)&& verifPommePasDansSerpent(leConcurrent,x,y)&& x != 1 && y !=1)
          { 
            ChoisirCouleurDessin(CouleurParComposante(255, 0, 0));
            RemplirRectangle(x*proporpix,y*proporpix,proporpix,proporpix);
            pommes[x][y] = 1;
            break;
          }


        }
      }
      if (pommes[teteP2.x][teteP2.y] != 0)
      {
        insertionFin(leConcurrent, queueP2.x, queueP2.y);
        insertionFin(leConcurrent, queueP2.x, queueP2.y);
        pommes[teteP2.x][teteP2.y] = 0;

        do
        {
          placepomme = 0;
          x = rand()%(colonneMax-2)+1;
          y = rand()%(ligneMax-2)+1;

          if (pommes[x][y] == 0 && verifPommePasDansSerpent(leSerpent,x,y)&& verifPommePasDansSerpent(leConcurrent,x,y)&& x != 1 && y !=1)
          { 
            ChoisirCouleurDessin(CouleurParComposante(255, 0, 0));
            RemplirRectangle(x*proporpix,y*proporpix,proporpix,proporpix);
            pommes[x][y] = 1;
            placepomme = 1;

          }


        }while(placepomme != 1);
      }

      actuAffichageP1(teteP1,queueP1);
      actuAffichageP2(teteP2,queueP2);
      suivant= Microsecondes()+CYCLE;
    }
  }
  Touche();
  return EXIT_SUCCESS;
}
