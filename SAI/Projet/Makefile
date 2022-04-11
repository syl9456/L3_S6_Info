all : Projet

Projet : main.o k-arbre.o cube.o formes.o
	gcc -Wall main.o k-arbre.o cube.o formes.o -lm -o Projet -lglut -lGLU -lGL

main.o : main.c k-arbre.h cube.h formes.h
	gcc -Wall main.c -c -lglut -lGLU -lGL

k-arbre.o : k-arbre.c k-arbre.h cube.h
	gcc -Wall k-arbre.c -c -lglut -lGLU -lGL

cube.o : cube.c cube.h
	gcc -Wall cube.c -c

formes.o :formes.c formes.h
	gcc -Wall formes.c -c -lglut -lGLU -lGL
	
clean :
	rm Projet main.o k-arbre.o cube.o
