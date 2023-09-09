CC = g++ 
CFLAGS = -c -g -Wall -std=c++14
EXENAME = Points

default: main.o Points.o 
	$(CC) -g  main.o Points.o -o $(EXENAME)

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

Points.o: Points.cpp
	$(CC) $(CFLAGS) Points.cpp

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)