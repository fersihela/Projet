
#include "perso.h"

int main()
{ TTF_Init();

//declaration
SDL_Surface *screen;
SDL_Surface *texte1=NULL;  //texte:score
SDL_Surface *number1=NULL; //score(valeur)
SDL_Surface *texte2=NULL;
TTF_Font *police=NULL; //font du score
TTF_Font *text2=NULL;  //vie 1

SDL_Event event;
SDL_Surface *back;

SDL_Rect positionback;
perso p;


int done=1,droite=0,gauche=0,up=0,dir=2;
Uint32 dt, t_prev;

//initialisation

SDL_Init(SDL_INIT_VIDEO); //initialiser SDL
screen=SDL_SetVideoMode (1200,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF); //creation d'une fenetre
SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre
back=IMG_Load("back.png"); //chargement  back du jeu
positionback.x=0;
positionback.y=0;
initPerso(&p);

//score
  
police = TTF_OpenFont("image/REP2CN__.ttf", 35); //chargement d'une police avec taille

SDL_Color blanco={255,255,255}; 
p.score_perso.position_txt.x=15;
p.score_perso.position_txt.y=20;

texte1= TTF_RenderText_Blended(police,"score :",blanco);  

p.score_perso.number[20];
p.score_perso.valscore=1450;

sprintf(p.score_perso.number, "%d",(p.score_perso.valscore));//conversion 

number1= TTF_RenderText_Blended(police,p.score_perso.number,blanco);
p.score_perso.position_number.x=120;
p.score_perso.position_number.y=20;
TTF_CloseFont(police);

//vie1
text2=TTF_OpenFont("image/REP2CN__.ttf",35); //chargement police/taille
SDL_Color blanc={255,255,255};
p.vie_perso.position_texte.x=580;
p.vie_perso.position_texte.y=15;
texte2= TTF_RenderText_Blended(text2,"Vie1 :",blanc); //ecriture
TTF_CloseFont(text2);



p.vie_perso.image_vie[0]=IMG_Load("image/vie03.png") ; //chargement d'image vie p1
p.vie_perso.image_vie[1]=IMG_Load("image/vie02.png") ;
p.vie_perso.image_vie[2]=IMG_Load("image/vie01.png") ;
p.vie_perso.image_vie[3]=IMG_Load("image/vie00.png") ;

 p.vie_perso.position_vie.x=650;
 p.vie_perso.position_vie.y=20;
 p.vie_perso.nbvie=3;
 
//boucle du jeu
while (done)
{ 
//affichage 
SDL_BlitSurface(back,NULL,screen,&positionback);
afficherPerso(p,screen);   //afficher p1
    
SDL_BlitSurface(p.vie_perso.image_vie[p.vie_perso.nbvie],NULL,screen,(&p.vie_perso.position_vie));  //affichage vie p1

SDL_BlitSurface(texte2,NULL,screen,&(p.vie_perso.position_texte));//vie (texte)p1

SDL_BlitSurface(texte1, NULL, screen,&p.score_perso.position_txt);//score(texte)
SDL_BlitSurface(number1, NULL, screen,&p.score_perso.position_number);//score(valeur) 
	

SDL_Flip(screen);//mise à jour
SDL_Delay(100); //attente


t_prev=SDL_GetTicks();//temps au debut du jeu (prelevement du temps)

  //input 
while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
    case SDL_QUIT:
        done=0;  //quitter jeu
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=1;
                break;
            case SDLK_LEFT:
                gauche=1;
                break;
            case SDLK_UP:
                up=1;
                break;  
            
        }
    break;

    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=0;   //p1 stable avec direction droite
                dir=2;
                p.vitesse=0;
                break;
            case SDLK_LEFT:
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



//update

if (droite==1)      //direction (droite) du p1
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=0;


}
if (gauche==1)    // à gauche du p1
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=1;

} 
if (up==1)   //saut
saut(&p);

p.acceleration -=0.3;//deceleration p1

if (p.acceleration<0 ) 
p.acceleration=0; //   controler l'intervalle de l'acceleration p1
if (p.acceleration>4) 
p.acceleration=4;

SDL_Delay(1);
dt = SDL_GetTicks() - t_prev;   //le temps ecoulé depuis initialisation du boucle du jeu
deplacerPerso(&p,dt);
animerPerso(&p);

if ((p.vitesse==0)&&(p.acceleration==0))  //perso est stable 
{
    p.direction=dir;  //sauvgarder la direction du personnage p1 lorsque il devient fixe 
}
p.position.y += p.vitesseV;  //position change en fonction du vitesev
p.vitesseV += 10; 
if (p.position.y >=238)
{
    p.vitesseV=0;//descendre p1
    p.position.y=238;
}
}
TTF_Quit();
return 0;
}

