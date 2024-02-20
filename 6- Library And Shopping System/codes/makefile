CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
all: library.out
library.out: main.o library.o document.o member.o
	g++ *.o $(CCFLAGS) -o library.out

main.o: main.cpp library.hpp
	g++ -c main.cpp -o main.o

library.o: library.cpp document.hpp member.hpp 
	g++ -c library.cpp -o library.o

document.o: document.cpp define.hpp
	g++ -c document.cpp -o document.o
	
member.o: member.cpp document.hpp 
	g++ -c member.cpp -o member.o
