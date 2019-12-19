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
#include "chargement.h"
#include "jeu.h"
#define ligneMax 60
#define colonneMax 80

void solo(){
	ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    ChargerImage("./img/droite.png", 0,(ligneMax*10+80)/12-28, 0, 0, 28, 28);
    ChargerImage("./img/gauche.png", 0,(ligneMax*10+80)/12-28+((ligneMax*10+80)/15), 0, 0, 28, 28);
    ChargerImage("./img/haut.png", 0,(ligneMax*10+80)/12-28+2*((ligneMax*10+80)/15), 0, 0, 28, 28);
    ChargerImage("./img/bas.png", 0,(ligneMax*10+80)/12-28+3*((ligneMax*10+80)/15), 0, 0, 28, 28);
	EcrireTexte(10, (ligneMax*10+80)/12, "  : mouvement vers la droite", 2);		/*TailleChaineEcran("Snake", 2)/2 : prend la moitié de la taille en pixel de "Snake"*/
    EcrireTexte(10, (ligneMax*10+80)/12+(ligneMax*10+80)/15, "  : mouvement vers la gauche", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+2*((ligneMax*10+80)/15), "  : mouvement vers le haut", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+3*((ligneMax*10+80)/15), "  : mouvement vers le bas", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+4*((ligneMax*10+80)/15), "[ESPACE] : Pause", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+5*((ligneMax*10+80)/15), "[ESC] : Quitter", 2);
    ChoisirCouleurDessin(CouleurParComposante(100, 100, 100));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Appuyez sur [ESPACE] pour jouer", 2)/2, (ligneMax*10+80)/1.2, "Appuyez sur [ESPACE] pour jouer", 2);

    }

void multi(){
	ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    ChargerImage("./img/droite.png", 0,(ligneMax*10+80)/12-28+(ligneMax*10+80)/15, 0, 0, 28, 28);
    ChargerImage("./img/gauche.png", 0,(ligneMax*10+80)/12-28+2*((ligneMax*10+80)/15), 0, 0, 28, 28);
    ChargerImage("./img/haut.png", 0,(ligneMax*10+80)/12-28+3*((ligneMax*10+80)/15), 0, 0, 28, 28);
    ChargerImage("./img/bas.png", 0,(ligneMax*10+80)/12-28+4*((ligneMax*10+80)/15), 0, 0, 28, 28);
	EcrireTexte(10, (ligneMax*10+80)/12, "Joueur 1 (serpent noir) :", 2);
	EcrireTexte(10, (ligneMax*10+80)/12+(ligneMax*10+80)/15, "  : mouvement vers la droite", 2);		/*TailleChaineEcran("Snake", 2)/2 : prend la moitié de la taille en pixel de "Snake"*/
    EcrireTexte(10, (ligneMax*10+80)/12+2*(ligneMax*10+80)/15, "  : mouvement vers la gauche", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+3*((ligneMax*10+80)/15), "  : mouvement vers le haut", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+4*((ligneMax*10+80)/15), "  : mouvement vers le bas", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+5*(ligneMax*10+80)/15, "Joueur 2 (serpent blanc) :", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+6*(ligneMax*10+80)/15, "D : mouvement vers la droite", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+7*(ligneMax*10+80)/15, "Q : mouvement vers la gauche", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+8*((ligneMax*10+80)/15), "Z : mouvement vers le haut", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+9*((ligneMax*10+80)/15), "S : mouvement vers le bas", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+10*((ligneMax*10+80)/15), "[ESPACE] : Pause", 2);
    EcrireTexte(10, (ligneMax*10+80)/12+11*((ligneMax*10+80)/15), "[ESC] : Quitter", 2);
   	ChoisirCouleurDessin(CouleurParComposante(100, 100, 100));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Appuyez sur [ESPACE] pour jouer", 2)/2, (ligneMax*10+80)/1.05, "Appuyez sur [ESPACE] pour jouer", 2);

}

void chargement(int mode)
{
	/* Afficher chargement */
	InitialiserGraphique();
    CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80);
    EffacerEcran(CouleurParComposante(0, 0, 0));
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));

    if (mode == 1){
    	solo();
    	while (True){
	 		if(Touche() == XK_space){
	 			FermerGraphique();
                jeu();
	 			printf("espace\n");
	 			
	   		}
 		}
    }
    if (mode == 2){
    	multi();
    	while (True){
	 		if(Touche() == XK_space){
	 			FermerGraphique();
                jeuM();
	 			printf("espace\n");
	 			
	   		}
 		}
    }

    
	FermerGraphique();
}

/*gcc menu.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph*/