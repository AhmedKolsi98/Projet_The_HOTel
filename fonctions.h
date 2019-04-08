#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>
#include <SDL/SDL_mixer.h>


typedef struct background 
{
SDL_Surface *background;
SDL_Surface *screen;
SDL_Rect camera;
//SDL_Rect pos;
}background;

void initialisation_background (background *b  );
void afficher_background (SDL_Surface *screen , background *b);
// Les fonctions de scrolling
void scrolling_right (background *b , SDL_Surface *screen );
void scrolling_left (background *b , SDL_Surface *screen );



//jeu
void jouer(SDL_Surface* ecran);


