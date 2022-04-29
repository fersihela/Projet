#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "integration.h"
#include "enigme.h"
#include "minimap.h"
#include "background.h"
#include "collisionparfaite.h"





int main()
{
 TTF_Init();
//declaration
SDL_Surface *screen=NULL;


//enigme texte
	enigme enigme;
	volume volume_enig;
	mute mute_enig;
	temps time_enig;
	SDL_Surface* anim_enig[4];
	int *ianimation=0;
//__________________________


back b;
Ennemi e;
Ennemi1 e1; 
perso p;
minimap m;
int l,f;
int done=1,droite=0,gauche=0,up=0,dir=2;
Uint32 t_prev,dt;
temps t;
int continuer=1,input=0;
background ba,bm;
Personne pM; 
SDL_Event event;

//initialisation
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
screen=SDL_SetVideoMode(1200,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL)
    	{
        	printf("ERREUR: %s\n", SDL_GetError());
        	return 1;
       }

initPerso(&p);
initialiser_back(&b);
initmap( &m);
initialiser_temps(&t);
initialisation_back(&ba);
initBackMasque(&bm);




//Son continu
	Mix_Music* music; 
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
  printf("NO AUDIO %s\n",Mix_GetError());
}
music = Mix_LoadMUS("most-epic-battle-music-warriors-to-the-end-mix-by-epic-score.mp3"); //load the music 

Mix_PlayMusic(music,-1);




// affiche_back(back B, SDL_Surface* screen)	;
e=initEnnemi(e);
e1=initEnnemi1(e1); 
initialisation(&enigme,&volume_enig,&mute_enig,&time_enig,anim_enig);//initialisation enigme texte
 
while (done)
{
/*if(condition de colition perfect pixel)
	{
	resolution(&enigme,screen,volume_enig,mute_enig,time_enig,anim_enig );//enigme texte
	}*/
//affichage
affiche_back(b,screen)	;
afficherPerso(p,screen);
afficherEnnemi(e,screen);//affichage de l'ennemi pirate
afficherEnnemi1(e1,screen);//affichage de l'ennemi perroquet
afficher_temps(&t,screen);
afficherminimap ( m,screen);
SDL_BlitSurface(pM.sprite, NULL, screen, &pM.position_perso);//afficher perso dans minimap
 e = animerEnnemi (e, l);//animation de l'ennemi pirate
        e1 = animerEnnemi1 (e1, f);//animation de l'ennemi perroquet
        l = Collision_Bounding_Box (p, e);//retourner la valeur 1 en cas de collision du pirate avec perso
        f = Collision_Bounding_Box1 (p, e1);//retourner la valeur 1 en cas de collision du perroquet avec perso
	e = deplacer (e, l);//deplacer le pirate
        e1 = deplacer1 (e1, f);  //deplacer le perroquet


 SDL_Flip(screen);//mise à jour
SDL_Delay(100); //attente
t_prev = SDL_GetTicks();
     
//input
while(SDL_PollEvent(&event))
{
 
switch (event.type)
{
case SDL_QUIT:
   done=0;
    break;

case SDL_KEYDOWN:
    switch (event.key.keysym.sym)
    {
    case  SDLK_RIGHT:
         droite=1;
         input = 1;
        break;
    case  SDLK_LEFT:
       gauche=1;
        input = 2;
        break; 
    case SDLK_UP:
        up=1;
       input = 3;
        break;  
case SDLK_DOWN:
        
       input =4;
        break;    
 
    }
break;

case SDL_KEYUP:
switch (event.key.keysym.sym)
    {
    case  SDLK_RIGHT:
             droite=0;   //p1 stable avec direction droite
              dir=2;
             p.vitesse=0;
           
        break;

    case  SDLK_LEFT:        
       gauche=0;    //p1 stable avec  direction gauche
       p.vitesse=0;
        dir=3;
        
        break; 

    case SDLK_UP:
        up=0;
      
        break;   
   
    }

break;
}  
}
   		                     
// update


if (droite==1)      
{ 
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=0;
    droite =0;
}
if (gauche==1)    
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=1;
}

if ((Collision_Bounding_Box(p,e)==0)&&(Collision_Bounding_Box1( p,e1)==0))
 {    deplacerPerso(&p,dt);
     animerPerso(&p);
}
if ((Collision_Bounding_Box(p,e)==1)&&(Collision_Bounding_Box1( p,e1)==1))//il y a collision 
{
if (p.vie_perso.nbvie>0)
{p.vie_perso.nbvie--;
p.score_perso.valscore--;
}
}
else if ((p.vie_perso.nbvie==0)||(p.score_perso.valscore<0))
{
done=0;
}

if (up==1) 
saut(&p);

p.acceleration -=0.3;//deceleration p1

if (p.acceleration<0 ) 
p.acceleration=0; //   controler l'intervalle de l'acceleration p1
if (p.acceleration>4) 
p.acceleration=4;

SDL_Delay(1);
dt = SDL_GetTicks() - t_prev;   //le temps ecoulé depuis initialisation du boucle du jeu

if ((p.vitesse==0)&&(p.acceleration==0))   
{
    p.direction=dir;    
}
p.position.y += p.vitesseV;  
p.vitesseV += 10; 
if (p.position.y >=270)
{
    p.vitesseV=0;
    p.position.y=270; 
}

if(input == 1)
{
				if( (collisionparfaite(screen,p)==0) && (p.position.x==(ba.camera2.x/2)))

				 {deplacerPerso(&p,dt);
                                 animerPerso(&p);}
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
				if( (collisionparfaite(screen,p)==0) && (p.position.x==(ba.camera2.x/2)))

				 {deplacerPerso(&p,dt);
                                 animerPerso(&p);}
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
				if( (collisionparfaite(screen,p)==0) && (p.position.x==(ba.camera2.x/2)))

                               { deplacerPerso(&p,dt);
	                         animerPerso(&p);}
				else			
				{scrolling(&ba,3);		
				scrolling(&bm,3);}
				//collision(screen,&perso);
input =0;
}

if(input == 4)
{
				if( (collisionparfaite(screen,p)==0) && (p.position.x==(ba.camera2.x/2)))

				{ deplacerPerso(&p,dt);
                                  animerPerso(&p);}
				else 
				{scrolling(&ba,4);		
				scrolling(&bm,4);}
				//collision(screen,&perso);
input =0;
			
			
}
}

SDL_FreeSurface(p.spritesheet);
//liberation enigme texte
freee(&enigme);
libereranimation(anim_enig);
//_________________________
TTF_Quit();
free_minimap (&m);
free_temps(&t,screen);
SDL_FreeSurface(pM.sprite);
Mix_FreeMusic(music);
atexit(SDL_Quit);
SDL_Quit();
    return 0;
}
