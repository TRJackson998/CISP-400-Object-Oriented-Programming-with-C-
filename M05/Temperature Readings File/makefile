CC = g++ 
CFLAGS = -c -g -Wall -std=c++14
EXENAME = Temperatures

default: main.o Temperatures.o 
	$(CC) -g  main.o Temperatures.o -o $(EXENAME)

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

Temperatures.o: Temperatures.cpp
	$(CC) $(CFLAGS) Temperatures.cpp

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)