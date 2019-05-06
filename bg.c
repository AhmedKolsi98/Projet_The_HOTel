#include "bg.h"

void initialiser_backround(background *b,int x)
{
b->background=NULL;
b->background=IMG_Load("background.png");
b->camera.x=0;
b->camera.y=0;
b->camera.w=480;
b->camera.h=480;
b->posbg.x=x;
b->posbg.y=0;
}
void afficher_background (SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->background,&b->camera,screen,&b->posbg);
}
