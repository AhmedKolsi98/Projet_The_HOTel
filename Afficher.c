#include "fonctions.h"

void afficher_background (SDL_Surface *screen , background *b)
{
SDL_BlitSurface(b->background,&b->camera,screen,NULL);
}

