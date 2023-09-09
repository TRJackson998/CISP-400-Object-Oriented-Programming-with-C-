CC = g++ 
CFLAGS = -c -g -Wall -std=c++14
EXENAME = ZyLab

default: Blank.o 
	$(CC) -g  Blank.o -o $(EXENAME)

Blank.o: Blank.cpp Vector.h
	$(CC) $(CFLAGS) Blank.cpp 

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)