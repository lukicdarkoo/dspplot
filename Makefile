SRC = $(wildcard src/*.c)
LIB = -lm

all: 
	gcc $(SRC) -o bin/dspplot $(LIB) 
