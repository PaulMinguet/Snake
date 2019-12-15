/**************************************************************************************/
/**************************************************************************************/
/****************************************MAIN.C****************************************/
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


int coactux = (colonneMax/2),
coactuy = (ligneMax/2);


/*------------------------------------initSnake------------------------------------*/

Serpent *initSnake(){
	Coordonnees tete;
	Serpent *leSerpent = initialisation();
	ChoisirCouleurDessin(CouleurParNom("black"));
	system("/home/paul/IUT/PT11_APL2019/Paul/serpent.c");
	tete = premier(leSerpent);
	insertionFin(leSerpent, tete.x, tete.y+1);
	insertionFin(leSerpent, tete.x, tete.y+2);
	insertionFin(leSerpent, tete.x, tete.y+3);
	insertionFin(leSerpent, tete.x, tete.y+4);
	insertionFin(leSerpent, tete.x, tete.y+5);
	insertionFin(leSerpent, tete.x, tete.y+6);
	insertionFin(leSerpent, tete.x, tete.y+7);
	insertionFin(leSerpent, tete.x, tete.y+8);
	insertionFin(leSerpent, tete.x, tete.y+9);
	RemplirRectangle(tete.x*proporpix,tete.y*proporpix,proporpix,proporpix);				
	return leSerpent;

}
/*------------------------------------checkMovSnake------------------------------------*/

int checkMovSnake(int buttonP){
/*cette fonction a pour usage d'associer a la variable buttonP
la valeur de la derniere touche préssée*/
	if(ToucheEnAttente()){
		switch(Touche()){			
			case XK_Left :
			if (buttonP == XK_Right)
			{
				buttonP == XK_Right;break;
			}else{
				buttonP = XK_Left;break;
			}
			
			case XK_Right :
			if (buttonP == XK_Left)
			{
				buttonP == XK_Left;break;
			}else{
				buttonP = XK_Right;break;
			}
			
			case XK_Up :
			if (buttonP == XK_Down)
			{
				buttonP == XK_Up;break;
			}else{
				buttonP = XK_Up;break;
			}


			case XK_Down :
			if (buttonP == XK_Up)
			{
				buttonP == XK_Up;break;
			}else{
				buttonP = XK_Down;break;
			}
		}
		
	}


	return buttonP;
}
/*------------------------------------movSnake------------------------------------*/

Coordonnees movSnake(int buttonP,Coordonnees coactu){
	/*cette donction permet de changer la direction du serpent
	soustrayant/additionant les valeurs d'une variable de type coordoonnees*/

	if (buttonP == XK_Left)
	{	
		coactu.x--;

	}
	if (buttonP == XK_Right)
	{
		coactu.x++;
	}
	if (buttonP == XK_Up)
	{
		coactu.y--;
	}
	if (buttonP == XK_Down)
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
void actuAffichage(Coordonnees tete,Coordonnees queue){
	/*actualise la position de la tete du snake*/
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(tete.x*proporpix,tete.y*proporpix,proporpix,proporpix);
	/*efface la derniere valeur de la queue du snake*/
	ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
	RemplirRectangle(queue.x*proporpix,queue.y*proporpix,proporpix,proporpix);



}

/*------------------------------------Collisions Mur----------------------------------*/
void collisionsmurs(Coordonnees tete){
	int fin = 0;
	if(tete.x <= 1 || tete.x >= colonneMax || tete.y <= 1 || tete.y >= ligneMax){
		fin = 1;
		ChoisirCouleurDessin(CouleurParNom("black"));
		EcrireTexte((colonneMax*proporpix+20)/2-TailleChaineEcran("Game Over", 2)/2, (ligneMax*proporpix+80)/2, "Game Over", 2);
		EcrireTexte((colonneMax*proporpix+20)/2-TailleChaineEcran("Appuyez sur 'q' pour quitter", 1)/2, (ligneMax*proporpix+80)/2+20, "Appuyez sur 'q' pour quitter", 1);
		while (1){
			if(Touche() == XK_q){
				printf("p\n");
				FermerGraphique();
				exit(1);

			}else{}
		}
		
	}
}


/*------------------------------------Pause----------------------------------*/
/*int pause(){
	if (buttonP == XK_Space){
		fin = !fin;
	}
}

*/
/*------------------------------------MAIN------------------------------------*/
int main()
{
	couleur fond;
	Coordonnees tete, queue;
	int pommes[ligneMax][colonneMax];
	int buttonP = XK_Right;
	long suivant= Microsecondes()+CYCLE;
	int i,x,y;
	srand(time(NULL));	
	tete.x = 20;
	tete.y = 26;

	for (x = 0; x < ligneMax; ++x)
	{
		for (y = 0; y < colonneMax; ++y)
		{
			pommes[x][y] = 0;
		}
	}

	InitialiserGraphique();
	CreerFenetre(proporpix,proporpix,colonneMax*proporpix+20,ligneMax*proporpix+80); 		/*creation fenetre*/
	EffacerEcran(CouleurParComposante(0, 0, 0));				                            /*coloration du fond en noir*/						
	ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));				        /*selection de la couleur*/
    RemplirRectangle(proporpix,proporpix,colonneMax*proporpix,ligneMax*proporpix);			/*RemplirRectangle(int x,int y,int l,int h);*/
	Serpent *leSerpent = initSnake();
	initAffichage();

	for ( i = 0; i < QUANTITEPOMME; ++i)
	{ 		
		
		for (;;)
		{
			x = rand()%(colonneMax-2)+1;
			y = rand()%(ligneMax-2)+1;

			if (pommes[x][y] == 0)
			{ 
				ChoisirCouleurDessin(CouleurParComposante(255, 0, 0));
				RemplirRectangle(x*proporpix,y*proporpix,proporpix,proporpix);
				pommes[x][y] = 1;

				printf("%d %d\n",x ,y );
				break;
			}
		}

	}
	for (;;)													                   /*début du jeu*/
	{		
			if (ToucheEnAttente())								                           /*verifie si il y a une touche dans le tampon*/
		{
				buttonP = checkMovSnake(buttonP);				                           /*attribue a buttonP la derniere touche préssé*/
		}

		if (Microsecondes()>suivant)
		{	

			tete = movSnake(buttonP,tete);
			serpentCannibale(leSerpent,tete.x,tete.y);
			queue = dernier(leSerpent);
			deplacement(leSerpent,tete.x,tete.y);
			collisionsmurs(tete);


			if (pommes[tete.x][tete.y] == 1)
			{
				insertionFin(leSerpent, queue.x, queue.y);
				pommes[tete.x][tete.y] = 0;
				
				for (;;)
				{
					x = rand()%(colonneMax-2)+1;
					y = rand()%(ligneMax-2)+1;

					if (pommes[x][y] == 0)
					{ 
						ChoisirCouleurDessin(CouleurParComposante(255, 0, 0));
						RemplirRectangle(x*proporpix,y*proporpix,proporpix,proporpix);
						pommes[x][y] = 1;
						printf("%d %d\n",x ,y );
						break;
					}


				}
			}

	   			actuAffichage(tete,queue);
				suivant= Microsecondes()+CYCLE;
			}
		}
		Touche();
		return EXIT_SUCCESS;
	}