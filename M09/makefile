CC = g++
CFLAGS = -c -Wall -std=c++14
EXENAME = M09

default: main.o
	$(CC) main.o -o $(EXENAME)

main.o: main.cpp HashTable.h
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o $(EXENAME)

run:
	./$(EXENAME)
