CC=g++
FLAG=-Wall -std=c++17
EXE=css342_quiz_weird_sort

all: $(EXE)

weird_sort.o: weird_sort.cpp weird_sort.h
	$(CC) $(FLAG) -c weird_sort.cpp -o weird_sort.o

$(EXE): weird_sort.o
	$(CC) $(FLAG) weird_sort.o -o $(EXE)

clean:
	rm *.o $(EXE)




