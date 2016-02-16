CXX = clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES=prog2

all: ${BINARIES}

prog2: HuffmanEncoding.o MinHeap.o Main.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o