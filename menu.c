// Tutoriel : https://www.youtube.com/watch?v=a8U-ne3fLs8&index=37&list=PLGYKyocXgHJLZGFAQQ9yykmVFMoGSlBJr
#include "fonctions.h"

int main(int argc, char** argc)
{
	SDL_Surface *ecran = NULL, *menu =NULL, *texte =NULL; //Surface pour le menu
	SDL_Rect positionMenu,positionClic,positionTxt;
	SDL_Event event;
	int continuer = 1;

	TTF_Font *police = NULL;
	SDL_Color couleurNoire = {0,0,0},couleurBlanche = {255,255,255},couleurRouge = {255,0,0}
	TTF_Font *police
	FSOUND_STREAM *music = NULL;
	FSOUND_Init(44100,32,0); //Initialisation musique
	music = FSOUND_Stream_Open("SonMenu.ogg",FSOUND_LOOP_NORMAL,0,0);
	TTF_Init(); //Initialisation police
	police = TTF_OpenFont("police.ttf",35); //chargement police
	policeBig = TTF_OpenFont("police.ttf",95); //Grand police

	putenv("SDL_VIDEO_CENTRED=1"); //On centre la fenetre
	SDL_Init(SDL_INIT_VIDEO); //On initialise la SDL
	SDL_WM_SetCaption("MonMenu",NULL);

	menu = IMG_Load("MenuJeu.png");

	FSOUND_Stream_SetLoopCount(music,-1);
	FSOUND_Stream_Play(FSOUND_Free, music);
	positionMenu.x = 0;
	positionMenu.y = 0;

	while (continuer)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			continuer = 0;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
				//...
				break;
			}
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				positionClic.x = event.button.x; //On récupére les coordonnées de souris
				positionClic.y = event.button.y;
				if (event.button.x > 10 && event.button.x < 150 && event.button.y > 120 && event.button.y < 160) //Jouer
				{
					texte = TTF_RenderText_Blended(policeBig, "Ta fin est proche ...",couleurRouge);
					positionTxt.x = 30;
					positionTxt.y = 500;
					SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
					SDL_Flip(ecran);

					//jouer(ecran);


				}
				else if (event.button.x > 10 && event.button.x <150 && event.button.y > 180 && event.button.y < 220)//Site
				{
					system("start http://www.netprof.fr");
				}
				else if (event.button.y > 10 && event.button.x <150 && event.button.y < 240 && event.button.y < 280)//A propos
				{

				}
				else if (event.button.y > 10 && event.button.x <150 && event.button.y < 630 && event.button.y < 670)//Quitter
				{
					//On quitte
					exit(0);
				}	
			}
			case SDL_MOUSEMOTION: //Afficher un texte qui donne de l'information sur les bouttons
				if (event.motion.x > 10 && event.motion.x < 150 && event.motion.y > 120 && event.motion.y < 160) //Jouer
				{
					texte = TTF_RenderText_Blended(police, "Ta fin est proche ...",couleurRouge);
					positionTxt.x = 230;
					positionTxt.y = 622;
					SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
					SDL_Flip(ecran);

					SDL_Delay(150); //Evite de faire sauter l'image
				}
				else if (event.motion.x > 10 && event.motion.x <150 && event.motion.y > 180 && event.motion.y < 220)//Site
				{
					texte = TTF_RenderText_Blended(police, "Page internet",couleurRouge);
					positionTxt.x = 230;
					positionTxt.y = 622;
					SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
					SDL_Flip(ecran);

					SDL_Delay(150); //Evite de faire sauter l'image
				}
				else if (event.motion.y > 10 && event.motion.x <150 && event.motion.y < 240 && event.motion.y < 280)//A propos
				{
					texte = TTF_RenderText_Blended(police, "A propos",couleurRouge);
					positionTxt.x = 230;
					positionTxt.y = 622;
					SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
					SDL_Flip(ecran);

					SDL_Delay(150); //Evite de faire sauter l'image
				}
				else if (event.motion.y > 10 && event.motion.x <150 && event.motion.y < 630 && event.motion.y < 670)//Quitter
				{
					texte = TTF_RenderText_Blended(police, "Quitter",couleurRouge);
					positionTxt.x = 230;
					positionTxt.y = 622;
					SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
					SDL_Flip(ecran);

					SDL_Delay(150); //Evite de faire sauter l'image
				}
			break;		
		}
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(menu,NULL,ecran,&positionMenu);

		SDL_Flip(ecran);
	}
//Libérer la totalité des objets qu'on a chargé
	FSOUND_Stream_Close(music);
	SDL_FreeSurface(menu);

	TTF_CloseFont(police);
	TTF_Quit();

	SDL_FreeSurface(texte);
	SDL_Quit();

	return EXIT_SUCCESS;

}







