#include "fonctions.h"

void scrolling_right (background *b , SDL_Surface *screen )
{
	if (b->camera.x<900-b->camera.w)
	b->camera.x+=20;
}
void scrolling_left (background *b , SDL_Surface *screen )
{
  if (b->camera.x>0)
	b->camera.x-=20;
}
void scrolling_up (background *b , SDL_Surface *screen)
{
	if (b->camera.y<450-b->camera.h)
	b->camera.y+=20;
}
void scrolling_down (background *b, SDL_Surface *screen)
{
	if(b->camera.y>0)
	b->camera.y-=20;
}
