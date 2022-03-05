all : kArbre

kArbre : main.o k-arbre.o cube.o
	gcc -Wall main.o k-arbre.o cube.o -lm -o kArbre

main.o : main.c k-arbre.h cube.h
	gcc -Wall main.c -c

k-arbre.o : k-arbre.c k-arbre.h cube.h
	gcc -Wall k-arbre.c -c

cube.o : cube.c cube.h
	gcc -Wall cube.c -c

clean :
	rm kArbre main.o k-arbre.o cube.o