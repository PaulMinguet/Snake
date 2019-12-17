/**************************************************************************************/
/**************************************************************************************/
/****************************************MENU.C****************************************/
/***********************************PROJET SNAKE 2019**********************************/
/********************************IUT UPEC FONTAINEBLEAU********************************/
/********************************** MATTHIEU CARRICO***********************************/
/*************************************PAUL MINGUET*************************************/
/**************************************************************************************/
/**************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#define ligneMax 60
#define colonneMax 80

int main()
{
	int x, y;

	/* Afficher menu */
	InitialiserGraphique();
    CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80);
    EffacerEcran(CouleurParComposante(0, 0, 0));
    ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
    RemplirRectangle(0,0,colonneMax*10+20,ligneMax*10+80);
    ChoisirCouleurDessin(CouleurParComposante(218, 165, 32));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Snake", 2)/2, (ligneMax*10+80)/3, "Snake", 2);		/*TailleChaineEcran("Snake", 2)/2 : prend la moitié de la taille en pixel de "Snake"*/
    ChoisirCouleurDessin(CouleurParComposante(218, 165, 32));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Jouer", 2)/2, (ligneMax*10+80)/2, "Jouer", 2);
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Multijoueurs", 2)/2, (ligneMax*10+80)/1.75, "Multijoueurs", 2);
    ChoisirCouleurDessin(CouleurParComposante(179, 179, 179));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Options", 2)/2, (ligneMax*10+80)/1.5, "Options", 2);
    ChoisirCouleurDessin(CouleurParComposante(100, 100, 100));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Quitter", 2)/2, (ligneMax*10+80)/1.2, "Quitter", 2);

 	while (1 != 0){
 	while(!SourisCliquee()) {}
	 	SourisPosition();
	 	if(_X >= (colonneMax*10+20)/2-TailleChaineEcran("Jouer", 2)/2 && _X <= (colonneMax*10+20)/2+TailleChaineEcran("Jouer", 2)/2 && _Y >= (ligneMax*10+80)/2-20 && _Y <= (ligneMax*10+80)/2){
	 		FermerGraphique();
	 		system("./solo");
	 		return EXIT_SUCCESS;
	 	}
	 	if(_X >= (colonneMax*10+20)/2-TailleChaineEcran("Multijoueurs", 2)/2 && _X <= (colonneMax*10+20)/2+TailleChaineEcran("Multijoueurs", 2)/2 && _Y >= (ligneMax*10+80)/1.75-20 && _Y <= (ligneMax*10+80)/1.75){
	 		FermerGraphique();
	 		system("./multijoueurs");
	 		return EXIT_SUCCESS;
	 	}
	 	if(_X >= (colonneMax*10+20)/2-TailleChaineEcran("Options", 2)/2 && _X <= (colonneMax*10+20)/2+TailleChaineEcran("Options", 2)/2 && _Y >= (ligneMax*10+80)/1.5-20 && _Y <= (ligneMax*10+80)/1.5){
	 		FermerGraphique();
	 		system("./options");
	 		return EXIT_SUCCESS;
	 	}
	 	if(_X >= (colonneMax*10+20)/2-TailleChaineEcran("Quitter", 2)/2 && _X <= (colonneMax*10+20)/2+TailleChaineEcran("Quitter", 2)/2 && _Y >= (ligneMax*10+80)/1.2-20 && _Y <= (ligneMax*10+80)/1.2){
	 		FermerGraphique();
	 		return EXIT_SUCCESS;
	 	}
	}
	FermerGraphique();
	return EXIT_SUCCESS;
}

/*gcc menu.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph*/