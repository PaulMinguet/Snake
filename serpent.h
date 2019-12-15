#ifndef SERPENT_H
#define SERPENT_H
#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

#define ligneMax 60
#define colonneMax 80
#define CYCLE 50000L
#define proporpix 10
#define QUANTITEPOMME 5
 
typedef struct Corps Corps;		//création liste chaînée Corps
struct Corps{
	int cox, coy;				//coordonnées x et y de chaque partie de la liste
	Corps *suivant;				//renvoie vers l'élément suivant en mémoire
};

typedef struct Serpent Serpent;		//création de la structure de contrôle (la tête)
struct Serpent{
	Corps *premier;				//pointe vers le premier élément
};

typedef struct Coordonnees Coordonnees;
struct Coordonnees{
	int x, y;
};

typedef struct Tampon Tampon;
struct Tampon{
	int tcox, tcoy;
};
Serpent *initialisation();
void insertionDebut(Serpent *serpent, int nvCox, int nvCoy);
void insertionFin(Serpent *serpent, int nvCox, int nvCoy);
void suppression(Serpent *serpent);
void afficherSerpent(Serpent *serpent);
Coordonnees dernier(Serpent *serpent);
Coordonnees premier(Serpent *serpent);
void deplacement(Serpent *serpent, int nouvCox, int nouvCoy);
void serpentCannibale(Serpent *serpent, int cosx, int cosy);
#endif /* SERPENT_H */