CC = g++ 
CFLAGS = -c -g -Wall -std=c++14
EXENAME = test

default: main.o Person.o 
	$(CC) -g  main.o Person.o -o $(EXENAME)

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

Person.o: Person.cpp 
	$(CC) $(CFLAGS) Person.cpp 

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)