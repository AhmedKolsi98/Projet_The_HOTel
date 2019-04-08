#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
typedef struct background 
{
SDL_Surface *background;
SDL_Surface *screen;
SDL_Rect camera;
//SDL_Rect pos;
}background;
void initialisation_background (background *b  );
void afficher_background (SDL_Surface *screen , background *b);
void scrolling_right (background *b , SDL_Surface *screen );
void scrolling_left (background *b , SDL_Surface *screen );
int k;
typedef struct vie
{
	SDL_Surface *vie0 ; 
SDL_Surface *vie1 ;
SDL_Surface *vie2 ; 
SDL_Surface *vie3 ;
SDL_Rect positionvie;
SDL_Rect positionvie1;
SDL_Rect positionvie2;
SDL_Rect positiongameover ; 
int nbr;

} vie ;
void intialiser_vie (vie *v);
void afficher_vie (vie *v, int k , SDL_Surface *screen );

void gestion_vie (vie *v, int k,SDL_Surface *screen) ;


