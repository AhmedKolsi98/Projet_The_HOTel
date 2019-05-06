#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"anime.h"


int main(int argc, char *argv[])
{
    int velocity=0,gravity=12;
    int ground=450;
    SDL_Init(SDL_INIT_VIDEO);
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("erreur de chargement de la bibliotheque video : > %s ",SDL_GetError());
    }

    SDL_Surface *screen=NULL, *p[8]= {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},*background=NULL;

    p[0]=IMG_Load("p1.PNG");
    p[1]=IMG_Load("p2.PNG");
    p[2]=IMG_Load("p3.PNG");
    p[3]=IMG_Load("p4.PNG");
    p[4]=IMG_Load("p11.png");
    p[5]=IMG_Load("p12.png");
    p[6]=IMG_Load("p13.png");
    p[7]=IMG_Load("p14.png");

    int i=0;
    for(; i<4; i++)
    {
        if(!p[i])
        {
            printf("erreur de chargement de limage %d : > %s ",i+1,SDL_GetError());
        }
    }

    screen = SDL_SetVideoMode(largeur,hauteur,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    if(!screen)
    {
        printf("erreur de chargement de l'ecran : > %s",SDL_GetError());
    }

    background = IMG_Load("background.png");

    SDL_Rect p_p, p_background;

    p_background.x=0;
    p_background.y=0;

    p_p.x=60;
    p_p.y=450;

    SDL_Event event;
    int cont=1;
    int frame =0;
    const int speed=1;
    SDL_EnableKeyRepeat(10,10);
    while(cont)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE :
                cont = 0;
                break;
            /*case SDLK_LEFT :
                   if(frame>=4)
                {
                    frame=0;
                }*/

               // SDL_Flip(screen);
                SDL_Delay(50);
                p_p.x-=10;
                frame++;
                break;
                break;
            case SDLK_RIGHT :
                if(frame>=3)
                {
                    frame=0;
                }

               // SDL_Flip(screen);
                SDL_Delay(50);
                p_p.x+=10;
                frame++;
                break;

            case SDLK_UP :
                if( p_p.y==ground)//collision with ground
                    velocity =-100;


                break;


            }
            break;
        case SDL_KEYUP :
           if(event.key.keysym.sym==SDLK_UP)
              {
                  velocity=0;
              p_p.y=ground;
              }

            break;


        }


                SDL_BlitSurface(background,NULL,screen,&p_background);
                SDL_BlitSurface(p[frame],NULL,screen,&p_p);
                SDL_Flip(screen);


      velocity+=gravity;
        p_p.y += velocity;
        if(p_p.y >= ground)
        {
            p_p.y=ground;
            velocity = 0;
        }
    }



    SDL_FreeSurface(p[8]);
    SDL_FreeSurface(background);

    SDL_Quit();

}
