CFLAGS= -W  -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 


all:   main.o
	g++  main.o   -o hotel.x $(CFLAGS)


main.o: main.c
	g++ -c main.c -o main.o



clean:
	rm -rf *.o
