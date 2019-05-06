#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "background.h"
void initialisation_background (background *b  )
{
//b->pos.x=0;
//b->pos.y=0;
b->camera.x=0;
b->camera.y=0;
b->camera.w=800;
b->camera.h=200;
b->background=IMG_Load("background.jpg");

}

 void afficher_background (SDL_Surface *screen , background *b)
{
SDL_BlitSurface(b->background,&b->camera,screen,NULL);
}

void scrolling_right (background *b , SDL_Surface *screen )
{

b->camera.x+=20;
}

void scrolling_left (background *b , SDL_Surface *screen )
{

b->camera.x-=20;
}


void intialiser_vie (vie *v)
{


v->positionvie.x=500;
v->positionvie.y=0; 
v->positionvie1.x=550;
v->positionvie1.y=0;
v->positionvie2.x=450;
v->positionvie2.y=0;
v->positiongameover.x=0; 
v->positiongameover.y=0 ; 
 v->nbr = 3 ; 
v->vie3=IMG_Load ("vie0.png");
v->vie2=IMG_Load ("vie1.png"); 
v->vie1=IMG_Load ("vie2.png") ; 
v->vie0=IMG_Load ("vie3.png") ; 



}


void afficher_vie (vie *v, int k , SDL_Surface *screen )
{

SDL_BlitSurface (v->vie0,NULL,screen,&(v->positionvie));
SDL_BlitSurface (v->vie1,NULL,screen,&(v->positionvie1));
SDL_BlitSurface (v->vie1,NULL,screen,&(v->positionvie2));
}
void gestion_vie (vie *v, int k , SDL_Surface *screen )
{

if ( k == 1) 
{ 
 {v->nbr--; 

 SDL_BlitSurface (v->vie1,NULL,screen,&(v->positionvie));} }


if (k == 1 ) 
 
 {  v->nbr-- ; 

  SDL_BlitSurface (v->vie2,NULL,screen,&(v->positionvie));} 

if (k == 1 ) 

 {v->nbr--; 

SDL_BlitSurface (v->vie3,NULL,screen,&(v->positiongameover)) ;}
}










