#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "voiture.h"
#include "background.h"
#include <stdio.h>

int loadVoitureImages(Voiture * A)
{
	int i;
	char buf[50];
	char buf0[]="../images/voiture";
	char bmp[]=".bmp";
	for(i=0; i<4; i++) {
		sprintf(buf,"%s%d%s",buf0,i,bmp);
		A->image[i] = SDL_LoadBMP(buf);
		if (A->image[i]== NULL) {
			printf("Unable to load  Voiture bitmap:\n");
			return (-1);
		}
		// set the color of Voiture background (white color) as transparent
		SDL_SetColorKey( A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 255, 255, 255) );
	}
	return(0);
}

void initVoiture(Voiture *A)
{
	A->direction=0;
	A->position.x=0;
	A->position.y=SCREEN_H - A->image[0]->h;
	A->position.w=A->image[0]->w;
	A->position.h=A->image[0]->h;
	A->score=0;
	A->vie=5;
	A->velocity=2; //5km/h
	A->acceleration=0;
	A->Mass=70;
	A->moving=0;
}

void moveVoiture(Voiture *A,Background *B,Uint32 dt)
{
	/*Dx = vit + ½at2
	 * displacement = initial velocity * time + ½ acceleration * time2
	 * */
A->velocity+=0.5*A->acceleration*dt;
	B->backgroundPos.x+=A->velocity*dt;
		//Partie 1
}

void freeVoiture(Voiture *A)
{
	int i;
	for(i=0; i<4; i++)
		SDL_FreeSurface(A->image[i]);
}
