CC=g++
FLAG=-Wall -std=c++17
EXE=css342_quiz_swap_array

all: $(EXE)

main.o: main.cpp util.hpp
	$(CC) $(FLAG) -c main.cpp -o main.o

$(EXE): main.o
	$(CC) $(FLAG) main.o -o $(EXE)

clean:
	rm *.x *.o $(EXE)
