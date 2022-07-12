CC=gcc
FLAGS= -Wall -Wextra
BINARIES=collatz-conjecture

collatz-conjecture: main.c
	$(CC) main.c -o $(BINARIES) $(FLAGS)
