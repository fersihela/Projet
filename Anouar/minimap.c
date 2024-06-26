#include "minimap.h"
#include <stdlib.h>
#include <stdio.h>



void initmap( minimap *m)
{
	m->position_mini.x=100;
	m->position_mini.y=0;
	m->sprite=NULL;
    m->sprite=IMG_Load("minimap1.png");
}

void afficherminimap (minimap m, SDL_Surface * screen)
{
	
    SDL_BlitSurface(m.sprite, NULL, screen, &m.position_mini);
   
}
void free_minimap (minimap *m)
{
    SDL_FreeSurface(m->sprite);
}

void initialiser_temps(temps *t)
{
 t->texte = NULL;
 t->position.x=1400;
   t->position.y=30;
     t->police = NULL;
  t->police = TTF_OpenFont("avocado.ttf", 40);
    strcpy( t->entree,"");
(t->secondesEcoulees)=0;
time(&(t->t1));	 //temps du debut
}


void afficher_temps(temps *t,SDL_Surface *screen)
{	
SDL_Color couleurnoir= {0, 0,0};

    	time(&(t->t2));// temps actuel

		t->secondesEcoulees = t->t2 - t->t1;

        t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);
	 sprintf(t->entree,"%02d:%02d",t->min,t->sec);
	 
        t->texte = TTF_RenderText_Blended(t->police,t->entree, couleurnoir);
        
      

SDL_BlitSurface(t->texte, NULL, screen, &(t->position)); /* Blit du texte */
	
}




void free_temps(temps *t,SDL_Surface *screen)
{
	SDL_FreeSurface(t->texte);
 	TTF_CloseFont(t->police);
}





SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{
        
        SDL_Color color;
        Uint32 col = 0;
        //Determine position

                char pixelPosition = (char)Background->pixels;
                //Offset by Y
                pixelPosition += (Background->pitch * y);
                //Offset by X
                pixelPosition += (Background->format->BytesPerPixel * x);
                //Copy pixel data
                memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
                //Convert to color
                SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

                return (color);
}


int collisionPP( Personne p, SDL_Surface * Masque)
{
    SDL_Color test ,couleurnoir= {0,0,0};

    SDL_Rect pos[8];
    pos[0].x=p.position_perso.x;
    pos[0].y=p.position_perso.y;
    pos[1].x=p.position_perso.x+p.position_perso.w/2;
    pos[1].y=p.position_perso.y;
    pos[2].x=p.position_perso.x+p.position_perso.w;
    pos[2].y=p.position_perso.y;
    pos[3].x=p.position_perso.x;
    pos[3].y=p.position_perso.y+p.position_perso.h/2;   
    pos[4].x=p.position_perso.x;
    pos[4].y=p.position_perso.y+p.position_perso.h;
    pos[5].x=p.position_perso.x+p.position_perso.w/2;
    pos[5].y=p.position_perso.y+p.position_perso.h;
    pos[6].x=p.position_perso.x+p.position_perso.w;
    pos[6].y=p.position_perso.y+p.position_perso.h;    
    pos[7].x=p.position_perso.x+p.position_perso.w;
    pos[7].y=p.position_perso.y+p.position_perso.h/2;


     int collision=0 , x ,y ;

     for(int i=0 ;i<8 && collision==0;i++)
     {
        x=pos[i].x;
        y=pos[i].y;
        test=GetPixel(Masque,x,y);
        if(test.r==0 && test.g==0 && test.b==0)
            collision=1;
     }
     return collision;

}

void update_1_(SDL_Rect *prochain , SDL_Rect *principal, SDL_Rect *Pminimap, int distance, int longueur,int longueurM)
{
    principal->x=prochain->x;
    Pminimap->x+=distance*longueur/longueurM;
}

void update_2_(SDL_Rect *prochain , SDL_Rect *principal, SDL_Rect *Pminimap, int distance, int longueur,int longueurM)
{
    principal->x=prochain->x;
    Pminimap->x-=distance*longueur/longueurM;
}

void mouvement(Personne *p ,Personne *pM ,Personne *pMprochaine, int distance, int longueur,int longueurM , SDL_Surface *masked , int sens)
{
    if(sens==1)
    {
                    pMprochaine->position_perso.x+=distance;
                    if(pMprochaine->position_perso.x >=longueurM)
                    {
                        pMprochaine->position_perso.x=longueurM;
                        pM->position_perso.x=longueurM;
                        p->position_perso.x=longueur+95;
                    }
                    else if(collisionPP( *pMprochaine, masked)==0)
                    {
                        pM->position_perso.x=pMprochaine->position_perso.x;
                        p->position_perso.x+=distance*longueur/longueurM;
                    }

                    else{
                        pMprochaine->position_perso.x=pM->position_perso.x;
                    }
    }
    else if(sens==-1)
    {
        pMprochaine->position_perso.x-=distance;
                    if(pMprochaine->position_perso.x <=0)
                    {
                       pMprochaine->position_perso.x=0; 
                       pM->position_perso.x=0;
                       p->position_perso.x=95;
                    }
                    else if(collisionPP( *pMprochaine, masked)==0 )
                    {
                        pM->position_perso.x=pMprochaine->position_perso.x;
                        p->position_perso.x-=distance*longueur/longueurM;
                    }
                    else{
                        pMprochaine->position_perso.x=pM->position_perso.x;
                    }

    }
}
/*void initialiserScore(  Score *score )
{
	char string[20];
	SDL_Color couleurNoire ={255,255,255};
	
	score->posScore.x=300 ;
	score->posScore.y=20;
	score->posFond.x=score->posScore.x-20;
	score->posFond.y=score->posScore.y-20;	

	score->fondScore = IMG_Load("bois.png");
	(score->police) = TTF_OpenFont("Colleged.ttf", 20);

	score->scoreActuel=0;
	sprintf(string, "score = %d ", score->scoreActuel);

	(score->texteScore)=TTF_RenderText_Blended(score->police ,string, couleurNoire);		
}


void afficherScore(SDL_Surface *ecran , Score *score, background bg,int collision )
{

		
            SDL_Color couleurNoire ={255,255,255};
	
	char string[20];
	
	score->scoreActuel=bg.position.x*0.1+50*collision;
	sprintf(string, "score = %d ", score->scoreActuel);
	
	score->texteScore =TTF_RenderText_Blended(score->police,string, couleurNoire);
	
	SDL_BlitSurface(score->fondScore, NULL, ecran, &score->posFond);
	SDL_BlitSurface(score->texteScore, NULL, ecran, &score->posScore);
}*/
