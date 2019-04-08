#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "background.h"

int width_bg=1134;


 
int main ()
{
SDL_Surface *screen;
screen=SDL_SetVideoMode(600,200,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
background b;
vie v;
initialisation_background (&b  );
 intialiser_vie (&v);

int done=1;

SDL_Event event;
    while(done)
    {
      
      if (SDL_PollEvent(&event))
       {


switch (event.type) {
  case SDL_QUIT  : done=0 ; break;
case SDL_KEYDOWN :
  if (event.key.keysym.sym == SDLK_RIGHT){
if (b.camera.x<=width_bg-600-20) 
    scrolling_right (& b , screen );


}
 else if (event.key.keysym.sym == SDLK_LEFT){
    if (b.camera.x>=0)
   scrolling_left (& b , screen );

  }
  
break;

}
}
gestion_vie (&v, k,screen) ;
afficher_background (screen ,& b);
afficher_vie (&v, k , screen );

SDL_Flip(screen);
}
}



