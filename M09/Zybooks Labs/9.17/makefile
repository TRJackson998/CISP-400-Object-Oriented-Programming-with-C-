CC = g++
CFLAGS = -c -Wall -std=c++14
EXENAME = executable

default: main.o
	$(CC) main.o -o $(EXENAME)

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o *.txt $(EXENAME)

run:
	./$(EXENAME)
