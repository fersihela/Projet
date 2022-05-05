#ifndef BACKGROUND_H_INCLUDE
#define BACKGROUND_H_INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1200
#define SCREEN_H 800

typedef struct
{
	SDL_Surface *imgback;
	SDL_Rect posback;
	SDL_Rect posback2;
	SDL_Rect camera;
	SDL_Rect camera2;
	Mix_Music *son;
	SDL_Surface *image_moon;  
	SDL_Rect pos_image_moon;
	SDL_Rect single_moon;	
	int moon_num;


}background;
void afficher_back(background b, SDL_Surface *ecran);
void initialisation_back(background *b);
void initBack (background *b);
void initBackMasque (background *b);
void initBack2 (background *b);
void afficheBack (background b,SDL_Surface *ecran);
void afficheBack2 (background b,SDL_Surface *ecran);
void scrolling (background *b,int direction);
void displaymoon(background b,SDL_Surface *ecran);
void animerBackground(background *b);
#endif  

