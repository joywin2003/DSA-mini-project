CC = gcc
FLAGS = -Wall -g

all: main

main: main.c
	$(CC) $(FLAGS) main.c structures.o -o main

struct:
	$(CC) $(FLAGS) -c structures.c

clean:
	rm main *.o