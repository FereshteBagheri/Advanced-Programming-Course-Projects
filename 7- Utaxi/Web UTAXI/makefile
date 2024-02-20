
all: utaxi.out
utaxi.out: main.o utaxi.o  user.o trip.o error.o location.o functions.o handlers.o template_parsetr.o response.o request.o utilities.o server.o route.o
	g++ *.o $(CCFLAGS) -o utaxi.out

main.o: main.cpp utaxi.hpp server/server.hpp handlers.hpp
	g++ -std=c++11 -c main.cpp -o main.o

utaxi.o: utaxi.cpp
	g++  -std=c++11 -c utaxi.cpp -o utaxi.o

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

handlers.o: handlers.cpp utaxi.hpp server/server.hpp
	g++  -std=c++11 -c handlers.cpp -o handlers.o

template_parsetr.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	g++ --std=c++11 -c utils/template_parser.cpp -o template_parser.o

response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	g++ --std=c++11 -c utils/response.cpp -o response.o

request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	g++ --std=c++11 -c utils/request.cpp -o request.o

utilities.o: utils/utilities.cpp utils/utilities.hpp
	g++ --std=c++11 -c utils/utilities.cpp -o utilities.o

server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	g++ --std=c++11 -c server/server.cpp -o server.o

route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	g++ --std=c++11 -c server/route.cpp -o route.o
	
clean:
	rm *.o *.out


