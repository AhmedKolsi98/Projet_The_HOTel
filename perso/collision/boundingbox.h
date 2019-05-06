#ifndef BOUNDINGBOX_H_INCLUDED
#define BOUNDINGBOX_H_INCLUDED


typedef struct 
{int x ;
int y;
int w;
int h;
}posperso;

typedef struct 
{int x ;
int y;
int w;
int h;
}posennemi;
bool collision(SDL_Rect* rect1,SDL_Rect* rect2);
#endif
