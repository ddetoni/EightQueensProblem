all: main

main: main.o
	g++ main.o -o bin/main

main.o: src/main.cpp
	g++ -c src/main.cpp

clear:
	rm *.o
