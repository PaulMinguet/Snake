#include <stdio.h>
#include<stdlib.h>
#include<graph.h>
#define ligneMax 40
#define colonneMax 60
#define CYCLE 50000L

int coactux = (colonneMax/2),
coactuy = (ligneMax/2);
int fin = 0;

/*------------------------------------initSnake------------------------------------*/

void initSnake(){
	ChoisirCouleurDessin(CouleurParNom("black"));
	system("/home/paul/IUT/PT11_APL2019/Paul/serpent.c");
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

	ChoisirCouleurDessin(CouleurParNom("grey"));
	RemplirRectangle(10,10,colonneMax*10,ligneMax*10);
	ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
	RemplirRectangle(20,20,colonneMax*10-20,ligneMax*10-20);
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(coactux*10,coactuy*10,10,10);		


}

/*------------------------------------Collisions Mur----------------------------------*/
int collisionsmurs(){
	if(coactux*10 <= 10 || coactux*10 >= colonneMax*10 || coactuy <= 1 || coactuy >= ligneMax){
		fin = 1;
		EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Game Over", 2)/2, (ligneMax*10+80)/2, "Game Over", 2);
		EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Appuyez sur une touche pour quitter", 1)/2, (ligneMax*10+80)/2+20, "Appuyez sur une touche pour quitter", 1);
	}
}

/*------------------------------------Collisions Mur----------------------------------*/
int pause(){
	if (buttonP == XK_Space){
		fin = !fin;
	}
}


/*------------------------------------MAIN------------------------------------*/
int main()
{	couleur fond;
	int map[ligneMax][colonneMax];

	int buttonP = XK_Right;
	
	long suivant= Microsecondes()+CYCLE;


	InitialiserGraphique();

	CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80); 		/*creation fenetre*/
	EffacerEcran(CouleurParComposante(0, 0, 0));				/*coloration du fond en noir*/						
	ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));				/*selection de la couleur*/
    RemplirRectangle(10,10,colonneMax*10,ligneMax*10);			/*RemplirRectangle(int x,int y,int l,int h);*/
	initSnake();

	for (;fin != 1;)													/*début du jeu*/
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
		collisionsmurs();
	}



	Touche();


	return EXIT_SUCCESS;
}

//gcc main.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph