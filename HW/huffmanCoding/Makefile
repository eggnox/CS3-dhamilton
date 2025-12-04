#compiler name
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

PROGRAM  = huffman
OBJS     = main.o huffman.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

main.o: main.cpp huffman.h
	$(CXX) $(CXXFLAGS) -c main.cpp

huffman.o: huffman.cpp huffman.h
	$(CXX) $(CXXFLAGS) -c huffman.cpp

clean:
	rm -f $(PROGRAM) $(OBJS)
