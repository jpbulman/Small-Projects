all: PA5

# Set CFLAGS to allow Debug and issue all warnings.
CFLAGS = -g -Wall

PA5: PA5.o Ant.o Board.o Doodlebug.o Organism.o
	g++ $(CFLAGS) PA5.o Ant.o Board.o Doodlebug.o Organism.o -o PA5

PA5.o: PA5.cpp Ant.h Board.h Doodlebug.h Organism.h
	g++ $(CFLAGS) -c PA5.cpp

Ant.o: Ant.cpp Organism.h
	g++ $(CFLAGS) -c Ant.cpp
	
Doodlebug.o: Doodlebug.cpp Doodlebug.h Organism.h
	g++ $(CFLAGS) -c Doodlebug.cpp
	
Board.o: Board.cpp Board.h Organism.h Ant.h Doodlebug.h
	g++ $(CFLAGS) -c Board.cpp
	
Organism.o: Organism.cpp Organism.h
	g++ $(CFLAGS) -c Organism.cpp

clean:
	rm -f Ant.o Board.o Doodlebug.o Organism.o PA5.o PA5
	rm -f -r html latex

docs:
	doxygen
	# Following lines are only needed if we want to access doc pages
	#   using a Web server.
	#chmod go+r html/*
	#cp html/* ~/public_html/cs2303assig3