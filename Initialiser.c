#include "fonctions.h"

void initialisation_background (background *b  )
{
//b->pos.x=0;
//b->pos.y=0;
b->camera.x=0;
b->camera.y=0;
b->camera.w=800;
b->camera.h=400;
b->background=IMG_Load("background.png");
}
void initialisation_personnage (personnage *perso  )
{
//b->pos.x=0;
//b->pos.y=0;
perso->camera.x=0;
perso->camera.y=0;
perso->camera.w=800;
perso->camera.h=400;
perso->perso=IMG_Load("personnage.png");
}
void initialisation_ennemi (ennemi *Ennemi  )
{
//b->pos.x=0;
//b->pos.y=0;
Ennemi->camera.x=0;
Ennemi->camera.y=0;
Ennemi->camera.w=800;
Ennemi->camera.h=400;
Ennemi->Ennemi=IMG_Load("ennemi.png");
}

