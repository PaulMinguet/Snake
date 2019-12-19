#ifndef SERPENT_H
#define SERPENT_H
#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "serpent.h"
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
typedef struct Button Button;
struct Button{
	int P1, P2;
};

Serpent *initSnake();
Button checkMovSnake(Button buttonP);
Coordonnees movSnake(Button buttonP,Coordonnees coactu);
Coordonnees movSnakeP2(Button buttonP ,Coordonnees coactu);
void initAffichage();
void actuAffichageP1(Coordonnees tete,Coordonnees queue);
void actuAffichageP2(Coordonnees tete,Coordonnees queue);
void collisionsmurs(Coordonnees tete);
void timer();
void addscore(int nvscore);
int jeu();
int jeuM();

#endif /* SERPENT_H */