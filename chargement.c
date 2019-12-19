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
	/* Afficher chargement */
	InitialiserGraphique();
    CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80);
    EffacerEcran(CouleurParComposante(0, 0, 0));
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    ChargerImage("./bas.png", 10,(ligneMax*10+80)/12, 0, 0, 250, 250);
    EcrireTexte(10, (ligneMax*10+80)/12, "> : mouvement vers la droite", 2);		/*TailleChaineEcran("Snake", 2)/2 : prend la moitié de la taille en pixel de "Snake"*/
    EcrireTexte(10, (ligneMax*10+80)/12+(ligneMax*10+80)/15, "< : mouvement vers la gauche", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+2*((ligneMax*10+80)/15), "V : mouvement vers le bas", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+3*((ligneMax*10+80)/15), "^ : mouvement vers le bas", 2);

    ChoisirCouleurDessin(CouleurParComposante(179, 179, 179));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Options", 2)/2, (ligneMax*10+80)/1.5, "Options", 2);
    ChoisirCouleurDessin(CouleurParComposante(100, 100, 100));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Quitter", 2)/2, (ligneMax*10+80)/1.2, "Quitter", 2);

 	while (1 != 0){
	}
	FermerGraphique();
	return EXIT_SUCCESS;
}

/*gcc menu.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph*/