#include"collisionparfaite.h"

SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{	
	SDL_Color color;
	Uint32 col=0;

	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);

	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);

	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}
int  collisionparfaite(SDL_Surface *psurface,perso p)
{	
	int tabx[7],taby[7],i;
	SDL_Color color1,color;
	color1.r = 0;
	color1.g = 0;
	color1.b = 0;

	tabx[0]=p.position.x;
	taby[0]=p.position.y;

	tabx[1]=(p.position.x)+((p.position.w)/2);
 	taby[1]=p.position.y;

	tabx[2]=(p.position.x+p.position.w);
	taby[2]=p.position.y;

	tabx[3]=p.position.x;
	taby[3]=(p.position.y)+((p.position.h)/2);

	tabx[4]=p.position.x;
	taby[4]=(p.position.y+p.position.h);

	tabx[5]=(p.position.x)+((p.position.w)/2);
	taby[5]=(p.position.y+p.position.h);

	tabx[6]=(p.position.x+p.position.w);
	taby[6]=(p.position.y+p.position.h);

	tabx[7]=(p.position.x+p.position.w);
	taby[7]=(p.position.y)+((p.position.h)/2);
	
	
	
	for(i=0;i<8;i++)
	{
	color=getpixel(psurface,tabx[i],taby[i]);
	if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
	{
		return i;

	}
	}
	return 10;
	
}	

void collision(SDL_Surface *psurface,perso *p)
{	int i;
	i=collisionparfaite(psurface,*p);

	switch (i)
	{
		case 0 :p->position.y+=1;
			break;
		case 1 :p->position.y+=1;
			 break;
		case 2 :p->position.y+=1;
			break;
		case 3 :p->position.x+=1;
			break;
		case 4 :p->position.y-=1;
			break;
		case 5 :p->position.y-=1; 
			break;
		case 6 :p->position.y-=1; 
			break;
		case 7 :p->position.x-=1;
			break;
		

	}
}
