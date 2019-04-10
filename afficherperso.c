#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
 
#define LARGEUR 850
#define HAUTEUR 425
void pause();
 
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *perso = NULL;
    SDL_Rect positionFond, positionperso;
 
    positionFond.x =0 ;
    positionFond.y =0;
    positionperso.x =0;
    positionperso.y =0;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(LARGEUR,HAUTEUR, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
 
    imageDeFond =IMG_Load("/home/fatima16/Desktop/projet/55554353_381460955916682_4721127716479303680_n.png");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
 
    /* Chargement d'un PNG avec IMG_Load
    */
    perso = IMG_Load("/home/fatima16/Desktop/projet/IMG_7713.png");
    SDL_BlitSurface(perso, NULL, ecran, &positionperso);
 
    SDL_Flip(ecran);
    pause();
 
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(perso);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
 

