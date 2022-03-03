all : kArbre

kArbre : main.o k-arbre.o
	gcc -Wall main.o k-arbre.o -o kArbre

main.o : main.c k-arbre.h
	gcc -Wall main.c -c

k-arbre.o : k-arbre.c k-arbre.h
	gcc -Wall k-arbre.c -c

clean :
	rm kArbre main.o k-arbre.o