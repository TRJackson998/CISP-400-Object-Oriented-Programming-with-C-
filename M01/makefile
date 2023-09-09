COMPILER = g++
DEBUG = -g
C_FLAGS = -c -Wall -std=c++14
EXENAME = M01

default: M01.o
	$(COMPILER) $(DEBUG) M01.o -o $(EXENAME)
main.o: M01.cpp
	$(COMPILER) $(DEBUG) $(C_FLAGS) M01.cpp
clean:
	rm *.o $(EXENAME)
run:
	./$(EXENAME)
