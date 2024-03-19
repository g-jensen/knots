SFML_LIB=-lsfml-graphics -lsfml-window -lsfml-system

run: clean link
	./main

clean: 
	rm -f *.o
	rm -f main

link: compile
	g++ *.o -o main ${SFML_LIB}

compile:
	g++ -c -g main.cpp
	g++ -c -g src/*.cpp