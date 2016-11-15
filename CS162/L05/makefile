all:
	g++ Ant.cpp Critter.cpp Doodlebug.cpp Grid.cpp main.cpp -o critter

d:
	g++ Ant.cpp Critter.cpp Doodlebug.cpp Grid.cpp main.cpp -g -o critter_debug

debug:
	valgrind --leak-check=yes --read-var-info=yes ./critter_debug

clean:
	rm -rf *.dSYM
	-rm $(objects) critter critter_debug
