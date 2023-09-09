CC = g++ 
CFLAGS = -c -g -Wall -std=c++14
EXENAME = M02

default: main.o RSA.o 
	$(CC) -g  main.o RSA.o -o $(EXENAME)

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

RSA.o: RSA.cpp 
	$(CC) $(CFLAGS) RSA.cpp 

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)