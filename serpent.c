#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "serpent.h"
/*-----> Initialisation <-----*/
Serpent *initialisation(){			//on crée la structure de contrôle Serpent
	Serpent *serpent = malloc(sizeof(*serpent));	//On alloue dynamiquement la structure de contrôle
	Corps *corps = malloc(sizeof(*corps));	//On alloue dynamiquement le premier élément

	if (serpent == NULL || corps == NULL){	//Si les allocations dynamiques n'ont pas fonctionné: exit
		exit(EXIT_FAILURE);
	}

	corps->cox = 20;			//on défini les coordonnées cox et coy de base
	corps->coy = 26;
	corps->suivant = NULL;		//on "termine" la liste chaînée qui mesure un élément
	serpent->premier = corps;		//le premier élément est corps

	return serpent;
}

/*-----> Insérer un élément <-----*/
void insertionDebut(Serpent *serpent, int nvCox, int nvCoy){		//on crée la fonction d'insertion
	/*Création du nouvel élément*/
	Corps *nouveau = malloc(sizeof(*nouveau));			//on alloue l'espace nécessaire dans la mémoire
	if (serpent == NULL || nouveau == NULL){
		exit(EXIT_FAILURE);
	}
	nouveau->cox = nvCox;				//on donne les nouvelles coordonnées au nouvel élément
	nouveau->coy = nvCoy;

	/* Insertion de l'élément au début la liste */
	nouveau->suivant = serpent->premier;	//on fait pointer le nouvel élément vers son nouveau suivant (celui de tête)
	serpent->premier = nouveau;			//on fait pointer serpent vers le nouvel élément
}

/*-----> Insérer un élément à la fin<-----*/
void insertionFin(Serpent *serpent, int nvCox, int nvCoy){		//on crée la fonction d'insertion
	/*Création du nouvel élément*/
	Corps *nouveau = malloc(sizeof(*nouveau));			//on alloue l'espace nécessaire dans la mémoire
	if (serpent == NULL || nouveau == NULL){
		exit(EXIT_FAILURE);
	}
	nouveau->cox = nvCox;				//on donne les nouvelles coordonnées au nouvel élément
	nouveau->coy = nvCoy;

	/* Insertion de l'élément */
	nouveau->suivant = NULL;	//on fait pointer le nouvel élément vers son nouveau suivant le dernier
	Corps* p = serpent->premier;	//on assigne l'adresse du corps au premier élément
	while(p->suivant!=NULL){
		p = p->suivant;
	}

	p->suivant=nouveau;			//on fait pointer serpent vers le nouvel élément
}

/*-----> Supprimer un élément <-----*/
void suppression(Serpent *serpent){
	if (serpent == NULL){					//Si la liste est vide: exit
		exit(EXIT_FAILURE);
	}

	if (serpent->premier != NULL){			//Si non vide:
		Corps *aSupprimer = serpent->premier;			//Assigner à aSupprimer l'adresse de Corps à supprimer
		serpent->premier = serpent->premier->suivant;	//Faire pointer le premier élément vers le nouveau deuxième
		free(aSupprimer);					//Supprimer le premier élément
	}
}

/*-----> Afficher liste <-----*/
void afficherSerpent(Serpent *serpent){
	if (serpent == NULL){
		exit(EXIT_FAILURE);
	}

	Corps *actuel = serpent->premier;

	while (actuel != NULL){
		printf("%d,%d -> ", actuel->cox, actuel->coy);
		actuel = actuel->suivant;
	}
	printf("NULL\n");
	//printf("%d, %d", xfin, yfin);
}

/*-----> chercher dernier élément de la liste <-----*/
Coordonnees dernier(Serpent *serpent){
	Coordonnees cofin;					//Initialisation des coordonnées du dernier corps
	if (serpent == NULL){			//Erreur si il n'y a pas de corps
		exit(EXIT_FAILURE);
	}

	Corps *actuel = serpent->premier;		//On initialise le pointeur de la liste chaînée

	while (actuel->suivant != NULL){		//Tant que le corps suivant n'est pas NULL (fin de la liste chaînée)
		//printf("%d,%d -> ", actuel->cox, actuel->coy); -- test popur afficher
		actuel = actuel->suivant;			//On avance dans la liste
	}
	cofin.x = actuel->cox;				//On assigne les coordonnées du dernier corps
	cofin.y = actuel->coy;

	return cofin;
}

/*-----> chercher premier élément de la liste <-----*/
Coordonnees premier(Serpent *serpent){
	Coordonnees codeb;					//Initialisation des coordonnées du dernier corps
	if (serpent == NULL){			//Erreur si il n'y a pas de corps
		exit(EXIT_FAILURE);
	}

	Corps *actuel = serpent->premier;		//On initialise le pointeur de la liste chaînée

	codeb.x = actuel->cox;					//On assigne les coordonnées du dernier corps
	codeb.y = actuel->coy;

	return codeb;
}

void deplacement(Serpent *serpent, int nouvCox, int nouvCoy){				//inverser coordonnées
	int tamponx, tampony, tamponsx, tamponsy;
	Corps *actuel = serpent->premier;
	Corps *suivant = suivant;
	tamponx = actuel->cox;		//tamponx --> tampon actuel
	tampony = actuel->coy;
	actuel->cox = nouvCox;
	actuel->coy = nouvCoy;
	for(;actuel->suivant != NULL;){
		if(actuel->suivant == NULL){break;}
		actuel = actuel->suivant;
		tamponsx = actuel->cox;	//tamponsx --> tampon suivant
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
/*
int main(){
	Coordonnees tete;
	Coordonnees queue;
	Serpent *leSerpent = initialisation();
	
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
	queue = dernier(leSerpent);
	printf("queue Avant : %d %d\n", queue.x, queue.y);
	deplacement(leSerpent, 20, 361);
	queue = dernier(leSerpent);

	printf("tete : %d %d\n",tete.x, tete.y);
	printf("queue : %d %d\n", queue.x, queue.y);
	afficherSerpent(leSerpent);
	return EXIT_SUCCESS;
}
*/
//gcc serpent.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph