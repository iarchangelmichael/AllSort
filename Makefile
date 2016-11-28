CC=gcc
CXX=g++
RM=rm -f
SOURCEAllSort.cpp
CXXFLAGS= ${HLFLAGS} -std=c++11

all: $(SOURCE)
	$(CXX) $(SOURCE) $(CXXFLAGS) -o allsort

clean:
	rm ./allsort