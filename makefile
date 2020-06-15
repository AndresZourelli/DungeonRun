CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


OBJS =  main.o checkInput.o chest.o deadend.o empty_room.o exit.o game.o inventory.o locked_door.o monster.o person.o space.o starting_room.o

SRCS = main.cpp checkInput.cpp chest.cpp deadend.cpp empty_room.cpp exit.cpp game.cpp inventory.cpp locked_door.cpp monster.cpp person.cpp space.cpp starting_room.cpp
 
HEADERS = checkInput.hpp chest.hpp deadend.hpp empty_room.hpp exit.hpp game.hpp inventory.hpp locked_door.hpp monster.hpp person.hpp space.hpp starting_room.hpp

OTHER = makefile Reflection.pdf

main: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main

zip:
	zip -D FinalProject_Zourelli_Fabian_Andres ${HEADERS} ${SRCS} ${OTHER}
