/**************************************************************************************/
/**************************************************************************************/
/***************************************SERPENT.C**************************************/
/***********************************PROJET SNAKE 2019**********************************/
/********************************IUT UPEC FONTAINEBLEAU********************************/
/********************************** MATTHIEU CARRICO***********************************/
/*************************************PAUL MINGUET*************************************/
/**************************************************************************************/
/**************************************************************************************/




#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "serpent.h"





/*------------------------------------------> Initialisation <------------------------------------------*/

Serpent *initialisation(int codebx, int codeby){					/*on crée la structure de contrôle Serpent*/
	Serpent *serpent = malloc(sizeof(*serpent));					/*On alloue dynamiquement la structure de contrôle*/
	Corps *corps = malloc(sizeof(*corps));							/*On alloue dynamiquement le premier élément*/

	if (serpent == NULL || corps == NULL){							/*Si les allocations dynamiques n'ont pas fonctionné: exit*/
exit(EXIT_FAILURE);
}

	corps->cox = codebx;										    /*on défini les coordonnées cox et coy de base*/
corps->coy = codeby;
	corps->suivant = NULL;											/*on "termine" la liste chaînée qui mesure un élément*/
	serpent->premier = corps;										/*le premier élément est corps*/

return serpent;
}

/*---------------------------------> Insere un element en sebut de chaine<----------------------------------*/

void insertionDebut(Serpent *serpent, int nvCox, int nvCoy){		/*on crée la fonction d'insertion*/

	/*Création du nouvel élément*/

	Corps *nouveau = malloc(sizeof(*nouveau));						/*on alloue l'espace nécessaire dans la mémoire*/
if (serpent == NULL || nouveau == NULL){
	exit(EXIT_FAILURE);
}
	nouveau->cox = nvCox;											/*on donne les nouvelles coordonnées au nouvel élément*/
nouveau->coy = nvCoy;

	/* Insertion de l'élément au début la liste */

	nouveau->suivant = serpent->premier;							/*on fait pointer le nouvel élément vers son nouveau suivant (celui de tête)*/
	serpent->premier = nouveau;										/*on fait pointer serpent vers le nouvel élément*/
}

/*---------------------------------> Insérer un élément à la fin<-----------------------------------------*/

void insertionFin(Serpent *serpent, int nvCox, int nvCoy){			/*on crée la fonction d'insertion*/

	/*Création du nouvel élément*/

Corps *nouveau = malloc(sizeof(*nouveau));						/*on alloue l'espace nécessaire dans la mémoire*/

if (serpent == NULL || nouveau == NULL){
	exit(EXIT_FAILURE);
}
nouveau->cox = nvCox;											/*on donne les nouvelles coordonnées au nouvel élément*/
nouveau->coy = nvCoy;

	/* Insertion de l'élément */

	nouveau->suivant = NULL;										/*on fait pointer le nouvel élément vers son nouveau suivant le dernier*/
	Corps* p = serpent->premier;									/*on assigne l'adresse du corps au premier élément*/
while(p->suivant!=NULL){
	p = p->suivant;
}

	p->suivant=nouveau;												/*on fait pointer serpent vers le nouvel élément*/
}

/*--------------------------------------> Supprimer un élément <---------------------------------------------*/

void suppression(Serpent *serpent){
	if (serpent == NULL){											/*Si la liste est vide: exit*/
	exit(EXIT_FAILURE);
}

	if (serpent->premier != NULL){									/*Si non vide:*/
		Corps *aSupprimer = serpent->premier;						/*Assigner à aSupprimer l'adresse de Corps à supprimer*/
		serpent->premier = serpent->premier->suivant;				/*Faire pointer le premier élément vers le nouveau deuxième*/
		free(aSupprimer);											/*Supprimer le premier élément*/
}
}

/*-----------------------------------------> Afficher liste <-----------------------------------------*/

void afficherSerpent(Serpent *serpent){
	if (serpent == NULL){
		exit(EXIT_FAILURE);
	}
	Corps *actuel = serpent->premier;

	while (actuel != NULL){
		
		actuel = actuel->suivant;
	}
}
/*-------------------------------> verifie si le serpent ne ce rentre pas dedans <--------------------------------*/

void serpentCannibale(Serpent *serpent, int cosx, int cosy){
	if (serpent == NULL){
		exit(EXIT_FAILURE);
	}
	Corps *actuel = serpent->premier;						/*on avance vers le premier élement (la tete)*/
	actuel = actuel->suivant;								/*on avance encore une fois dans la liste puisque le serpent de peut pas s'auto dévorer la tete*/

	while (actuel != NULL){
		if (actuel->cox == cosx && actuel->coy == cosy)
		{

			ChoisirCouleurDessin(CouleurParNom("black"));
			EcrireTexte((colonneMax*proporpix+20)/2-TailleChaineEcran("Game Over", 2)/2, (ligneMax*proporpix+80)/2, "Game Over", 2);
			EcrireTexte((colonneMax*proporpix+20)/2-TailleChaineEcran("Appuyez sur 'q' pour quitter", 1)/2, (ligneMax*proporpix+80)/2+20, "Appuyez sur 'q' pour quitter", 1);
			while (1){
				if(Touche() == XK_q){

					FermerGraphique();
					exit(0);
					break;
				}
			}
		}
		actuel = actuel->suivant;
	}															
}
/*-----------------------------------------> verifie si la pomme n'apparait pas dans le serpent <--------------------------------*/
int verifPommePasDansSerpent(Serpent *serpent, int cosx, int cosy){
	int check = 1;
	if (serpent == NULL){
		exit(EXIT_FAILURE);
	}
	Corps *actuel = serpent->premier;
	actuel = actuel->suivant;

	while (actuel != NULL){
		if (actuel->cox == cosx && actuel->coy == cosy)
		{
			check=0;
		}
		actuel = actuel->suivant;
	}			
	return check;													
}


/*-----------------------------------------> chercher dernier élément de la liste <-----------------------------------------*/
Coordonnees dernier(Serpent *serpent){
	Coordonnees cofin;											/*Initialisation des coordonnées du dernier corps*/
	if (serpent == NULL){										/*Erreur si il n'y a pas de corps*/
	exit(EXIT_FAILURE);
}

	Corps *actuel = serpent->premier;							/*On initialise le pointeur de la liste chaînée*/

	while (actuel->suivant != NULL){							/*Tant que le corps suivant n'est pas NULL (fin de la liste chaînée)*/

		actuel = actuel->suivant;								/*On avance dans la liste*/
}
	cofin.x = actuel->cox;										/*On assigne les coordonnées du dernier corps*/
cofin.y = actuel->coy;

return cofin;
}

/*-----------------------------------------> chercher premier élément de la liste <-----------------------------------------*/

Coordonnees premier(Serpent *serpent){
Coordonnees codeb;											/*Initialisation des coordonnées du dernier corps*/

if (serpent == NULL){										/*Erreur si il n'y a pas de corps*/
	exit(EXIT_FAILURE);
}

Corps *actuel = serpent->premier;							/*On initialise le pointeur de la liste chaînée*/

codeb.x = actuel->cox;										/*On assigne les coordonnées du dernier corps*/
codeb.y = actuel->coy;

return codeb;
}

/*-----------------------------------------> deplacement <-----------------------------------------*/
/*cette fonction a pour but de deplacer le serpent*/
/*pour cela nous a chaque mouvement du serpent*/
/*nous envoyons a cette fonction les nouvelles coordonnées de la tete du serpent*/
/*cette fonction décale les anciennes coordonnées de la tete vers l'element suivant*/
/*et ainsi de suite jusqua atteindre la fin de la liste */

void deplacement(Serpent *serpent, int nouvCox, int nouvCoy){	/*inverser coordonnées*/
int tamponx, tampony, tamponsx, tamponsy;
Corps *actuel = serpent->premier;
Corps *suivant = suivant;
tamponx = actuel->cox;											/*tamponx --> tampon actuel*/
tampony = actuel->coy;
actuel->cox = nouvCox;
actuel->coy = nouvCoy;
for(;actuel->suivant != NULL;){
	if(actuel->suivant == NULL){break;}
	actuel = actuel->suivant;
		tamponsx = actuel->cox;									/*tamponsx --> tampon suivant*/
	tamponsy = actuel->coy;
	actuel->cox = tamponx;
	actuel->coy = tampony;
	if(actuel->suivant == NULL){break;}
	actuel = actuel->suivant;
	tamponx = actuel->cox;
	tampony = actuel->coy;
	actuel->cox = tamponsx;
	actuel->coy = tamponsy;

}
}