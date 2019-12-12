#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "serpent.h"

#define ligneMax 40
#define colonneMax 60
#define CYCLE 50000L

int coactux = (colonneMax/2),
coactuy = (ligneMax/2);
int fin = 0;

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
	RemplirRectangle(tete.x*10,tete.y*10,10,10);				/*place le snake au centre afin de commencer */

	return leSerpent;

}
/*------------------------------------checkMovSnake------------------------------------*/

int checkMovSnake(int buttonP){
/*cette fonction a pour usage */
	if(ToucheEnAttente()){
		switch(Touche()){			
			case XK_Left :
			buttonP = XK_Left;break;
			case XK_Right :
			buttonP = XK_Right;break;
			case XK_Up :
			buttonP = XK_Up;break;
			case XK_Down :
			buttonP = XK_Down;break;
		}
		
	}


	return buttonP;
}
/*------------------------------------movSnake------------------------------------*/

Coordonnees movSnake(int buttonP,Coordonnees coactu){


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


/*------------------------------------actuFenetre------------------------------------*/
void initAffichage(){
	ChoisirCouleurDessin(CouleurParNom("grey"));
	RemplirRectangle(10,10,colonneMax*10,ligneMax*10);
	ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
	RemplirRectangle(20,20,colonneMax*10-20,ligneMax*10-20);
}
void actuAffichage(Coordonnees tete,Coordonnees queue){
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(tete.x*10,tete.y*10,10,10);
	ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
	RemplirRectangle(queue.x*10,queue.y*10,10,10);



}

/*------------------------------------Collisions Mur----------------------------------*/
int collisionsmurs(Coordonnees tete){
	if(tete.x <= 10 || tete.x >= colonneMax || tete.y <= 1 || tete.y >= ligneMax){
		fin = 1;
		EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Game Over", 2)/2, (ligneMax*10+80)/2, "Game Over", 2);
		EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Appuyez sur une touche pour quitter", 1)/2, (ligneMax*10+80)/2+20, "Appuyez sur une touche pour quitter", 1);
	}
}

/*------------------------------------Collisions Mur----------------------------------*/
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
	int map[ligneMax][colonneMax];

	int buttonP = XK_Right;
	
	long suivant= Microsecondes()+CYCLE;


	InitialiserGraphique();
	tete.x = 20;
	tete.y = 26;
	CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80); 		/*creation fenetre*/
	EffacerEcran(CouleurParComposante(0, 0, 0));				/*coloration du fond en noir*/						
	ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));				/*selection de la couleur*/
    RemplirRectangle(10,10,colonneMax*10,ligneMax*10);			/*RemplirRectangle(int x,int y,int l,int h);*/
	Serpent *leSerpent = initSnake();
	initAffichage();

	for (;fin != 1;)													/*début du jeu*/
	{
			if (ToucheEnAttente())								/*verifie si il y a une touche dans le tampon*/
			{
				buttonP = checkMovSnake(buttonP);				/*atribue a buttonP la derniere touche préssé*/
			}

		if (Microsecondes()>suivant)
		{
			tete = movSnake(buttonP,tete);
			queue = dernier(leSerpent);
			deplacement(leSerpent,tete.x,tete.y);
			actuAffichage(tete,queue);

			suivant= Microsecondes()+CYCLE;
		}
		collisionsmurs(tete);
	}



	Touche();


	return EXIT_SUCCESS;
}

//gcc main.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph