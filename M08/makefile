CC = g++ 
CFLAGS = -c -g -Wall -std=c++14
EXENAME = M08

default: main.o String.o 
	$(CC) -g  main.o String.o -o $(EXENAME)

main.o: main.cpp String.h
	$(CC) $(CFLAGS) main.cpp 

other.o: String.cpp String.h
	$(CC) $(CFLAGS) String.cpp 

clean: 
	rm *.o *.txt $(EXENAME)

run:
	./$(EXENAME)