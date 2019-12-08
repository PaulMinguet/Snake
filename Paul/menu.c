#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#define ligneMax 40
#define colonneMax 60

int main()
{

	/* Afficher menu */
	InitialiserGraphique();
    CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80);
    EffacerEcran(CouleurParComposante(0, 0, 0));
    ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
    RemplirRectangle(0,0,colonneMax*10+20,ligneMax*10+80);
    ChoisirCouleurDessin(CouleurParComposante(218, 165, 32));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Snake", 2)/2, (ligneMax*10+80)/10, "Snake", 2);		//TailleChaineEcran("Snake", 2)/2 : prend la moitié de la taille en pixel de "Snake"

/* Cliquer */
    char t[50];
    int x, y;
    couleur c;
	c=CouleurParNom("black"); 
	SourisPosition();
	x=_X;
	y=_Y;
	sprintf(t,"x=%3d:y=%3d",_X,_Y);
	EffacerEcran(CouleurParNom("white"));
	EcrireTexteC(((colonneMax*10+20)/2-TailleChaineEcran(t,0))/2,
			(ligneMax*10+80)/2,t,c,0);
 
	while(!SourisCliquee())
	{
		SourisPosition();
		if (_X!=x||_Y!=y)
		{
			sprintf(t,"x=%3d:y=%3d",_X,_Y);
			EffacerEcran(CouleurParNom("white"));
			EcrireTexteC(((colonneMax*10+20)/2-TailleChaineEcran(t,0))/2,
					(ligneMax*10+80)/2,t,c,0);
			x=_X;
			y=_Y;
		}
	}
    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}

//gcc menu.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph
