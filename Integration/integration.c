#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "integration.h"
void initialiser_back(back *B)
 {
      (*B).img_back=IMG_Load("RES/back.png");
         if((*B).img_back==NULL)
           {
            printf("loading error ! %s\n", SDL_GetError());
          return;
           }
        (*B).pos_back.x=0;
        (*B).pos_back.y=0;
  }

void initPerso(perso *p)
  
{ p->spritesheet=IMG_Load("RES/perso2.png");
    
    p->position.x=50;    //position p1 (back du jeu)
    p->position.y=238;

    p->direction=2;//direction droite  (p est stable)

    p->acceleration=0;
    p->vitesse=0;
    p->vitesseV=0;

    
    p->pos_sprite.x= 0;     //position frame (sprite sheet)
    p->pos_sprite.y= 200;
    p->pos_sprite.h= 100;
    p->pos_sprite.w= 100;
// initialiser score
p->score_perso.police = TTF_OpenFont("RES/REP2CN__.ttf", 35); //chargement d'une police avec taille
SDL_Color blanco={255,255,255}; 
p->score_perso.position_txt.x=15;
p->score_perso.position_txt.y=20;
p->score_perso.texte1= TTF_RenderText_Blended(p->score_perso.police,"score :",blanco);  
p->score_perso.number[20];
p->score_perso.valscore=1450;
sprintf(p->score_perso.number, "%d",(p->score_perso.valscore));//conversion entier en une chaine de caractère
p->score_perso.number1= TTF_RenderText_Blended(p->score_perso.police,p->score_perso.number,blanco);
p->score_perso.position_number.x=120;
p->score_perso.position_number.y=20;
TTF_CloseFont(p->score_perso.police);


//initialiser vie 1
p->vie_perso.text=TTF_OpenFont("RES/REP2CN__.ttf",35); //chargement police/taille
SDL_Color blanc={255,255,255};
p->vie_perso.position_texte.x=600;
p->vie_perso.position_texte.y=20;
p->vie_perso.texte= TTF_RenderText_Blended(p->vie_perso.text,"Vie1 :",blanc); //ecriture
TTF_CloseFont(p->vie_perso.text);
p->vie_perso.image_vie[0]=IMG_Load("RES/vie03.png") ; //chargement d'image vie p1
p->vie_perso.image_vie[1]=IMG_Load("RES/vie02.png") ;
p->vie_perso.image_vie[2]=IMG_Load("RES/vie01.png") ;
p->vie_perso.image_vie[3]=IMG_Load("RES/vie00.png") ;

 p->vie_perso.position_vie.x=680;   //initialisation de position
 p->vie_perso.position_vie.y=20;
 p->vie_perso.nbvie=3;
}
void initPerso2(perso *p2)
{
p2->spritesheet=IMG_Load("RES/perso.png"); //chargement d'image p2
    
    p2->position.x=50;
    p2->position.y=238;

    p2->direction=2;

    p2->acceleration=0;
    p2->vitesse=0;
    p2->vitesseV=0;

    //position d'un frame  pour p2
    p2->pos_sprite.x= 0;
    p2->pos_sprite.y= 200;
    p2->pos_sprite.h= 100;
    p2->pos_sprite.w= 100;

//initialiser vie 2
p2->vie_perso.text=TTF_OpenFont("RES/REP2CN__.ttf",35);  //chargement police/taille
SDL_Color couleur={255,255,255};
p2->vie_perso.position_texte.x=600;
p2->vie_perso.position_texte.y=50;
p2->vie_perso.texte= TTF_RenderText_Blended(p2->vie_perso.text,"Vie2 :",couleur); //ecriture
TTF_CloseFont(p2->vie_perso.text);
p2->vie_perso.image_vie[0]=IMG_Load("RES/vie03.png") ; //chargement d'image vie p2
p2->vie_perso.image_vie[1]=IMG_Load("RES/vie02.png") ;
p2->vie_perso.image_vie[2]=IMG_Load("RES/vie01.png") ;
p2->vie_perso.image_vie[3]=IMG_Load("RES/vie00.png") ;

 p2->vie_perso.position_vie.x=680;
 p2->vie_perso.position_vie.y=50;
 p2->vie_perso.nbvie=3;
}
Ennemi initEnnemi( Ennemi e)
 {
  e.image[0]=IMG_Load("RES/rpg1.png");//loading des images dirigées vers la droite
  e.image[1]=IMG_Load("RES/rpg2.png");
  e.image[2]=IMG_Load("RES/rpg3.png");

  e.Hit=IMG_Load("imagedehit.png");//loading de l'image de hit

  e.image2[0]=IMG_Load("RES/rpd1.png");//loading des images dirigées vers la gauche
  e.image2[1]=IMG_Load("RES/rpd2.png");
  e.image2[2]=IMG_Load("RES/rpd3.png");

  e.imageActuel=e.image[0];//loading de l'image avec laquelle on commence l'animation
 
  e.position.x= 500;//positionement de l'ennemi
  e.position.y= 80;
  e.position.h= 250;
  e.position.w= 100;
 
  e.speed=1;//il ya de mvt
  e.frame=0;//statut avec laquelle on choisie limage
  e.direction=0; //0 : droite , 1 : gauche
                 
  return e;
}


Ennemi1 initEnnemi1( Ennemi1 e1)
{
  e1.image1[0]=IMG_Load("RES/a.png");
  e1.image1[1]=IMG_Load("RES/b.png");
  e1.image1[2]=IMG_Load("RES/c.png");

  e1.Hit=IMG_Load("RES/hit.png");

  e1.image3[0]=IMG_Load("RES/d.png");
  e1.image3[1]=IMG_Load("RES/e.png");
  e1.image3[2]=IMG_Load("RES/f.png");
 
  e1.imageActuel=e1.image1[0];

  e1.position.x= 500;
  e1.position.y= 200;
  e1.position.h= 250;
  e1.position.w= 100;
 
  e1.speed=1;//il y a un mouvement ou non
  e1.frame=0;//statut
  e1.direction=0; //0 : droite , 1 : gauche               
  return e1;
}
void affiche_back(back B, SDL_Surface* screen)	
 {
SDL_BlitSurface(B.img_back,NULL,screen,&B.pos_back);

 }

void afficherEnnemi(Ennemi e,SDL_Surface* screen)
{
  SDL_BlitSurface(e.imageActuel,NULL,screen,&e.position);//(image à copier,region a copier,surface destinataire ecran ,emplacement sur l'ecran) 
}


void afficherEnnemi1(Ennemi1 e1,SDL_Surface* screen)
{
  SDL_BlitSurface(e1.imageActuel,NULL,screen,&e1.position);
}


Ennemi animerEnnemi(Ennemi e, int l)
{
  if (e.frame==2) //statut avec derniere image
  {
    e.frame=0;//statut avec premiere image
  }

  else
  e.frame++;// incrementation des images

	if (e.direction== 0) //droite
 	 	e.imageActuel=e.image[e.frame];//on va charger les differentes images 
	else if(e.direction== 1)
	 	 e.imageActuel=e.image2[e.frame];//gauche
  if(l==1)//il y a collision
    e.imageActuel=e.Hit;//charger l'image de hit en cas de collision
  return e;
}


Ennemi1 animerEnnemi1(Ennemi1 e1, int f)
{
  if (e1.frame==2) //statut avec derniere image
  {
    e1.frame=0;//statut avec premiere image
  }

  else
  e1.frame++;// incrementation des images

	if (e1.direction== 0) //droite
 	 	e1.imageActuel=e1.image1[e1.frame];
	else if(e1.direction== 1)
	 	 e1.imageActuel=e1.image3[e1.frame];//gauche
  if(f==1)
   e1.imageActuel=e1.Hit;//changer l'image par l'image du hit
  return e1;
}


Ennemi deplacer( Ennemi e, int l)
{

  int PosMax=1100;//pos maximale qu'il ne faut pas depasser
  int PosMin=0;//pos minimale qu'il ne faut pas depasser
// if (l ==1)
 //e.speed=0;//pas de mvt

 if (e.direction==0 && e.position.x <PosMax) 
 e.position.x+= e.speed;//incrementation du pos vers la droite

 else if (e.position.x == PosMax)//rebourse le chemin
 e.direction=1;

 if (e.direction==1 && e.position.x>0) 
 e.position.x-= e.speed ;//decrementation du pos vers la gauche

 else if (e.position.x== 0)//rebourse le chemin
 e.direction=0;
  return e;
}


Ennemi1 deplacer1( Ennemi1 e1, int f)
{

  int PosMax=1100;
  int PosMin=0;

 //if (f ==1)
 //e1.speed=0;//pas de mvt


 if (e1.direction==0 && e1.position.x <PosMax) 
 e1.position.x+= e1.speed;

 else if (e1.position.x == PosMax)
 e1.direction=1;

 if (e1.direction==1 && e1.position.x>0) 
 e1.position.x-= e1.speed ;

 else if (e1.position.x== 0)
 e1.direction=0;


  return e1;
}

int Collision_Bounding_Box(perso p, Ennemi e ) 
{
    int col=0;
   if ((p.position.x + p.position.w< e.position.x) || (p.position.x>  e.position.x +  e.position.w) ||
(p.position.y + p.position.h<  e.position.y) || (p.position.y>  e.position.y +  e.position.h ))


col = 0 ;// pas de collision
else

col= 1; // collision

return col;
}
int Collision_Bounding_Box1(perso p, Ennemi1 e1 ) 
{
    int col1=0;
   if ((p.position.x + p.position.w< e1.position.x) || (p.position.x>  e1.position.x +  e1.position.w) ||
(p.position.y + p.position.h<  e1.position.y) || (p.position.y>  e1.position.y +  e1.position.h ))


col1 = 0 ;// pas de collision
else

col1= 1; // collision

return col1;
}


void afficherPerso(perso p, SDL_Surface * screen){
SDL_BlitSurface(p.spritesheet,&p.pos_sprite,screen,&p.position);//affichage du p ( chaque frame) à partir sprite sheet 
SDL_BlitSurface(p.score_perso.texte1, NULL,screen,&p.score_perso.position_txt);// afficher score(texte)
SDL_BlitSurface(p.score_perso.number1, NULL, screen,&p.score_perso.position_number);// afficher score

SDL_BlitSurface(p.vie_perso.image_vie[p.vie_perso.nbvie],NULL,screen,(&p.vie_perso.position_vie));  //affichage vie p1
SDL_BlitSurface(p.vie_perso.texte,NULL,screen,&(p.vie_perso.position_texte)); // vie 1 
}




void deplacerPerso (perso *p,int dt){   //deplacer p avec acceleration
    double dx;   
    dx = 0.5 * p->acceleration * dt *dt + p->vitesse * dt ; //equation relative à un petit deplacement dx
    if ((p->direction==0))  //  droite
    {
        p->position.x += dx ;
    }
    else if ((p->direction==1)) // gauche
    p->position.x -= dx ;
   
}

void animerPerso (perso* p){
    p->pos_sprite.x += 100;  //(x de chaque frame est egale à 100)//passage du frame  aux autres.

if (p->pos_sprite.x >= 1500) //si on depasse x (du dernier frame) on revient au premier frame (on a 15 frames)
p->pos_sprite.x = 0;
p->pos_sprite.y = p->direction * 100 ; //  ligne du sprite sheet
}


void saut (perso* p) {
    if (p->position.y==238)   // perso atteint position initiale
   {
       p->vitesseV=-50;    // vitessev diminue progressivement
 

    }

}

void liberer(perso p, SDL_Surface * screen)
{
SDL_FreeSurface(p.spritesheet);

}

