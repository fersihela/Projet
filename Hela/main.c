#include "enigme.h"

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

	
	enigme e;
	SDL_Event event;
	int x,y;
	volume O;
	mute m;
	Mix_Music* music;
	temps t;
	SDL_Surface* anim[4];
	int *ianimation=0;

 //INIT
	TTF_Init();
	int done=0;
	SDL_Surface *screen;

	atexit(SDL_Quit);

	screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(!screen)
	{
		printf("Unable to set video %s\n",SDL_GetError());
		return 1;
	}
	initialisation(&e,&O,&m,&t,anim);

//GAME LOOP
	
	resolution(&e,screen,O,m,t,anim );



freee(&e);
libereranimation(anim);
TTF_Quit();
SDL_Quit();

return 0 ;
}
