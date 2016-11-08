#Makefile

GCC= g++
OBJ = o

all: MIS

MIS: main.$(OBJ) Parser.$(OBJ) Var.$(OBJ) Instructions.$(OBJ) Math.$(OBJ) Label.$(OBJ) Assign.$(OBJ) Jump.$(OBJ) Sleep.$(OBJ)
	$(GCC) $^ -o $@

clean:
	rm *.o
