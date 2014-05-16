CFLAGS=-std=gnu++11

all: main

main: main.o
	g++ $(CFLAGS) main.o -o bin/main

main.o: src/main.cpp
	g++ $(CFLAGS) -c src/main.cpp

clear:
	rm *.o
