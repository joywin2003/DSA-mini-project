CC = gcc
FLAGS = -Wall -g

all: helpers main

main: main.c
	$(CC) $(FLAGS) main.c helpers.o -o main

helpers:
	$(CC) $(FLAGS) -c helpers.c

clean:
	rm main *.o