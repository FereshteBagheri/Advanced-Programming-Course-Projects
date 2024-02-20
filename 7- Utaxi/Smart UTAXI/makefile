CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
all: utaxi.out
utaxi.out: main.o request.o command.o user.o trip.o error.o location.o functions.o
	g++ *.o $(CCFLAGS) -o utaxi.out

main.o: main.cpp request.hpp
	g++ -std=c++11 -c main.cpp -o main.o

request.o: request.cpp command.hpp  
	g++  -std=c++11 -c request.cpp -o request.o

command.o: command.cpp user.hpp
	g++  -std=c++11 -c command.cpp -o command.o
	
user.o: user.cpp error.hpp trip.hpp 
	g++  -std=c++11 -c user.cpp -o user.o

trip.o: trip.cpp functions.hpp  
	g++  -std=c++11 -c trip.cpp -o trip.o

error.o: error.cpp const.hpp 
	g++  -std=c++11 -c error.cpp -o error.o

location.o: location.cpp const.hpp 
	g++  -std=c++11 -c location.cpp -o location.o

functions.o: functions.cpp location.hpp 
	g++  -std=c++11 -c functions.cpp -o functions.o

clean:
	rm *.o *.out
