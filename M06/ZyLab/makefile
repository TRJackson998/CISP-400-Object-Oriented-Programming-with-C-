CC = g++ 
CFLAGS = -c -g -Wall -std=c++14
EXENAME = a.out

default: main.o B.h
	$(CC) -g  main.o B.h -o $(EXENAME)

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)