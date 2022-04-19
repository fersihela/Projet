#include "minimap.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int collision ,distance =10 , sens=0;
    SDL_Event event;
	minimap m;
    Personne p , pM , pMprochaine;
	temps t;
	SDL_Surface *screen = NULL,*imageDeFond=NULL , *masked=NULL;
	SDL_Rect position_BG ;
   int longueurM=6268 , largeurM=800 , longueur =1254 , largeur=160;
	screen = SDL_SetVideoMode(1600, 800 , 32, SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
	TTF_Init();
    if(screen==NULL)
    	{
        	printf("ERREUR: %s\n", SDL_GetError());
        	return 1;
       }


position_BG.x=0;
position_BG.y=0;

	imageDeFond = IMG_Load("RES/map1.png");
       int continuer= 1;
       initmap( &m);
       initialiser_temps(&t);

       masked=IMG_Load("RES/map1_masked.png");

    p.sprite=IMG_Load("RES/1r1.png");
    p.position_perso.x=95;
    p.position_perso.y=87;



    pM.sprite=IMG_Load("RES/1r1_3.png");
    pM.position_perso.x=0;
    pM.position_perso.y=350;


    pMprochaine.position_perso.h=357;
    pMprochaine.position_perso.w=137;
    pMprochaine.position_perso.x=pM.position_perso.x;
    pMprochaine.position_perso.y=pM.position_perso.y;
    SDL_EnableKeyRepeat(50,50);
	while (continuer)
{
	sens=0;

    SDL_BlitSurface(imageDeFond, NULL, screen, &position_BG);
	afficherminimap ( m,screen);
    SDL_BlitSurface(p.sprite, NULL, screen, &p.position_perso);
    SDL_BlitSurface(pM.sprite, NULL, screen, &pM.position_perso);
	afficher_temps(&t,screen);
    

	while(SDL_PollEvent(&event))
	{

     switch(event.type)
    {
            case SDL_QUIT:
                continuer = 0;
        break ;
        case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                	case SDLK_ESCAPE:
                            continuer = 0;
             		break;
                	case SDLK_RIGHT :
                    sens=30;
                	break;

                	case SDLK_LEFT :
                    sens=-1;
                    break;
                }
            }
            	
            }
            mouvement(&p ,&pM ,&pMprochaine,distance,longueur,longueurM , masked ,  sens );
            SDL_Flip(screen);

}
free_minimap (&m);
SDL_FreeSurface(p.sprite);
free_temps(&t,screen);
SDL_FreeSurface(screen);
TTF_Quit();
SDL_Quit();
	return EXIT_SUCCESS;
}
