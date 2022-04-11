#include "enigme.h"
#include "minimap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

#define SCREEN_W 1620
#define SCREEN_H 880

int main()
{ 

	SDL_Event event;
//enigme texte
	enigme e;
	volume O;
	mute m;
	Mix_Music* music;
	temps t;
	SDL_Surface* anim[4];
	int *ianimation=0;
//__________________________



	int done=1;//game loop int

 //INIT
	TTF_Init();
	SDL_Surface *screen;

	atexit(SDL_Quit);

	screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(!screen)
	{
		printf("Unable to set video %s\n",SDL_GetError());
		return 1;
	}
	initialisation(&e,&O,&m,&t,anim);//initialisation enigme texte

//GAME LOOP
	while (done==1)
{
	//if(condition de colition perfect pixel)
	{
	resolution(&e,screen,O,m,t,anim );//enigme texte
	}

	done=0;//temporaire
}

//liberation enigme texte
freee(&e);
libereranimation(anim);
//_________________________
TTF_Quit();
SDL_Quit();

return 0 ;
}
