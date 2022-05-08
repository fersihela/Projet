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
/**
* @struct enigme
* @brief struct for enigme
*/
typedef struct 
{
    char question[100];
    char rep1[100],rep2[100],rep3[100],rep4[100];
    int solution,alea,resolu;
    SDL_Surface *Question,*Rep1,*Rep2,*Rep3,*Rep4; /*!< variable de question et reponse. */
    SDL_Surface *correct,*wrong; /*!< image correct et wrong. */
    SDL_Rect question_Pos,rep1_Pos,rep2_Pos,rep3_Pos,rep4_Pos,position_correct, position_wrong;/*!< Rectangle*/
    SDL_Surface *img_back; /*!< image back. */
    SDL_Rect pos_back;/*!< Rectangle back*/
    Mix_Music* Music;
    TTF_Font *font;
     SDL_Color textColor;

}enigme;
/**
* @struct temps
* @brief struct for temps
*/
typedef struct
{
SDL_Surface *texte; /*!< texte. */
SDL_Rect position; /*!< Rectangle texte*/ 
TTF_Font *police ;
char entree[100];
int secondesEcoulees;
SDL_Color couleurBlanche;
time_t t1,t2;
int min, sec;
}temps;
//Volume
/**
* @struct volume
* @brief struct for volume
*/
typedef struct{

SDL_Surface *img_soundminus; /*!< image sound minus. */
SDL_Surface *img_soundplus; /*!< image sound plus. */
SDL_Rect pos_soundminus,pos_soundplus;/*!< Rectangle sound minus et sound plus*/ 
}volume;
/**
* @struct mute
* @brief struct for mute
*/
typedef struct{

SDL_Surface *img_soundon; /*!< image sound on. */
SDL_Surface *img_soundoff; /*!< image sound off. */
SDL_Surface *img_soundsupp; /*!< image sound supp. */
SDL_Rect pos_soundon; /*!< Rectangle sound on*/ 
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

int arduinoWriteData(int x);
int arduinoReadData(int *x);
#endif
