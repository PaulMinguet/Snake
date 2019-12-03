#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#define ligneMax 40
#define colonneMax 60

int main()
{
	int x, y;
	InitialiserGraphique();
    CreerFenetre(10,10,colonneMax*10+20,ligneMax*10+80);
    EffacerEcran(CouleurParComposante(0, 0, 0));
    ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
    RemplirRectangle(0,0,colonneMax*10+20,ligneMax*10+80);
    ChoisirCouleurDessin(CouleurParComposante(218, 165, 32));
    EcrireTexte((colonneMax*10+20)/2-TailleChaineEcran("Snake", 2)/2, (ligneMax*10+80)/10, "Snake", 2);		//TailleChaineEcran("Snake", 2)/2 : prend la moitié de la taille en pixel de "Snake"

    SourisPosition();
    x = _X;
    y = _Y;
    while(!SourisCliquee()){
    	SourisPosition();
    	if (_X!=x || _Y!=y){
    		EcrireTexteC((colonneMax*10+20)/2-TailleChaineEcran("Snake", 2)/2, (ligneMax*10+80)/2, "Clic !", 2);
    	}
    }

    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}

//gcc test_graph.c -I/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/include -L/home/paul/IUT/PT/bibliotheque-graphique-iut-1.1/src/lib -lgraph
