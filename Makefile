CC=gcc
CXX=g++
RM=rm -f
SOURCE=AllSort.cpp
CXXFLAGS= ${HLFLAGS} -std=c++11

all: $(SOURCE)
	$(CXX) $(SOURCE) $(CXXFLAGS) -o allsort

clean:
	rm ./allsort