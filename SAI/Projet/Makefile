all : Projet

Projet : main.o k-arbre.o cube.o
	gcc -Wall main.o k-arbre.o cube.o -lm -o Projet -lglut -lGLU -lGL

main.o : main.c k-arbre.h cube.h
	gcc -Wall main.c -c -lglut -lGLU -lGL

k-arbre.o : k-arbre.c k-arbre.h cube.h
	gcc -Wall k-arbre.c -c -lglut -lGLU -lGL

cube.o : cube.c cube.h
	gcc -Wall cube.c -c

clean :
	rm Projet main.o k-arbre.o cube.o