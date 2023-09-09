CC = g++
CFLAGS = -c -Wall -std=c++14
EXENAME = executable

default: main.o
	$(CC) main.o -o $(EXENAME)

main.o: main.cpp grade.h
	$(CC) $(CFLAGS) main.cpp


clean:
	rm *.o $(EXENAME)

run:
	./$(EXENAME)
