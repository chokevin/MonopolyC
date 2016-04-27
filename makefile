CCC = g++
CCFLAGS = -ansi

driver1: driver1.o player.o game.o property.o
	$(CCC) -o driver1 driver1.o player.o game.o property.o

driver1.o:

player.o: player.h

property.o: property.h

game.o: game.h player.h property.h 

clean:
	rm -f *.o

real_clean: clean
	rm -f driver1
