#Makefile

GCC= g++
OBJ = o

all: Prob1 clean

Prob1: main.$(OBJ) ParseException.$(OBJ)
	$(GCC) $^ -o $@

clean:
	rm *.o
