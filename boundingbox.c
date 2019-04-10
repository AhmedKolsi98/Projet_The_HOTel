#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jeu.h" 

/*(0-pas de collision   1 collision)*/
int Collision_Bounding_Box (SDL_Rect rec1 ,SDL_Rect position_obstacle) 
{

	int colli =1 ; 
struct rect_collision  rect1,rect2 ; 

rect1.x=rec1.x ;
rect1.y=rec1.y ;

rect2.position.x=position_obstacle.x ;
rect2.position.y=position_obstacle.y ;
 

rect1.hauteur =0; 
rect1.largeur =0; 

rect2.hauteur=position_obstacle.h+10; 
rect2.largeur=position_obstacle.w +10; 

if ((rect1.position.y >= rect1.hauteur + rect2.position.y)  ||   (rect1.position.x >= rect1.largeur +rect2.position.x) ||   (rect1.position.y + rect1.hauteur <= rect2.position.y) || (rect1.position.x + rect1.largeur <= rect2.position.x)   )
{
	colli=0 ; 
}

return colli ; 

}


         
