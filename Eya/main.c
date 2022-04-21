#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "collisionparfaite.h"
#include "background.h"

int main(void)
{	
	int continuer=1,input=0;
	SDL_Surface *screen=NULL,*screen2;
	background ba,bm;
	Personne perso;
	SDL_Event event;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	screen=SDL_SetVideoMode(1360,765,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}
		
	initialisation_back(&ba);//initback
	initBackMasque(&bm);//pour la collision parfaite
	

	initialiserperso(&perso);
	

	while (continuer)
	{	afficheBack(bm,screen);
		afficheBack2(ba,screen);
		afficher_perso(screen,perso);		
		deplacer_perso(&perso,event);
		//displaymoon(ba,ecran);
		//animerBackground(ba);
 		//collision(screen,&perso);
		
		SDL_PollEvent(&event);
		SDL_Flip(screen);
     	switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
			case SDLK_RIGHT:
			 	input = 1;
			 break;
                        case SDLK_LEFT:
                   		input = 2;
                   
                        break;
			 case SDLK_UP:
			 	input = 3;
		  				 
                        break;
 			 case SDLK_DOWN:
 			 	input = 4;
 		  				 
                        break;	
      		 }
      		 	
            break;
       

 	} 

if(input == 1)
{
				if( (collisionparfaite(screen,perso))==10 && (perso.pos_perso.x==(ba.camera2.x/2)))

				deplacer_perso(&perso,event);
				else 		
				{
				scrolling(&ba,1);
				scrolling(&bm,1);
				//collision(screen,&perso);
				}	
input =0;

}

if(input == 2)
{
				if( (collisionparfaite(screen,perso))==10 && (perso.pos_perso.x==(ba.camera2.x/2)))

				deplacer_perso(&perso,event);
				else 
				{
				scrolling(&ba,2);	
				scrolling(&bm,2);
				//collision(screen,&perso);
				}
input =0;
}

if(input == 3)
{
				if( (collisionparfaite(screen,perso))==10 && (perso.pos_perso.x==(ba.camera2.x/2)))

                                deplacer_perso(&perso,event);
	
				else			
				scrolling(&ba,3);		
				scrolling(&bm,3);
				//collision(screen,&perso);
input =0;
}

if(input == 4)
{
				if( (collisionparfaite(screen,perso))==10 && (perso.pos_perso.x==(ba.camera2.x/2)))

				deplacer_perso(&perso,event);
				else 
				scrolling(&ba,4);		
				scrolling(&bm,4);
				//collision(screen,&perso);
input =0;
			
			
}
}
	/*free_perso(perso);
	SDL_FreeSurface(screen);
	SDL_FreeSurface(ba);
	SDL_FreeSurface(bm);*/
	SDL_Quit();

	return 1;
}
