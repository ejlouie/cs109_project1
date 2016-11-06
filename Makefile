#Makefile

GCC= g++
OBJ = o

all: MIS clean

MIS: main.$(OBJ) ParseException.$(OBJ)
	$(GCC) $^ -o $@

clean:
	rm *.o
