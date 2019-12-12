#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#define ligneMax 40
#define colonneMax 60

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
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Snake", 2)/2, (ligneMax*10+80)/10, "Snake", 2);		//TailleChaineEcran("Snake", 2)/2 : prend la moitié de la taille en pixel de "Snake"
    ChoisirCouleurDessin(CouleurParComposante(218, 165, 32));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Jouer", 2)/2, (ligneMax*10+80)/5, "Jouer", 2);

 	while (1 != 0){
 	while(!SourisCliquee()) {}
	 	SourisPosition();
	 	if(_X >= (colonneMax*10+20)/2-TailleChaineEcran("Jouer", 2)/2 && _X <= (colonneMax*10+20)/2+TailleChaineEcran("Jouer", 2)/2 && _Y >= (ligneMax*10+80)/5-20 && _Y <= (ligneMax*10+80)/5){
	 		EffacerEcran(CouleurParNom("white"));
	 		FermerGraphique();
	 		system("/home/paul/IUT/PT11_APL2019/Matthieu/a.out");
	 	}
	}
	FermerGraphique();
	return EXIT_SUCCESS;
}

//gcc menu.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph
