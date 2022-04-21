#include "background.h"



void initBackMasque (background *b)
{
//background
b->imgback=IMG_Load("mapMasque.png");
b->posback.x=0;
b->posback.y=0;

//camera
b->camera.x=0;
b->camera.y=0;
b->camera.w=SCREEN_W; 
b->camera.h=SCREEN_H;

}

void initBack2 (background *b)
{
//background2
b->imgback=IMG_Load("map.png");
b->posback2.x=0;
b->posback2.y=0;
//camera2
b->camera2.x=0;
b->camera2.y=0;
b->camera2.w=SCREEN_W; 
b->camera2.h=SCREEN_H;
//musique
b->son=Mix_LoadMUS("musique.mp3"); //Chargement de la musique
	b->image_moon=IMG_Load("moon.png");  
	b->pos_image_moon.x=500;
	b->pos_image_moon.y=100;
	
	b->single_moon.w=56;
	b->single_moon.h=107;
	b->single_moon.x=0;
	b->single_moon.y=0;

	b->moon_num=0;
}


void initialisation_back(background *b)
{
	
	initBack2(b);
}



void afficheBack (background b, SDL_Surface *ecran)
{

Mix_PlayMusic(b.son, -1);
SDL_BlitSurface(b.imgback,&b.camera,ecran,&b.posback);
}

void afficheBack2 (background b, SDL_Surface *ecran)
{

Mix_PlayMusic(b.son, -1); 
SDL_BlitSurface(b.imgback,&b.camera2,ecran,&b.posback2);
}


void scrolling (background *b,int direction)
{
 const int speed=15;
if (direction ==1){ 
	b->camera.x+= speed;          

	b->camera2.x+= speed;
	
        }
else if (direction ==2){          
	b->camera.x-=speed; 

	b->camera2.x-=speed; 
	}

else if (direction ==3){  
        b->camera.y-= speed;

         b->camera2.y-= speed;
	}
else if (direction ==4){         
        b->camera.y+= speed;

	 b->camera2.y+= speed;
	 }

}
void displaymoon(background b,SDL_Surface *ecran)
{
			
 		SDL_BlitSurface(b.image_moon,&(b.single_moon), ecran, &b.pos_image_moon);
}
void animerBackground(background *b){
		 	
	if (b->moon_num >=0 && b->moon_num <8) {
	b->single_moon.x=b->moon_num * b->single_moon.w;
	b->moon_num++;
	}
	
	if ( b->moon_num == 8) {
	b->single_moon.x=b->moon_num * b->single_moon.w;
	b->moon_num=0;
	}
 
	 
}

/*void scrolling_right(background *b)
{b->camera2.x+=10;
if(b->camera2.x==1000)
	{b->camera2.x=1000;}
}

void scrolling_left(background *b)
{b->camera2.x-=10;
if(b->camera2.x==0)
	{b->camera2.x=0;}
}*/


