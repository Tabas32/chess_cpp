CXXFLAGS=-std=c++11

all: main.o Chess_game.o
	${CXX} ${CXXFLAGS} ./build/main.o ./build/Chess_game.o -o game.out

main.o: ./src/main.cpp
	${CXX} ${CXXFLAGS} -c ./src/main.cpp -o ./build/main.o

Chess_game.o: ./src/gameCore/Chess_game.cpp
	${CXX} ${CXXFLAGS} -c ./src/gameCore/Chess_game.cpp -o ./build/Chess_game.o
