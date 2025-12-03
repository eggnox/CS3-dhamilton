#compiler name
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

PROGRAM  = huffman
OBJS     = main.o Huffman.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

main.o: main.cpp Huffman.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Huffman.o: Huffman.cpp huffman.h
	$(CXX) $(CXXFLAGS) -c huffman.cpp

clean:
	rm -f $(PROGRAM) $(OBJS)
