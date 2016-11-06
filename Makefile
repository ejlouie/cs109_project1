#Makefile

GCC= g++
OBJ = o

all: MIS clean

MIS: main.$(OBJ)
	$(GCC) $^ -o $@

clean:
	rm *.o
