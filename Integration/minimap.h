#ifndef minimap_H_INCLUDED
#define minimap_H_INCLUDED	
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct 
{
	SDL_Rect position_perso;
 	SDL_Surface *sprite;
}Personne;



typedef struct 
{
	SDL_Rect position_mini;
	SDL_Surface *sprite;
}minimap;



typedef struct 
{
SDL_Surface *texte;
 SDL_Rect position;
  
    TTF_Font *police ;

 char entree[100];
 int secondesEcoulees;
SDL_Color couleurBlanche;
time_t t1,t2;
int min, sec;
}temps;


typedef struct  
{ 
   SDL_Surface *fondScore;
   SDL_Surface *texteScore;
   SDL_Rect posFond;
   SDL_Rect posScore;
   int scoreActuel;
   TTF_Font *police;
   
}Score;



void initmap( minimap *m);
void afficherminimap (minimap m, SDL_Surface * screen);
void free_minimap (minimap *m);



void affichertemps (int * temps,SDL_Surface *screen);

void initialiser_temps(temps *t);
void afficher_temps(temps *t,SDL_Surface *screen);
void free_temps(temps *t,SDL_Surface *screen);
void update_1_(SDL_Rect *prochain , SDL_Rect *principal, SDL_Rect *Pminimap, int distance, int longueur,int longueurM);
void update_2_(SDL_Rect *prochain , SDL_Rect *principal, SDL_Rect *Pminimap, int distance, int longueur,int longueurM);
void mouvement(Personne *p ,Personne *pM ,Personne *pMprochaine, int distance, int longueur,int longueurM , SDL_Surface *masked , int sens);
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP( Personne p, SDL_Surface * Masque);

#endif
