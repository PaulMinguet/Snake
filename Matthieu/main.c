#include <stdio.h>
#include<stdlib.h>
#include<graph.h>
#define ligneMax 40
#define colonneMax 60

	int coactux = (colonneMax/2),
	coactuy = (ligneMax/2);


int main()
{	couleur fond;
	int map[ligneMax][colonneMax];

	int buttonP = XK_Right;



    InitialiserGraphique();
    CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80);
    EffacerEcran(CouleurParComposante(0, 0, 0));
    ChoisirCouleurDessin(CouleurParNom("green"));
    RemplirRectangle(10,10,colonneMax*10,ligneMax*10);					/*RemplirRectangle(int x,int y,int l,int h);*/
    initSnake();

   // buttonP = movSnake(buttonP);
    Touche();
    

    return EXIT_SUCCESS;
}

void initSnake(){
ChoisirCouleurDessin(CouleurParNom("black"));
RemplirRectangle(coactux*10,coactuy*10,10,10);

}


int movSnake(int buttonP){
	if(ToucheEnAttente()){
		if (Touche() == XK_Left)
		{
			buttonP = XK_Left;
		}
		if (Touche() == XK_Right)
		{
			buttonP = XK_Right;

		}
		if (Touche() == XK_Up)
		{
			buttonP = XK_Up;

		}
		if (Touche() == XK_Down)
		{
			buttonP = XK_Down;

		}
	}

	if (buttonP == XK_Left)
	{
		
	}
	if (buttonP == XK_Right)
	{

	}
	if (buttonP == XK_Up)
	{

	}
	if (buttonP == XK_Down)
	{
		
	}
	return buttonP;
}

