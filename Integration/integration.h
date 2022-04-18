#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct {

SDL_Surface *image_vie[5]; 
SDL_Rect position_vie ;
int nbvie;
SDL_Rect position_texte;
}vie;
typedef struct {
char number[20]; 
SDL_Rect position_txt; //texte(score)
SDL_Rect position_number;  
int valscore ;
}score;

typedef struct 
{
SDL_Surface *spritesheet;
SDL_Rect position;
int direction;
SDL_Rect pos_sprite; 
double vitesse,acceleration;
int vitesseV;
vie vie_perso;
score score_perso;
}perso;

typedef struct
{
  SDL_Surface* image[3];//tableau des images dirigées vers la droite
  SDL_Surface* image2[3];//tableau des images dirigées vers la gauche
  SDL_Surface* Hit; //image qui parait lors de la collision bb 
  SDL_Surface* imageActuel;//image avec laquelle on commence l'animation
  SDL_Rect position; //position de l'ennemie sue l'ecran 
  int frame;//la position qui prend l'ennemi
  int direction;//gauche ou droite 0:droite 1:gauche
  int speed;//speed=0 donc pas de mouvement
}Ennemi;//entite1 le pirate 


typedef struct
{
  SDL_Surface* image1[3];//droite
  SDL_Surface* image3[3];//gauche
  SDL_Surface* Hit; 
  SDL_Surface* imageActuel;
  SDL_Rect position; 
  int frame;
  int direction;
  int speed;
}Ennemi1;//entite2

typedef struct { 
SDL_Surface *img_back;
 SDL_Rect pos_back;
Mix_Music* son_contenu;
}back;

void initialiser_back(back *B);
void affiche_back(back B, SDL_Surface* screen)	;
void initPerso(perso *p);
Ennemi initEnnemi( Ennemi e);	
Ennemi1 initEnnemi1( Ennemi1 e1);
void  afficherEnnemi ( Ennemi e, SDL_Surface* screen);
void  afficherEnnemi1 ( Ennemi1 e1, SDL_Surface* screen);
Ennemi animerEnnemi( Ennemi e, int l);//l c'est pour la collision en cas de collision on fait apparaitre l'image de hit
Ennemi1 animerEnnemi1( Ennemi1 e1, int f);//l c'est pour la collision en cas de collision on fait apparaitre l'image de hit
Ennemi deplacer( Ennemi e, int l);
Ennemi1 deplacer1( Ennemi1 e1, int f);					
int Collision_Bounding_Box( perso p, Ennemi e); //collision entre le pirate et l'hero
int Collision_Bounding_Box1( perso p, Ennemi1 e1);//collision entre le perroquet et l'hero
void initPerso(perso *p);
void afficherPerso(perso p, SDL_Surface * screen);
void deplacerPerso (perso *p,int dt);
void animerPerso (perso* p);
void saut (perso* p) ;
void liberer(perso p, SDL_Surface * screen);




 #endif
