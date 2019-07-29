all: main bTreeTest

clean:
	rm main bTreeTest

main: bTree.h bTree.c parse.c main.c help.h help.c
	gcc -Wall -ansi -pedantic -g -o main bTree.c parse.c help.c main.c -lm

bTreeTest: bTree.h bTree.c bTreeTest.c
	gcc -Wall -ansi -pedantic -g -o bTreeTest bTree.c bTreeTest.c -lm

