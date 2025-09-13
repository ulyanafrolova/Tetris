CXX = g++
CXXFLAGS = -std=c++17 -Wall -I/opt/homebrew/include  
LDFLAGS = -L/opt/homebrew/lib -lraylib \
          -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

.PHONY: all clean

all: tetris

tetris: main.o grid.o blocks.o colors.o block.o game.o
	${CXX} $^ -o $@ ${LDFLAGS}

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

grid.o: grid.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

blocks.o: blocks.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

colors.o: colors.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

block.o: block.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

game.o: game.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	rm -f *.o tetris