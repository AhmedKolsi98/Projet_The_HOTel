#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>
#include "defs.h"

struct Background{
	SDL_Surface *backgroundImg;
	SDL_Surface *backgroundCollide;
	SDL_Rect backgroundPos;
};
typedef struct Background Background;

int loadBackground(Background *Backg);
void initBackground(Background *Backg);
void freeBackground(Background *Backg);
void blitBackground(Background*Backg,SDL_Surface *screen);

#endif
