# I am a comment, and I want to say that the variable CC will be # the compiler to use

CC = g++

# Hey!, I am comment number 2.  I want to say that CFLAGS will be the # options I'll pass to the compiler.

CFLAGS = -c -Wall -std=c++14
EXENAME = hello

default: main.o factorial.o hello.o
	$(CC) main.o hello.o factorial.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
factorial.o: factorial.cpp
	$(CC) $(CFLAGS) factorial.cpp
hello.o: hello.cpp
	$(CC) $(CFLAGS) hello.cpp
clean:
	rm *.o $(EXENAME)
run:
	./$(EXENAME)
