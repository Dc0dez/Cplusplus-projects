CC=g++
FLAG=-Wall -std=c++17
EXE=memory_sim_test

all: $(EXE)

memory_sim.o: memory_sim.cpp memory_sim.hpp
	$(CC) $(FLAG) -c memory_sim.cpp -o memory_sim.o

test.o: test.cpp test.hpp
	$(CC) $(FLAG) -c test.cpp -o test.o

$(EXE): memory_sim.o test.o
	$(CC) $(FLAG) memory_sim.o test.o -o $(EXE)

clean:
	rm *.x *.o $(EXE)
