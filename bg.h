#ifndef BG_H_INCLUDED
#define BG_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct  background
{

	    SDL_Surface *background;
	    SDL_Rect camera;
	    SDL_Rect posbg;
}background;
void initialiser_backround (background *b,int x);
void afficher_background (SDL_Surface *screen,background *b);
#endif // BG_H_INCLUDED
