#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "boundingbox.h"
int main()
{

SDL_Surface *screen=NULL;

screen = SDL_SetVideoMode(largeur,hauteur,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);


SDL_Flip(screen);
SDL_FreeSurface(screen);
SDL_Quit();
}
