#include "enigme.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
//-----------------------------------------INIT------------------------------------
//INIT Background
void initialiser_back_enigme_fichier(enigme *B)
{

(*B).img_back=IMG_Load("RES/back enigme ficher.jpg");
  if((*B).img_back==NULL)
{printf("loading error ! %s\n", SDL_GetError());
 return;}

(*B).pos_back.x=0;
(*B).pos_back.y=0;
(*B).pos_back.w=0;
(*B).pos_back.h=0;
}
//------------------------TEXT------------------------------
void initText(enigme *t)
{
t->textColor.r=255;
t->textColor.g=255;
t->textColor.b=255;
t->font=TTF_OpenFont("RES/Chalkboy.ttf",65);
}
//--------------------------TEMPS----------------------------------
void initialiser_temps_enigme(temps_e *t)
{
 //t->texte = NULL;
 t->position.x=700;
 t->position.y=10;
 t->police = TTF_OpenFont("RES/Chalkboy.ttf",75);
 strcpy( t->entree,"");
(t->secondesEcoulees)=0;
time(&(t->t1));	 //temps du debut
}
//------------------------MUSIC------------------------------
void initmusic()
{
	Mix_Music *music;
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)

	{printf("NO AUDIO %s\n",Mix_GetError());}

 

music = Mix_LoadMUS("RES/menu son.mp3"); //load the music 

Mix_PlayMusic(music,-1); //play music 
}
//-----------------------VOLUME-----------------------------
 void initialiser_volume(volume *O)  		
{
(*O).img_soundminus= IMG_Load("RES/soundminus.png");
(*O).img_soundplus= IMG_Load("RES/soundplus.png");


(*O).pos_soundminus.x=1520;
(*O).pos_soundminus.y=150;
(*O).pos_soundminus.w=60;
(*O).pos_soundminus.h=60;

(*O).pos_soundplus.x=1520;
(*O).pos_soundplus.y=50;
(*O).pos_soundplus.w=60;
(*O).pos_soundplus.h=60;
}
//----------------------MUTE-----------------------------

void initialiser_mute(mute *O)  		
{
(*O).img_soundon= IMG_Load("RES/soundon.png");
(*O).img_soundoff= IMG_Load("RES/soundoff.png");
(*O).img_soundsupp= IMG_Load("RES/soundsupp.png");

(*O).pos_soundon.x=1420;
(*O).pos_soundon.y=100;
(*O).pos_soundon.w=60;
(*O).pos_soundon.h=60;
}
//----------------------INIT----------------------------
void initialisation(enigme *e,volume *O,mute *m,temps_e *t,SDL_Surface *anim[])
{
initialiser_back_enigme_fichier(e);
initText(e);
init_enig_fichier(e);	
initmusic();
initialiser_volume(O);
initialiser_mute(m);
initialiser_temps_enigme(t);
initanimation(anim);
//e->resolu=0;
}
//----------------------ENIGME----------------------------
void init_enig_fichier( enigme * en )
{

    en->solution = 0;
    en->correct =IMG_Load("RES/pass.png");
    en->wrong =IMG_Load("RES/fail.png");
    en->position_correct.x = 500;
    en->position_correct.y = 400;
    en->position_wrong.x = 500;
    en->position_wrong.y = 400;


    en->Rep1 = NULL;
    en->rep1_Pos.x=230;
    en->rep1_Pos.y=360;
    en->rep1_Pos.w=440;
    en->rep1_Pos.h=100;

    en->Rep2 = NULL;
    en->rep2_Pos.x=1020;
    en->rep2_Pos.y=360;
    en->rep2_Pos.w=440;
    en->rep2_Pos.h=100;

    en->Rep3 =NULL;
    en->rep3_Pos.x=230;
    en->rep3_Pos.y=630;
    en->rep3_Pos.w=440;
    en->rep3_Pos.h=100;

    en->Rep4 =NULL;
    en->rep4_Pos.x=1020;
    en->rep4_Pos.y=630;
    en->rep4_Pos.w=440;
    en->rep4_Pos.h=100;


    en->Question = NULL;
    en->question_Pos.x=300;
    en->question_Pos.y=100;

    en->alea = 0;
}
//---------------------------ANIMATION---------------------TIME OUT-------
void initanimation(SDL_Surface *anim[])
{ int i;
  char filename[43];
for(i=0;i<4;i++)
{
sprintf(filename,"RES/animation/%d.png",i); 
anim[i] = IMG_Load(filename);
}
}
//---------------------------AFFICHER ANIM-----------------------
void afficheanimation(SDL_Surface* screen,enigme *B,SDL_Surface *anim[4])
{	      
	int ianimation=0;
	for (ianimation=0;ianimation<4;ianimation++)
	{
	SDL_BlitSurface(anim[ianimation],NULL,screen,&B->pos_back);
	SDL_Flip(screen);
	SDL_Delay(600);
	}

}
//-----------------------------AFFICHER TEMPS----------------------
void afficher_temps_enigme(temps_e *t,SDL_Surface *screen,enigme *en)
{	
    	time(&(t->t2));// temps actuel
	t->secondesEcoulees = t->t2 - t->t1;
        t->min=0-((t->secondesEcoulees/60)%60);
	t->sec= 20-((t->secondesEcoulees)%60);
	sprintf(t->entree,"%02d %02d",t->min,t->sec);
        t->texte = TTF_RenderText_Blended(en->font,t->entree, en->textColor);
	SDL_BlitSurface(t->texte, NULL, screen, &(t->position)); /* Blit du texte */	
}
//-----------------------------AFFICHER ENIGME----------------------
void blit_enig_fichier ( enigme *en, SDL_Surface* screen,mute m,volume O)
{	      
	SDL_BlitSurface(en->img_back,NULL,screen,&en->pos_back);
	SDL_BlitSurface(en->Question,NULL,screen,&en->question_Pos);
	SDL_BlitSurface(en->Rep1,NULL,screen,&en->rep1_Pos);
        SDL_BlitSurface(en->Rep2,NULL,screen,&en->rep2_Pos);
        SDL_BlitSurface(en->Rep3,NULL,screen,&en->rep3_Pos);
	SDL_BlitSurface(en->Rep4,NULL,screen,&en->rep4_Pos);
	SDL_BlitSurface(O.img_soundminus,NULL,screen,&O.pos_soundminus);
	SDL_BlitSurface(O.img_soundplus,NULL,screen,&O.pos_soundplus);
	SDL_BlitSurface(m.img_soundon,NULL,screen,&m.pos_soundon);
}
//------------------------------ALEA ENIGME------------------------
void alea_enig_fichier(enigme *en)
{
	FILE* fichier = NULL;
	FILE* fichier_reponse = NULL;
	char ques[60] ;
	char rep1[20] ;
	char rep2[20] ;
	char rep3[20] ;
	char rep4[20] ;
	int caracterelu_question,caracterelu_reponses,ligne =1,ligne_reponse=1;
	srand(time(0));

		en->alea = rand()%6 +1;
	

	fichier_reponse = fopen("RES/reponse.txt","r"); 
	fichier = fopen("RES/question.txt","r"); 
	if ( fichier != NULL && fichier_reponse != NULL )
	{
		while ( caracterelu_question!=EOF && ligne < en->alea )
		{
			caracterelu_question = fgetc(fichier);
			if ( caracterelu_question == '\n')
				ligne++;
		}
		fgets(ques,100,fichier);
		fclose(fichier);
		while ( caracterelu_reponses!=EOF && ligne_reponse < en->alea )
		{
			caracterelu_reponses = fgetc(fichier_reponse);
			if ( caracterelu_reponses == '\n')
				ligne_reponse++;
		}
		fscanf(fichier_reponse,"%s %s %s %s %d",rep1,rep2,rep3,rep4,&en->solution);
		fclose(fichier_reponse);
	}
	en->Question = TTF_RenderText_Blended(en->font,ques,en->textColor);
	en->Rep1 = TTF_RenderText_Blended(en->font,rep1,en->textColor);
	en->Rep2 = TTF_RenderText_Blended(en->font,rep2,en->textColor);
	en->Rep3 = TTF_RenderText_Blended(en->font,rep3,en->textColor);
	en->Rep4 = TTF_RenderText_Blended(en->font,rep4,en->textColor);
}
//-------------------------------RESOLUTION---------------------------
void resolution(enigme *en, SDL_Surface* screen,volume O,mute m,temps_e t,SDL_Surface *anim[])
{
SDL_Event event;
int continuer=1;
alea_enig_fichier(en);
int x,y,choix=0;
int volume=20,Vol;
		while(continuer == 1)	
			{
			blit_enig_fichier (en,screen,m,O);
			afficher_temps_enigme(&t,screen,en);
if ((t.min==0)&&(t.sec==0))
{	    afficheanimation(screen,en,anim);
		continuer=0;
}

		    	SDL_PollEvent(&event);
	switch(event.type)
		{
			case SDL_QUIT:
            			continuer=0;
           		 break;	

			case  SDL_MOUSEMOTION: 
        			 x=event.motion.x;
        			 y=event.motion.y;
			case SDL_MOUSEBUTTONDOWN:
//---------------------------VOLUME SOURIS-------------------------
			if  ( ( x > O.pos_soundminus.x ) && ( x < O.pos_soundminus.x + O.pos_soundminus.w ) && ( y > O.pos_soundminus.y ) && ( y < O.pos_soundminus.y + O.pos_soundminus.h )&&(event.button.button==SDL_BUTTON_LEFT) )
		{if(volume>0)
     		     {volume-=20;
       		    Mix_VolumeMusic(volume);}
			SDL_Delay(200) ;
}
  		   if ( ( x > O.pos_soundplus.x ) && ( x < O.pos_soundplus.x + O.pos_soundplus.w ) && ( y > O.pos_soundplus.y ) && ( y < O.pos_soundplus.y + O.pos_soundplus.h )&&(event.button.button==SDL_BUTTON_LEFT) )
   		 { if(volume<100)
     		     {volume+=20;
       		    Mix_VolumeMusic(volume);}
			SDL_Delay(200) ;}
		   if ( ( x > m.pos_soundon.x ) && ( x < m.pos_soundon.x + m.pos_soundon.w ) && ( y > m.pos_soundon.y ) && ( y < m.pos_soundon.y + m.pos_soundon.h )&&(event.button.button==SDL_BUTTON_LEFT) )
   		 {
		   if(volume>0)
     		     {Mix_VolumeMusic(0);
		      Vol=volume;
		      volume=0;}
		   else 
     		     {volume=Vol;
       		    Mix_VolumeMusic(volume);}
			SDL_Delay(200) ;}
//-----------------------------REPONSE SOURIS---------------------------
/*rep1*/		if (( x > en->rep1_Pos.x ) && ( x < en->rep1_Pos.x + en->rep1_Pos.w ) && ( y > en->rep1_Pos.y ) && ( y < en->rep1_Pos.y + en->rep1_Pos.h )&&(event.button.button==SDL_BUTTON_LEFT))
		{choix=1;}

/*rep2*/		if (( x > en->rep2_Pos.x ) && ( x < en->rep2_Pos.x + en->rep2_Pos.w ) && ( y > en->rep2_Pos.y ) && ( y < en->rep2_Pos.y + en->rep2_Pos.h )&&(event.button.button==SDL_BUTTON_LEFT)) 
                {choix=2;}
/*rep3*/		if (( x > en->rep3_Pos.x ) && ( x < en->rep3_Pos.x + en->rep3_Pos.w ) && ( y > en->rep3_Pos.y ) && ( y < en->rep3_Pos.y + en->rep3_Pos.h )&&(event.button.button==SDL_BUTTON_LEFT)) 
                {choix=3;}
/*rep4*/		if (( x > en->rep4_Pos.x ) && ( x < en->rep4_Pos.x + en->rep4_Pos.w ) && ( y > en->rep4_Pos.y ) && ( y < en->rep4_Pos.y + en->rep4_Pos.h )&&(event.button.button==SDL_BUTTON_LEFT))
                {choix=4;}
			break;	
//-----------------------------VOLUME CLAVIER---------------------------
		case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
              {
		case SDLK_DOWN: 
          	{if(volume>0)
     		     {volume-=20;
       		    Mix_VolumeMusic(volume);}
			SDL_Delay(200) ;}
           	break;
          	 case SDLK_UP: 
          	{ if(volume<100)
     		     {volume+=20;
       		    Mix_VolumeMusic(volume);}
			SDL_Delay(200) ;}
          	break;
	  	 case SDLK_m: 
          	{
		   if(volume>0)
     		     {Mix_VolumeMusic(0);
		      Vol=volume;
		      volume=0;}
		   else 
     		     {volume=Vol;
       		    Mix_VolumeMusic(volume);}
			SDL_Delay(200) ;}
        	  break;
//-----------------------------REPONSE CLAVIER---------------------------
		case SDLK_h: 
		{choix=1;}
           	break;
		case SDLK_e: 
          	{choix=2;}
           	break;
		case SDLK_l: 
          	{choix=3;}
           	break;
		case SDLK_a: 
          	{choix=4;}
           	break;
}}	
if (volume>0)
		{SDL_BlitSurface(m.img_soundsupp,NULL,screen,&m.pos_soundon);
		SDL_BlitSurface(m.img_soundon,NULL,screen,&m.pos_soundon);
		}
	else
		{SDL_BlitSurface(m.img_soundsupp,NULL,screen,&m.pos_soundon);
		SDL_BlitSurface(m.img_soundoff,NULL,screen,&m.pos_soundon);
		}
		
	SDL_Flip(screen);
if (choix!=0) 
{
if ( en->solution == choix )
        {
            SDL_BlitSurface(en->correct,NULL, screen, &en->position_correct );
            SDL_Flip(screen);
		//en->resolu=1;continuer=0;
            SDL_Delay(3000);

        }
        else 
        {
            SDL_BlitSurface(en->wrong,NULL, screen, &en->position_wrong );

            SDL_Flip(screen);
		//en->resolu=2;continuer=0;
            SDL_Delay(3000);

        }
}
}}
//-----------------------------------------------------
void freee( enigme *en)
{
    SDL_FreeSurface(en->img_back);
    SDL_FreeSurface(en->correct);
    SDL_FreeSurface(en->wrong);
    SDL_FreeSurface(en->Rep1);
    SDL_FreeSurface(en->Rep2);
    SDL_FreeSurface(en->Rep3);
    SDL_FreeSurface(en->Rep4);
    SDL_FreeSurface(en->Question);
    TTF_CloseFont(en->font);
}
//-----------------------------------------------------
void libereranimation(SDL_Surface *anim[])
{ int i;
  char filename[43];
	for(i=0;i<4;i++)
	{
		SDL_FreeSurface(anim[i]);
	}
}

