#ifndef Voiture_H
#define Voiture_H
#include <SDL/SDL.h>
#include "background.h"

		

		
struct Voiture{
	SDL_Rect position;
	SDL_Surface * image[5];
	int score;
	int vie;
	
	int direction; //0:right 1:left 2:up
	int moving; //0:not moving 1:moving
	float Mass;

	double velocity;
	double acceleration;
};
typedef struct Voiture Voiture;

int loadVoitureImages(Voiture * A);

void initVoiture(Voiture *A);

void moveVoiture(Voiture *A,Background *B,Uint32 dt);


void freeVoiture(Voiture *A);

#endif
