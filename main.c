#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h> //librairies qui contient les fonctions
#include <SDL/SDL_Image.h>
int main(void)
{
	SDL_Surface *ecran = NULL;
	SDL_Surface *imageFond = NULL;
	SDL_Rect positionFond;
	positionFond.x = 0;
	positionFond.y = 0;

	imageFond = SDL_LoadBMP("background.bmp");
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("THe HOTel",NULL); //Name of the game
	//SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,30,15,22));
	SDL_BlitSurface(imageFond,NULL,ecran,&positionFond);
	SDL_Flip(ecran); //Mise à jour
	SDL_FreeSurface(imageFond);
	SDL_Delay(5000);
	SDL_Quit();
	return EXIT_SUCCESS;
}