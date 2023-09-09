CC = g++ 
CFLAGS = -c -g -Wall -std=c++14
EXENAME = M04

default: main.o Matrices.o 
	$(CC) -g  main.o Matrices.o -o $(EXENAME)

main.o: main.cpp Matrices.h
	$(CC) $(CFLAGS) main.cpp 

other.o: Matrices.cpp Matrices.h
	$(CC) $(CFLAGS) Matrices.cpp 

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)