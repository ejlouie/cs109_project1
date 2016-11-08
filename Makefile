#Makefile

GCC= g++
OBJ = o

all: MIS clean

MIS: main.$(OBJ) Parser.$(OBJ) Var.$(OBJ) Instructions.$(OBJ) Math.$(OBJ)
	$(GCC) $^ -o $@

clean:
	rm *.o
