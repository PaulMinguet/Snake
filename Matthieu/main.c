#include <stdio.h>
#include<stdlib.h>
#include<graph.h>
#define ligneMax 40
#define colonneMax 60
#define CYCLE 100000L

int coactux = (colonneMax/2),
coactuy = (ligneMax/2);


int main()
{	couleur fond;
	int map[ligneMax][colonneMax];

	int buttonP = XK_Right;
	
	long suivant= Microsecondes()+CYCLE;


	InitialiserGraphique();
	CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80);
	EffacerEcran(CouleurParComposante(0, 0, 0));
	ChoisirCouleurDessin(CouleurParNom("green"));
    RemplirRectangle(10,10,colonneMax*10,ligneMax*10);					/*RemplirRectangle(int x,int y,int l,int h);*/
	initSnake();

	for (;;)
	{
			if (ToucheEnAttente())
			{
				buttonP = checkMovSnake(buttonP);
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

void initSnake(){
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(coactux*10,coactuy*10,10,10);

}


int checkMovSnake(int buttonP){
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



void actuFenetre(){

	ChoisirCouleurDessin(CouleurParNom("green"));
	RemplirRectangle(10,10,colonneMax*10,ligneMax*10);
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(coactux*10,coactuy*10,10,10);		

}

