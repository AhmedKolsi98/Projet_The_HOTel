#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>
#include <SDL/SDL_mixer.h>

#ifdef DEF_CONSTANTES
#define DEF_CONSTANTES //évite les inclusions infinies

#define LARGEUR_FENETRE 900
#define HAUTEUR_FENETRE 450

//jeu
void jouer(SDL_Surface* ecran);

#endif