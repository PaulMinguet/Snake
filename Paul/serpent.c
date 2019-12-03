#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
 
typedef struct Corps Corps;		//création liste chaînée Corps
struct Corps{
	int cox, coy;				//coordonnées x et y de chaque partie de la liste
	Corps *suivant;				//renvoie vers l'élément suivant en mémoire
};

typedef struct Serpent Serpent;		//création de la structure de contrôle (la tête)
struct Serpent{
	Corps *premier;				//pointe vers le premier élément
};

/*-----> Initialisation <-----*/
Serpent *initialisation(){			//on crée la structure de contrôle Serpent
	Serpent *serpent = malloc(sizeof(*serpent));	//On alloue dynamiquement la structure de contrôle
	Corps *corps = malloc(sizeof(*corps));	//On alloue dynamiquement le premier élément

	if (serpent == NULL || corps == NULL){	//Si les allocations dynamiques n'ont pas fonctionné: exit
		exit(EXIT_FAILURE);
	}

	corps->cox = 20;			//on défini les coordonnées cox et coy de base
	corps->coy = 30;
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
}

int main(){
	Serpent *leSerpent = initialisation();

	insertionFin(leSerpent, 20, 30+1);
	insertionFin(leSerpent, 20, 30+2);
	insertionFin(leSerpent, 20, 30+3);
	insertionFin(leSerpent, 20, 30+4);
	insertionFin(leSerpent, 20, 30+5);
	insertionFin(leSerpent, 20, 30+6);
	insertionFin(leSerpent, 20, 30+7);
	insertionFin(leSerpent, 20, 30+8);
	insertionFin(leSerpent, 20, 30+9);
	suppression(leSerpent);

	afficherSerpent(leSerpent);
	return EXIT_SUCCESS;
}

//gcc test_graph.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph
