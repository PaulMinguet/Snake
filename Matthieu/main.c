#include <stdio.h>
#include<stdlib.h>
#include<graph.h>
#define ligneMax 40
#define colonneMax 60
#define CYCLE 50000L

int coactux = (colonneMax/2),
coactuy = (ligneMax/2);

/*------------------------------------MAIN------------------------------------*/
int main()
{	couleur fond;
	int map[ligneMax][colonneMax];

	int buttonP = XK_Right;
	
	long suivant= Microsecondes()+CYCLE;


	InitialiserGraphique();

	CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80); 		/*creation fenetre*/
	EffacerEcran(CouleurParComposante(0, 0, 0));				/*coloration du fond en noir*/						
	ChoisirCouleurDessin(CouleurParNom("green"));				/*selection de la couleur*/
    RemplirRectangle(10,10,colonneMax*10,ligneMax*10);			/*RemplirRectangle(int x,int y,int l,int h);*/
	initSnake();

	for (;;)													/*début du jeu*/
	{
			if (ToucheEnAttente())								/*verifie si il y a une touche dans le tampon*/
			{
				buttonP = checkMovSnake(buttonP);				/*atribue a buttonP la derniere touche préssé*/
			}

		if (Microsecondes()>suivant)
		{
			movSnake(buttonP);
			actuFenetre();

			suivant= Microsecondes()+CYCLE;
		}
	}



	Touche();


	return EXIT_SUCCESS;
}
/*------------------------------------initSnake------------------------------------*/

void initSnake(){
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(coactux*10,coactuy*10,10,10);				/*place le snake au centre afin de commencer */

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

void movSnake(int buttonP){


	if (buttonP == XK_Left)
	{	
		coactux--;

	}
	if (buttonP == XK_Right)
	{
		coactux++;
	}
	if (buttonP == XK_Up)
	{
		coactuy--;
	}
	if (buttonP == XK_Down)
	{
		coactuy++;		
	}
}


/*------------------------------------actuFenetre------------------------------------*/
void actuFenetre(){

	ChoisirCouleurDessin(CouleurParNom("green"));
	RemplirRectangle(10,10,colonneMax*10,ligneMax*10);
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(coactux*10,coactuy*10,10,10);		

}

