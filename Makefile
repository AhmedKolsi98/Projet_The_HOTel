<<<<<<< HEAD
prog:fonctions.h main.c ressource.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 
main.o.o:main.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 
										
ressource.o:ressource.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
fonctions.o:fonctions.h
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 
	
=======
jeu: main.o Afficher.o AnimationPersonnage.o collision.o Scrolling.o Enigmes.o vies_score_temps.o -lm
	gcc main.o Afficher.o AnimationPersonnage.o collision.o Scrolling.o Enigmes.o vies_score_temps.o -o jeu


main.o:main.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c main.c
Initialiser.o:Initialiser.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c Initialiser.c
Afficher.o:Afficher.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c Afficher.c
AnimationPersonnage.o:AnimationPersonnage.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c 
collision.o:collision.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lm -c collision.c
Scrolling.o:Scrolling.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c Scrolling.c
Enigmes.o:Enigmes.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c Enigmes.c
vies_score_temps.o:vies_score_temps.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c vies_score_temps.c
>>>>>>> 55d3c12087fddef46ef3c9d4231a5de5620434c3
