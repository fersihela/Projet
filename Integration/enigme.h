#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>

typedef struct 
{
    char question[100];
    char rep1[100],rep2[100],rep3[100],rep4[100];
    int solution,alea;
    SDL_Surface *Question,*Rep1,*Rep2,*Rep3,*Rep4;
    SDL_Surface *correct,*wrong;
    SDL_Rect question_Pos,rep1_Pos,rep2_Pos,rep3_Pos,rep4_Pos,position_correct, position_wrong;
    SDL_Surface *img_back;
    SDL_Rect pos_back;
    Mix_Music* Music;
    TTF_Font *font;
     SDL_Color textColor;

}enigme;

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
//Volume
typedef struct{

SDL_Surface *img_soundminus;
SDL_Surface *img_soundplus;
SDL_Rect pos_soundminus,pos_soundplus;
}volume;

typedef struct{

SDL_Surface *img_soundon;
SDL_Surface *img_soundoff;
SDL_Surface *img_soundsupp;
SDL_Rect pos_soundon;
}mute;
//------------------------------------------------------
void initialisation(enigme *e,volume *O,mute *m,temps *t,SDL_Surface *anim[]);
void afficher_temps_enigme(temps *t,SDL_Surface *screen,enigme *en);
void initialiser_temps_enigme(temps *t);
void alea_enig_fichier(enigme *en );
void blit_enig_fichier ( enigme *en, SDL_Surface* screen,mute m,volume O);
void init_enig_fichier( enigme * en);
void initialiser_volume(volume *O);
void initialiser_mute(mute *O);
void initanimation(SDL_Surface *anim[]);
void freee( enigme *en);
void resolution(enigme *en, SDL_Surface* screen,volume O,mute m,temps t,SDL_Surface* anim[]);
void afficheanimation(SDL_Surface* screen,enigme *B,SDL_Surface *anim[]);
void libereranimation(SDL_Surface *anim[]);
#endif
