prog:main.o collision.o 

	gcc main.o voiture.o jeu.o background.o bullet.o text.o -o prog -lSDL -lSDL_ttf -lm -g
main.o:main.c
	gcc -c main.c -g
collision.o:collision.c
	gcc -c collision.c -g

mrproper:clean
	rm -f prog
