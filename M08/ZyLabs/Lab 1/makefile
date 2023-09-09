CC = g++ 
CFLAGS = -c -g -Wall -std=c++14
EXENAME = ZyLab

default: main.o 
	$(CC) -g  main.o -o $(EXENAME)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp 

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)