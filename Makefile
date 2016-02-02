
CXX=g++
CXX_FLAGS=-Wall -g

all: stupid


stupid: main.o testGdb.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

main.o: main.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $^

testGdb.o: testGdb.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $^
