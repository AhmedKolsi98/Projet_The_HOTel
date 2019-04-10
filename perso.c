#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include"peso.h"
#include <SDL/SDL_image.h>



#define LARGEUR 1200
#define HAUTEUR 1000
void pause();
 
int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL;
 
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(LARGEUR,HAUTEUR, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
 
    SDL_Flip(screen);
    pause();
    
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
 


void initialiser_perssonage (perssonage *p)
{
p->personnage=IMG_Load("/home/fatima16/Desktop/projet/depositphotos_94168896-stock-illustration-businessman-cartoon-animation-sprite.jpg");
p->frame=0;
p->rect.x=0;
p->rect.y=0;
p->rect.w=100;
p->rect.h=200;

}

void afficher_perssonage (perssonage *p,SDL_Surface *screen)
{
	SDL_BlitSurface(p->personnage,&p->rects[p->frame],screen,&p->rect);
}

void animation_right (perssonage *p)
{

	p->frame++;
	if (p->frame>=4)
		p->frame=1;
}
void setrects(SDL_Rect* clip)
{
clip[0].x=0;
clip[0].y=0;
clip[0].w=83;
clip[0].h=100;

clip[1].x=94;
clip[1].y=0;
clip[1].w=83;
clip[1].h=100;

clip[2].x=188;
clip[2].y=0;
clip[2].w=83;
clip[2].h=100;

clip[3].x=282;
clip[3].y=0;
clip[3].w=83;
clip[3].h=100;

clip[4].x=376;
clip[4].y=0;
clip[4].w=83;
clip[4].h=100;
}
