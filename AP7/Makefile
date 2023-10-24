CXX = g++
CXXFLAGS = -Wall -std=c++11 -I./include

all: pa7.out

pa7.out: src/main.cpp src/heap.cpp
	$(CXX) $(CXXFLAGS) $^ -o bin/pa7.out

clean:
	rm -f obj/* bin/pa7.out
