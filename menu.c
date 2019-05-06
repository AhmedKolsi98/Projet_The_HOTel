#include "fonctions.h"

void intro_game();
void credits();
void options();
void jouer();

int main(void)
{
	int cursor=0;
	int continuer = 1;
SDL_Surface *screen = NULL;
	SDL_Surface *menu =NULL;
	SDL_Surface *texte =NULL;
	SDL_Surface *Play_Button[3];
	SDL_Surface *Settings_Button[3];
	SDL_Surface *Exit_Button[3];

	SDL_Rect positionScreen;
	SDL_Rect positionMenu;
	SDL_Rect positionTxt;
	SDL_Rect positionPlay[3];
	SDL_Rect positionSettings[3];
	SDL_Rect positionExit[3];

	TTF_Font *police = NULL;
	TTF_Font *policeSettings = NULL;
	SDL_Color couleur = {191,255,105};

	SDL_Event event;
	putenv("SDL_VIDEO_CENTRED=1"); //On centre la fenetre
	if(SDL_Init(SDL_INIT_VIDEO != 0)){
		printf("Unable to initialize SDL: %s\n",SDL_GetError());
		return 1;
	}
	screen = SDL_SetVideoMode(900,450,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Init(SDL_INIT_VIDEO); //On initialise la SDL
	SDL_WM_SetCaption("El HOTel",NULL);
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
   	{
      printf("%s", Mix_GetError());
   	}
	
	Mix_Music *music ;

    music=Mix_LoadMUS("Music/Menu_bg.mp3");

    Mix_PlayMusic(music, -1);


	
	TTF_Init(); //Initialisation police
	police = TTF_OpenFont("Fonts/CaviarDreams_Bold.ttf",35); //chargement police
	policeSettings = TTF_OpenFont("Fonts/CaviarDreams_Bold.ttf",20);


	menu = IMG_Load("Menu.jpg");

	//Image loading	

	Play_Button[0] = IMG_Load("Buttons/Play.png");
	Play_Button[1] = IMG_Load("Buttons/Play2.png");
	Play_Button[2] = IMG_Load("Buttons/Play3.png");

	Settings_Button[0] = IMG_Load("Buttons/Settings.png");
	Settings_Button[1] = IMG_Load("Buttons/Settings2.png");
	Settings_Button[2] = IMG_Load("Buttons/Settings3.png");

	Exit_Button[0] = IMG_Load("Buttons/Exit.png");
	Exit_Button[1] = IMG_Load("Buttons/Exit2.png");
	Exit_Button[2] = IMG_Load("Buttons/Exit3.png");

	positionScreen.x = 0;
	positionScreen.y = 0;
	positionScreen.h = menu->h;
	positionScreen.w = menu->w;

	positionTxt.x = 417;//0,64 * positionscreen.h;
	positionTxt.y = 162; //0,36 * positionscreen.w;

	positionPlay[0].x =328;//0,36 * positionscreen.h;
	positionPlay[0].y =290;//0,64 * positionscreen.w;
	positionPlay[1].x = positionPlay[0].x;
	positionPlay[1].y = positionPlay[0].y;
	positionPlay[2].x = positionPlay[0].x;
	positionPlay[2].y = positionPlay[0].y;

	positionSettings[0].x =494;//0,55 * positionscreen.h;
	positionSettings[0].y =290;//0,64 * positionscreen.w;
	positionSettings[1].x =positionSettings[0].x;
	positionSettings[1].y =positionSettings[0].y;
	positionSettings[2].x =positionSettings[0].x;
	positionSettings[2].y =positionSettings[0].y;

	positionExit[0].x = 661; //0,73 * positionscreen.h
	positionExit[0].y = 290;//0,64 * positionscreen.w
	positionExit[1].x = positionExit[0].x;
	positionExit[1].y = positionExit[0].y;
	positionExit[2].x = positionExit[0].x;
	positionExit[2].y = positionExit[0].y;

	SDL_BlitSurface(menu,NULL,screen,&positionScreen);
	SDL_BlitSurface(Play_Button[0],NULL,screen,&positionPlay[0]);
	SDL_BlitSurface(Settings_Button[0],NULL,screen,&positionSettings[0]);
	SDL_BlitSurface(Exit_Button[0],NULL,screen,&positionExit[0]);
	SDL_Flip(screen);

	    while(1)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                exit(0);
            
            /*if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= ) && (event.button.x <= ))&&((event.button.y >= ) && (event.button.y <= )))
                    {
                        system(""); //Facebook 
                    }
                    if (((event.button.x >= ) && (event.button.x <= ))&&((event.button.y >= ) && (event.button.y <= )))
                    {
                        system(""); //Twitter
                    }

                }
            }*/
            if(event.type == SDL_MOUSEMOTION)
            {


              	if((event.button.x > positionPlay[0].x) && (event.button.x <(positionPlay[0].x+positionPlay[0].w)) && (event.button.y > positionPlay[0].y) && (event.button.y < (positionPlay[0].y+positionPlay[0].h)))
              	{cursor = 1 ;} //Play

              	else if ((event.button.x > positionSettings[0].x) && (event.button.x <(positionSettings[0].x+positionSettings[0].w)) && (event.button.y > positionSettings[0].y) && (event.button.y < (positionSettings[0].y+positionSettings[0].h)))
              	{cursor = 2 ;} //Settings

            	else if ((event.button.x > positionExit[0].x) && (event.button.x <(positionExit[0].x+positionExit[0].w)) && (event.button.y > positionExit[0].y) && (event.button.y < (positionExit[0].y+positionExit[0].h)))
            	{cursor = 3 ;} //Exit

            /*else if ( (event.button.x>309 && event.button.x<485 && event.button.y>409 && event.button.y<446) )
            {x = 4 ;}*/

              	else
              	{cursor = 0 ;}
          	}

           	if (event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_RIGHT)
                {    
                    if(cursor<=3)
                        cursor=cursor+1;
					if(cursor==4) 
                		cursor=1;
                }
                if(event.key.keysym.sym == SDLK_LEFT)
                {   
                    if(cursor>0)
                        cursor=cursor-1;
					if(cursor==0) 
                		cursor=3;
                }
            }
				else if (((event.key.keysym.sym == SDLK_KP_ENTER)||(event.key.keysym.sym == SDLK_RETURN)))
                
                    switch (cursor) //button pressed
                    {
			        case 1:

						SDL_BlitSurface(Settings_Button[0],NULL,screen,&positionSettings[0]);
						SDL_BlitSurface(Exit_Button[0],NULL,screen,&positionExit[0]);	
						
						SDL_BlitSurface(Play_Button[2],NULL,screen,&positionPlay[2]);
						SDL_Flip(screen);

						void jouer();

			            break;

			        case 2:
			       		SDL_BlitSurface(Play_Button[0],NULL,screen,&positionPlay[0]);
						SDL_BlitSurface(Exit_Button[0],NULL,screen,&positionExit[0]);

						SDL_BlitSurface(Settings_Button[2],NULL,screen,&positionSettings[2]);
						SDL_Flip(screen);
			        break;
			        

			        case 3:
			        	SDL_BlitSurface(Play_Button[0],NULL,screen,&positionPlay[0]);
						SDL_BlitSurface(Settings_Button[0],NULL,screen,&positionSettings[0]);

						SDL_BlitSurface(Exit_Button[2],NULL,screen,&positionExit[2]);
						SDL_Flip(screen);        

			          break;
                    }
              
                if(event.type == SDL_MOUSEBUTTONDOWN)
            	{
	                if (event.button.button == SDL_BUTTON_LEFT) //Button is pressed

	                    switch (cursor)
	                    {
				        case 1:
				        
							SDL_BlitSurface(Play_Button[2],NULL,screen,&positionPlay[2]);
							SDL_Flip(screen);
				            break;
				        

				        case 2:
				        
							SDL_BlitSurface(Settings_Button[2],NULL,screen,&positionSettings[2]);
							SDL_Flip(screen);
				        	break;
				        

				        case 3:

							SDL_BlitSurface(Exit_Button[2],NULL,screen,&positionExit[2]);
							SDL_Flip(screen);        
	       		        	break;
	                    }
           		}
            switch (cursor) //selected
	      {

        case 1: //Play button selected
        		SDL_BlitSurface(menu,NULL,screen,&positionMenu);
			texte = TTF_RenderText_Blended(police, "Play",couleur);

			SDL_BlitSurface(Settings_Button[0],NULL,screen,&positionSettings[0]);
			SDL_BlitSurface(Exit_Button[0],NULL,screen,&positionExit[0]);

			SDL_BlitSurface(texte,NULL,screen,&positionTxt);
			SDL_BlitSurface(Play_Button[1],NULL,screen,&positionPlay[1]);
			SDL_Flip(screen);
            break;
        
        case 2: //Settings buttn selected
        		SDL_BlitSurface(menu,NULL,screen,&positionMenu);
			texte = TTF_RenderText_Blended(policeSettings, "Settings",couleur);

			SDL_BlitSurface(Play_Button[0],NULL,screen,&positionPlay[0]);
			SDL_BlitSurface(Exit_Button[0],NULL,screen,&positionExit[0]);
			
			SDL_BlitSurface(texte,NULL,screen,&positionTxt);
			SDL_BlitSurface(Settings_Button[1],NULL,screen,&positionSettings[1]);
			SDL_Flip(screen);
        break;
        
        case 3: //exit button selected
			SDL_BlitSurface(menu,NULL,screen,&positionMenu);
			texte = TTF_RenderText_Blended(police, "Quit",couleur);

			SDL_BlitSurface(Play_Button[0],NULL,screen,&positionPlay[0]);
			SDL_BlitSurface(Settings_Button[0],NULL,screen,&positionSettings[0]);

			SDL_BlitSurface(texte,NULL,screen,&positionTxt);
			SDL_BlitSurface(Exit_Button[1],NULL,screen,&positionExit[1]);
			SDL_Flip(screen);        

          break;
        
        default: //Nothing is selected
        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
		SDL_BlitSurface(menu,NULL,screen,&positionMenu);
		SDL_BlitSurface(Play_Button[0],NULL,screen,&positionPlay[0]);
		SDL_BlitSurface(Settings_Button[0],NULL,screen,&positionSettings[0]);
		SDL_BlitSurface(Exit_Button[0],NULL,screen,&positionExit[0]);
		SDL_Flip(screen);

        break;
        }
    }    
}
	TTF_CloseFont(police);
	TTF_Quit();


	SDL_FreeSurface(menu);
	SDL_FreeSurface(texte);

	SDL_FreeSurface(Play_Button[0]);
	SDL_FreeSurface(Play_Button[1]);
	SDL_FreeSurface(Play_Button[2]);

	SDL_FreeSurface(Settings_Button[0]);
	SDL_FreeSurface(Settings_Button[1]);
	SDL_FreeSurface(Settings_Button[2]);

	SDL_FreeSurface(Exit_Button[0]);
	SDL_FreeSurface(Exit_Button[1]);
	SDL_FreeSurface(Exit_Button[2]);


	return EXIT_SUCCESS;
}
<<<<<<< HEAD
int main()
{
    return 0;
}






=======
>>>>>>> 55d3c12087fddef46ef3c9d4231a5de5620434c3
