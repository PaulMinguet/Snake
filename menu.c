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
#include "menu.h"
#define ligneMax 60
#define colonneMax 80

int menu()
{
	/* Afficher menu */
	InitialiserGraphique();
    CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80);
    EffacerEcran(CouleurParComposante(0, 0, 0));
    ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
    RemplirRectangle(0,0,colonneMax*10+20,ligneMax*10+80);
    ChargerImage("./img/fond_g.png", colonneMax*10/9, ligneMax*10/25, 0, 0, 150, 150);
    ChargerImage("./img/fond_d.png", 3*colonneMax*10/4, ligneMax*10/25, 0, 0, 150, 150);
    ChoisirCouleurDessin(CouleurParComposante(218, 165, 32));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Snake", 2)/2, (ligneMax*10+80)/6, "Snake", 2);		/*TailleChaineEcran("Snake", 2)/2 : prend la moitié de la taille en pixel de "Snake"*/
    ChoisirCouleurDessin(CouleurParComposante(218, 165, 32));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("SOLO", 2)/2, (ligneMax*10+80)/2, "SOLO", 2);
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Multijoueur", 2)/2, (ligneMax*10+80)/1.75, "Multijoueur", 2);
    ChoisirCouleurDessin(CouleurParComposante(100, 100, 100));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Quitter", 2)/2, (ligneMax*10+80)/1.2, "Quitter", 2);

 	while (True){
 	while(SourisCliquee()) {
	 	SourisPosition();
	 	if(_X >= (colonneMax*10+20)/2-TailleChaineEcran("SOLO", 2)/2 && _X <= (colonneMax*10+20)/2+TailleChaineEcran("SOLO", 2)/2 && _Y >= (ligneMax*10+80)/2-20 && _Y <= (ligneMax*10+80)/2){
	 		FermerGraphique();
	 		return 1;				/*lance solo*/
	 		
	 	}
	 	if(_X >= (colonneMax*10+20)/2-TailleChaineEcran("Multijoueur", 2)/2 && _X <= (colonneMax*10+20)/2+TailleChaineEcran("Multijoueur", 2)/2 && _Y >= (ligneMax*10+80)/1.75-20 && _Y <= (ligneMax*10+80)/1.75){
	 		FermerGraphique();
	 		return 2;				/*lance multijoueur*/
	 		
	 	}
	 	if(_X >= (colonneMax*10+20)/2-TailleChaineEcran("Quitter", 2)/2 && _X <= (colonneMax*10+20)/2+TailleChaineEcran("Quitter", 2)/2 && _Y >= (ligneMax*10+80)/1.2-20 && _Y <= (ligneMax*10+80)/1.2){
	 		FermerGraphique();
	 		return 3;				/*Quitte la fenetre*/
	 		
	 		
	 	}
	 	}
	}
	FermerGraphique();
	return EXIT_SUCCESS;
}

/*gcc menu.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph*/