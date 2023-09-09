CC = g++ 
CFLAGS = -c -g -Wall -std=c++14
EXENAME = M05

default: main.o Topograph.o 
	$(CC) -g  main.o Topograph.o Bmp.o -o $(EXENAME)

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

Topograph.o: Topograph.cpp Bmp.cpp
	$(CC) $(CFLAGS) Topograph.cpp Bmp.cpp
	
Bmp.o: Bmp.cpp
	$(CC) $(CFLAGS) Bmp.cpp

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)