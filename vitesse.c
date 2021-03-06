#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//define
#define largeur 800
#define hauteur 700

typedef struct Hero Hero;
struct Hero
{
SDL_Surface *screen;
SDL_Rect screen_rect;
SDL_Event event;
//background
SDL_Surface* bg ;
SDL_Rect bg_rect;

//perso
SDL_Surface* p ;
SDL_Rect p_rect;
int running
};
//les fonctions
void action_create(Hero* Hero)
{
//screen
Hero->screen=NULL;
Hero->screen = SDL_SetVideoMode(largeur,hauteur, 32, SDL_HWSURFACE);
SDL_WM_SetCaption("Ma super fenêtre SDL !", NULL);
//bg
Hero->bg=NULL;
SDL_Surface* tmp=NULL ;
tmp=IMG_Load("background.png");
Hero->bg=SDL_DisplayFormat(tmp);
SDL_FreeSurface(tmp);
tmp=NULL;
//rect bg
SDL_GetClipRect(Hero->bg,&Hero->bg_rect);

//perso
Hero->p=NULL;
tmp=IMG_Load("p1.PNG");

Hero->p=SDL_DisplayFormatAlpha(tmp);
SDL_FreeSurface(tmp);
tmp=NULL;
//rect perso
SDL_GetClipRect(Hero->p,&Hero->p_rect);
//position du perso
Hero->p_rect.x=60;
Hero->p_rect.y=450;


}
void action_dispose(Hero* Hero)
{
SDL_FreeSurface(Hero->bg);
SDL_FreeSurface(Hero->p);

}





void action_render(Hero* Hero)
{
SDL_BlitSurface(Hero->bg,NULL,Hero->screen,&Hero->bg_rect);
SDL_BlitSurface(Hero->p,NULL,Hero->screen,&Hero->p_rect);
SDL_Flip(Hero->screen);
}


int main(int argc, char *argv[])
{
int ex=0;

int running=1;
int now=0;
int dx=0;
int periodeFps=33; //33 frame par s
int dt=0;
float delta_s=0;
int xp;
Hero Hero;
Hero.running=1; //start while

//init
SDL_Init(SDL_INIT_VIDEO |SDL_INIT_AUDIO);
action_create( &Hero);

    //game loop
while(Hero.running)
{
    switch(Hero.event.type)
{
case SDL_QUIT:

Hero.running=0;
break;

//
case SDL_KEYDOWN:
switch(Hero.event.key.keysym.sym)
{
case SDLK_ESCAPE:
//
Hero.running=0;
break;
//
case SDLK_f:
 xp=Hero.p_rect.x;
 dx=1000; //vitesse en x
xp=xp+dx*delta_s;
//
if(xp > largeur)
{
 xp=0;
}
Hero.p_rect.x=xp;
  break;
default:
break;
}

break;
//
case SDL_KEYUP:
break;

default:
break;
}
now=SDL_GetTicks();
dt=now-ex;
if(dt > periodeFps)
{
delta_s=dt/1000.0;


SDL_PollEvent(& Hero.event);
action_render( &Hero);


//
ex=now;


}

else{
SDL_Delay(periodeFps -dt);
}
  }
//
action_dispose( &Hero);
//quit
SDL_Quit(); //sup screen

    return EXIT_SUCCESS;
}

