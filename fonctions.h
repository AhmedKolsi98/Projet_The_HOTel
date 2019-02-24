#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>
#include <FMOD/fmod.h>

#ifdef DEF_CONSTANTES
#define DEF_CONSTANTES //évite les inclusions infinies

#define LARGEUR_FENETRE 704
#define HAUTEUR_FENETRE 704

//jeu
void jouer(SDL_Surface* ecran);

#endif