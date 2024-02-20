CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
all: starwars.out
starwars.out: main.o game.o spaceship.o enemy.o bullet.o object.o rsdl.o
	g++ *.o $(CCFLAGS) -o starwars.out

main.o: main.cpp game.hpp
	g++ -c main.cpp -o main.o

game.o: game.cpp game.hpp spaceship.hpp 
	g++ -c game.cpp -o game.o

spaceship.o: spaceship.cpp spaceship.hpp enemy.hpp object.hpp
	g++ -c spaceship.cpp -o spaceship.o
	
rsdl.o: rsdl.cpp rsdl.hpp 
	g++ -c rsdl.cpp -o rsdl.o

bullet.o: bullet.cpp bullet.hpp rsdl.hpp define.hpp
	g++ -c bullet.cpp -o bullet.o

object.o: object.cpp object.hpp  rsdl.hpp define.hpp
	g++ -c object.cpp -o object.o

enemy.o: enemy.cpp enemy.hpp bullet.hpp  object.hpp
	g++ -c enemy.cpp -o enemy.o