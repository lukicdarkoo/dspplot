LIB_SRC = $(wildcard src/lib/*.c)
SRC = $(wildcard src/*.c)
LIB = -lm

all: 
	gcc $(SRC) $(LIB_SRC) -o dspplot $(LIB) 
	./dspplot
