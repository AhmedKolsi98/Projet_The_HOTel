prog:fonctions.h main.c ressource.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 
main.o.o:main.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 
										
ressource.o:ressource.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
fonctions.o:fonctions.h
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 
	
