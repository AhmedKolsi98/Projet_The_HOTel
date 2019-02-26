// Tutoriel : https://www.youtube.com/watch?v=a8U-ne3fLs8&index=37&list=PLGYKyocXgHJLZGFAQQ9yykmVFMoGSlBJr
#include "fonctions.h"

int main(void)
{
	SDL_Surface *ecran = NULL, *menu =NULL, *texte =NULL, *Play_Button = NULL,*Play_Button2 = NULL,*Play_Button3 = NULL,*Settings_Button = NULL,*Settings_Button2 = NULL,*Settings_Button3 = NULL,*Exit_Button = NULL,*Exit_Button2 = NULL,*Exit_Button3 = NULL;  //Surface pour le menu
	SDL_Rect positionMenu,positionClic,positionTxt,positionPlay,positionPlay2,positionPlay3,positionSettings,positionSettings2,positionSettings3,positionExit,positionExit2,positionExit3;
	SDL_Event event;
	int continuer = 1;

	TTF_Font *police = NULL, *policeSettings = NULL;
	SDL_Color couleur = {191,255,105};
	
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{printf("%s",Mix_GetError());}

	Mix_Music *music;
	music=Mix_LoadMUS("Menu_Background.mp3");
	Mix_PlayMusic(music,-1);

	TTF_Init(); //Initialisation police
	police = TTF_OpenFont("CaviarDreams_Bold.ttf",35); //chargement police
	policeSettings = TTF_OpenFont("CaviarDreams_Bold.ttf",20);

	putenv("SDL_VIDEO_CENTRED=1"); //On centre la fenetre
	if(SDL_Init(SDL_INIT_VIDEO != 0)){
		printf("Unable to initialize SDL: %s\n",SDL_GetError());
		return 1;
	}
	ecran = SDL_SetVideoMode(900,450,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Init(SDL_INIT_VIDEO); //On initialise la SDL
	SDL_WM_SetCaption("MonMenu",NULL);

	menu = IMG_Load("Menu.jpg");
	
	Play_Button = IMG_Load("Play.png");
	Play_Button2 = IMG_Load("Play2.png");
	Play_Button3 = IMG_Load("Play3.png");

	Settings_Button = IMG_Load("Settings.png");
	Settings_Button2 = IMG_Load("Settings2.png");
	Settings_Button3 = IMG_Load("Settings3.png");

	Exit_Button = IMG_Load("Exit.png");
	Exit_Button2 = IMG_Load("Exit2.png");
	Exit_Button3 = IMG_Load("Exit3.png");

	positionTxt.x = 417;
	positionTxt.y = 162;

	positionPlay.x =328;
	positionPlay.y =290;
	positionPlay2.x = positionPlay.x;
	positionPlay2.y = positionPlay.y;
	positionPlay3.x = positionPlay.x;
	positionPlay3.y = positionPlay.y;

	positionSettings.x =494;
	positionSettings.y =290;
	positionSettings2.x =positionSettings.x;
	positionSettings2.y =positionSettings.y;
	positionSettings3.x =positionSettings.x;
	positionSettings3.y =positionSettings.y;

	positionExit.x =661;
	positionExit.y =290;
	positionExit2.x = positionExit.x;
	positionExit2.y = positionExit.y;
	positionExit3.x = positionExit.x;
	positionExit3.y = positionExit.y;

	SDL_BlitSurface(menu,NULL,ecran,NULL);
	SDL_BlitSurface(Play_Button,NULL,ecran,&positionPlay);
	SDL_BlitSurface(Settings_Button,NULL,ecran,&positionSettings);
	SDL_BlitSurface(Exit_Button,NULL,ecran,&positionExit);
	SDL_Flip(ecran);


	while (continuer) //Boucle jeu
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
				if (event.button.x > positionPlay.x && event.button.x <(positionPlay.x+positionPlay.w) && event.button.y > positionPlay.y && event.button.y < (positionPlay.y+positionPlay.h))//Site
				{
					SDL_BlitSurface(Play_Button2,NULL,ecran,&positionPlay2);
					SDL_Flip(ecran);
				}
				else if (event.button.x > positionSettings.x && event.button.x <(positionSettings.x+positionSettings.w) && event.button.y > positionSettings.y && event.button.y < (positionSettings.y+positionSettings.h))//A propos 
				{
					SDL_BlitSurface(Settings_Button2,NULL,ecran,&positionSettings2);
					SDL_Flip(ecran);
				}
				else if (event.button.x > positionExit.x && event.button.x <(positionExit.x+positionExit.w) && event.button.y > positionExit.y && event.button.y < (positionExit.y+positionExit.h))
				{
					//On quitte
					SDL_BlitSurface(Exit_Button3,NULL,ecran,&positionExit3);
					SDL_Flip(ecran);
					exit(0);
				}	
			}
			case SDL_MOUSEMOTION: //Afficher un texte sur l'écran qui donne de l'information sur les bouttons
				if (event.motion.x > positionPlay.x && event.motion.x <(positionPlay.x+positionPlay.w) && event.motion.y > positionPlay.y && event.motion.y < (positionPlay.y+positionPlay.h)) //Jouer
				{
					texte = TTF_RenderText_Blended(police, "Play",couleur);

					SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
					SDL_BlitSurface(Play_Button3,NULL,ecran,&positionPlay3);
					SDL_Flip(ecran);
				}
				else if (event.motion.x > positionSettings.x && event.motion.x <(positionSettings.x+positionSettings.w) && event.motion.y > positionSettings.y && event.motion.y < (positionSettings.y+positionSettings.h))//Site
				{
					texte = TTF_RenderText_Blended(policeSettings, "Settings",couleur);

					SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
					SDL_BlitSurface(Settings_Button3,NULL,ecran,&positionSettings3);
					SDL_Flip(ecran);

				}
				else if (event.motion.x > positionExit.x && event.motion.x <(positionExit.x+positionExit.w) && event.motion.y > positionExit.y && event.motion.y < (positionExit.y+positionExit.h))//Quitter
				{
					texte = TTF_RenderText_Blended(police, "Quit",couleur);

					SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
					SDL_BlitSurface(Exit_Button3,NULL,ecran,&positionExit3);
					SDL_Flip(ecran);

					
				}
			break;	
		}
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(menu,NULL,ecran,&positionMenu);
		SDL_BlitSurface(Play_Button,NULL,ecran,&positionPlay);
		SDL_BlitSurface(Settings_Button,NULL,ecran,&positionSettings);
		SDL_BlitSurface(Exit_Button,NULL,ecran,&positionExit);
		SDL_Flip(ecran);
	}
//Libérer la totalité des objets qu'on a chargé

	TTF_CloseFont(police);
	TTF_Quit();
	Mix_FreeMusic(music);

	SDL_FreeSurface(menu);
	SDL_FreeSurface(texte);

	SDL_FreeSurface(Play_Button);
	SDL_FreeSurface(Play_Button2);
	SDL_FreeSurface(Play_Button3);

	SDL_FreeSurface(Settings_Button);
	SDL_FreeSurface(Settings_Button2);
	SDL_FreeSurface(Settings_Button3);

	SDL_FreeSurface(Exit_Button);
	SDL_FreeSurface(Exit_Button2);
	SDL_FreeSurface(Exit_Button3);

	SDL_VideoQuit();
	SDL_Quit();

	return EXIT_SUCCESS;

}







