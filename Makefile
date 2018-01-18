OBJECTS = src/main.cpp
EXEC = bin/tabrestore
CXXFLAGS = -Wall
CXX = g++

all: $(OBJECTS)
	$(CXX) -std=c++14 $(CXXFLAGS) -o $(EXEC) $(OBJECTS)
	