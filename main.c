    /**************************************************************************************/
    /**************************************************************************************/
    /****************************************MAIN.C****************************************/
    /***********************************PROJET SNAKE 2019**********************************/
    /********************************IUT UPEC FONTAINEBLEAU********************************/
    /********************************** MATTHIEU CARRICO***********************************/
    /*************************************PAUL MINGUET*************************************/
    /**************************************************************************************/
    /**************************************************************************************/

    #include <stdio.h>
    #include <stdlib.h>
    #include <graph.h>
    #include <time.h>
    #include "serpent.h"


    int coactux = (colonneMax/2),
    coactuy = (ligneMax/2);
    int score = 0;
	int nvscore = 0;
	unsigned int secondes = 0;
	unsigned int minutes = 0;
	unsigned long depart = 0;


    /*------------------------------------initSnake------------------------------------*/

    Serpent *initSnake(){
    	int t = 1;
    	Coordonnees tete;
    	Serpent *leSerpent = initialisation();
    	ChoisirCouleurDessin(CouleurParNom("black"));
    	system("/home/paul/IUT/PT11_APL2019/Paul/serpent.c");
    	tete = premier(leSerpent);
    	for(; t<=9; t++){
	    	insertionFin(leSerpent, tete.x, tete.y+t);
	    }
    	RemplirRectangle(tete.x*proporpix,tete.y*proporpix,proporpix,proporpix);				
    	return leSerpent;

    }
    
    /*------------------------------------checkMovSnake------------------------------------*/

    int checkMovSnake(int buttonP){
    /*cette fonction a pour usage d'associer a la variable buttonP
    la valeur de la derniere touche préssée*/
    	if(ToucheEnAttente()){
    		switch(Touche()){			
    			case XK_Left :
    			if (buttonP == XK_Right)
    			{
    				buttonP == XK_Right;break;
    			}else{
    				buttonP = XK_Left;break;
    			}
    			
    			case XK_Right :
    			if (buttonP == XK_Left)
    			{
    				buttonP == XK_Left;break;
    			}else{
    				buttonP = XK_Right;break;
    			}
    			
    			case XK_Up :
    			if (buttonP == XK_Down)
    			{
    				buttonP == XK_Up;break;
    			}else{
    				buttonP = XK_Up;break;
    			}


    			case XK_Down :
    			if (buttonP == XK_Up)
    			{
    				buttonP == XK_Up;break;
    			}else{
    				buttonP = XK_Down;break;
    			}
    		}
    		
    	}


    	return buttonP;
    }
    /*------------------------------------movSnake------------------------------------*/

    Coordonnees movSnake(int buttonP,Coordonnees coactu){
    	/*cette donction permet de changer la direction du serpent
    	soustrayant/additionant les valeurs d'une variable de type coordoonnees*/

    	if (buttonP == XK_Left)
    	{	
            /*printf("g\n");*/
    		coactu.x--;

    	}
    	if (buttonP == XK_Right)
    	{
            /*printf("d\n");*/
    		coactu.x++;
    	}
    	if (buttonP == XK_Up)
    	{
            /*printf("h\n");*/
    		coactu.y--;
    	}
    	if (buttonP == XK_Down)
    	{
            /*printf("b\n");*/
    		coactu.y++;		
    	}

    	return coactu;
    }


    /*------------------------------------initialise la Fenetre------------------------------------*/
    void initAffichage(){
    	ChoisirCouleurDessin(CouleurParNom("grey"));
    	RemplirRectangle(proporpix,proporpix,colonneMax*proporpix,ligneMax*proporpix);
    	ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
    	RemplirRectangle(20,20,colonneMax*proporpix-20,ligneMax*proporpix-20);
    }
    /*------------------------------------actualise l'affichage------------------------------------*/
    void actuAffichage(Coordonnees tete,Coordonnees queue){
    	/*actualise la position de la tete du snake*/
    	ChoisirCouleurDessin(CouleurParNom("black"));
    	RemplirRectangle(tete.x*proporpix,tete.y*proporpix,proporpix,proporpix);
    	/*efface la derniere valeur de la queue du snake*/
    	ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));
    	RemplirRectangle(queue.x*proporpix,queue.y*proporpix,proporpix,proporpix);



    }

    /*------------------------------------Collisions Mur----------------------------------*/
    void collisionsmurs(Coordonnees tete){
    	int fin = 0;
    	if(tete.x <= 1 || tete.x >= colonneMax || tete.y <= 1 || tete.y >= ligneMax){
    		/*fin = 1;*/
    		ChoisirCouleurDessin(CouleurParNom("black"));
    		EcrireTexte((colonneMax*proporpix+20)/2-TailleChaineEcran("Game Over", 2)/2, (ligneMax*proporpix+80)/2, "Game Over", 2);
    		EcrireTexte((colonneMax*proporpix+20)/2-TailleChaineEcran("Appuyez sur 'q' pour quitter", 1)/2, (ligneMax*proporpix+80)/2+20, "Appuyez sur 'q' pour quitter", 1);
    		while (1){
    			if(Touche() == XK_q){
    				/*printf("p\n");*/
    				FermerGraphique();
    				exit(1);

    			}else{}
    		}
    		
    	}
    }

    /*------------------------------------Timer----------------------------------*/
	void timer(){
		char tpssec[10];
		char tpsmin[10];
		if((Microsecondes()+CYCLE) - depart > 1000000L){
			depart = Microsecondes();
			ChoisirCouleurDessin(CouleurParNom("black"));
			RemplirRectangle(0, ligneMax*proporpix+10, (colonneMax*proporpix+20)/2, 80);
			ChoisirCouleurDessin(CouleurParNom("white"));
			sprintf(tpssec, " :%02d ", secondes);
			sprintf(tpsmin, "%02d", minutes);
			EcrireTexte(30,ligneMax*proporpix+10+45,tpssec, 2);
			EcrireTexte(17,ligneMax*proporpix+10+45,tpsmin, 2);
			secondes = secondes + 1;
			if(secondes == 60){
				secondes = 0;
				minutes++;
			}
			/*printf("%02d\n", secondes);*/
		}
	}

	/*------------------------------------Score----------------------------------*/
	void addscore(int nvscore){
		char nbscore[10];
		ChoisirCouleurDessin(CouleurParNom("black"));
		RemplirRectangle(colonneMax*8.5, ligneMax*proporpix+10, (colonneMax*proporpix+20)/2, 80);
		ChoisirCouleurDessin(CouleurParNom("white"));
		sprintf(nbscore, " %07d ", score);
		EcrireTexte(colonneMax*8.5,ligneMax*proporpix+10+45,nbscore, 2);
		score = score + nvscore;
		/*printf("%07d\n", score);*/
	}

    /*------------------------------------Pause----------------------------------*/
    int pause(int buttonP){
    	if (buttonP == XK_space){
            printf("espace");
    		for(;;){
                if (buttonP == XK_space){
                    break;
                }
            }
        }
    }

    
    /*------------------------------------MAIN------------------------------------*/
    int main()
    {
    	couleur fond;
    	Coordonnees tete, queue;
    	int pommes[ligneMax][colonneMax];
    	int buttonP = XK_Right;
    	long suivant= Microsecondes()+CYCLE;
    	int i,x,y;
    	srand(time(NULL));	
    	tete.x = 20;
    	tete.y = 26;

    	for (x = 0; x < ligneMax; ++x)
    	{
    		for (y = 0; y < colonneMax; ++y)
    		{
    			pommes[x][y] = 0;
    		}
    	}

    	InitialiserGraphique();
    	CreerFenetre(proporpix,proporpix,colonneMax*proporpix+20,ligneMax*proporpix+80); 		/*creation fenetre*/
    	EffacerEcran(CouleurParComposante(0, 0, 0));				                            /*coloration du fond en noir*/						
    	ChoisirCouleurDessin(CouleurParComposante(107, 142, 35));			          	        /*selection de la couleur*/
        RemplirRectangle(proporpix,proporpix,colonneMax*proporpix,ligneMax*proporpix);			/*RemplirRectangle(int x,int y,int l,int h);*/
    	Serpent *leSerpent = initSnake();
    	initAffichage();

    	for ( i = 0; i < QUANTITEPOMME; ++i)
    	{ 		
    		
    		for (;;)
    		{
    			x = rand()%(colonneMax-2)+1;
    			y = rand()%(ligneMax-2)+1;

                printf("x = %d y = %d\n",x ,y );
                printf("tab : %d\n",pommes[x][y]);

    			if (pommes[x][y] == 0 && x != 1 && y != 1)
    			{ 
    				ChoisirCouleurDessin(CouleurParComposante(255, 0, 0));
    				RemplirRectangle(x*proporpix,y*proporpix,proporpix,proporpix);
    				pommes[x][y] = 1;

                    printf("pommes : %d\n", i+1);
    				printf("%d %d\n",x ,y );
    				break;
    			}
    		}

    	}
    	for (;;)													                            /*début du jeu*/
    	{		
    			if (ToucheEnAttente())								                           /*verifie si il y a une touche dans le tampon*/
    		{
    				buttonP = checkMovSnake(buttonP);				                           /*attribue a buttonP la derniere touche préssé*/
    		}

    		if (Microsecondes()>suivant)
    		{	
    			timer();
				addscore(0);
    			tete = movSnake(buttonP,tete);
    			serpentCannibale(leSerpent,tete.x,tete.y);
    			queue = dernier(leSerpent);
    			deplacement(leSerpent,tete.x,tete.y);
    			collisionsmurs(tete);
                pause(buttonP);


    			if (pommes[tete.x][tete.y] == 1)
    			{
    				insertionFin(leSerpent, queue.x, queue.y);
    				pommes[tete.x][tete.y] = 0;
    				
    				for (;;)
    				{
    					x = rand()%(colonneMax-2)+1;
    					y = rand()%(ligneMax-2)+1;

    					if (pommes[x][y] == 0 && verifPommePasDansSerpent(leSerpent,x,y)&& x != 1 && y !=1)
    					{ 
                            printf("pommes : %d\n", i);
    						addscore(5);
    						ChoisirCouleurDessin(CouleurParComposante(255, 0, 0));
    						RemplirRectangle(x*proporpix,y*proporpix,proporpix,proporpix);
    						pommes[x][y] = 1;
    						printf("%d %d\n",x ,y );
    						break;
    					}


    				}
    			}

    	   			actuAffichage(tete,queue);
    				suivant= Microsecondes()+CYCLE;
    			}
    		}
    		Touche();
    		return EXIT_SUCCESS;
    	}
