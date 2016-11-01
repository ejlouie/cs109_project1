#Makefile

GCC= g++
OBJ = o
EXCEPTIONS_SRC = Exceptions

all: Prob1 clean


Prob1: Decoder.cpp main.$(OBJ)
	Exceptions
	$(GCC) $^ -o $@

Exceptions: $(EXCEPTIONS_SRC)/DecodeException.$(OBJ)


clean:
	rm $(PROBLEM_1_SRC)/*.o  $(PROBLEM_2_SRC)/*.o $(PROBLEM_3_SRC)/*.o
