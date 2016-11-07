# Makefile for Assignment2
#
# Created by Sam Gabbard: slgabbar@ucsc.edu
#
# Created: October 18th 2016
#
# To build project 1, type "make Class"
# To build project 2, type "make Inventory"
# To build project 3, type "make Heap"
# To build all at once type "make"
# "make clean" will rm .o files

# ===================================================================

CC     = g++
CFLAGS = -std=c++11
OBJS1 = sub_div.o add_mul.o Insns_Parser.o out.o jmp.o Label.o main.o jmpz.o jmpgle.o sleep.o
HEADER = Instructions.h sub_div.h add_mul.h Insns_Parser.h out.h common.h jmp.h jmpz.h jmpgle.h Label.h sleep.h

vm: ${OBJS1}
	${CC} ${CFLAGS} ${OBJS1} -o vm

sub_div.o:	sub_div.cpp  sub_div.h
	${CC} -c ${CFLAGS}  sub_div.cpp

add_mul.o:	add_mul.cpp  add_mul.h
	${CC} -c ${CFLAGS} add_mul.cpp

Insns_Parser.o: Insns_Parser.cpp Insns_Parser.h
	${CC} -c ${CFLAGS} Insns_Parser.cpp

out.o: out.cpp out.h
	${CC} -c ${CFLAGS} out.cpp

Label.o: Label.cpp Label.h
	${CC} -c ${CFLAGS} Label.cpp

jmp.o: jmp.cpp jmp.h
	${CC} -c ${CFLAGS} jmp.cpp

jmpz.o: jmpz.cpp jmpz.h
	${CC} -c ${CFLAGS} jmpz.cpp

jmpgle.o: jmpgle.cpp jmpgle.h
	${CC} -c ${CFLAGS} jmpgle.cpp

sleep.o: sleep.cpp sleep.h
	${CC} -c ${CFLAGS} sleep.cpp

main.o: main.cpp ${HEADER}
	${CC} -c ${CFLAGS} main.cpp

clean:
	rm ${OBJS1}

fuck:
	rm Instructions.h~ sub_div.h~ add_mul.h~ Parser.h~ common.h~ sub_div.cpp~ add_mul.cpp~ Parser.cpp~ main.cpp~ Makefile~ hello.txt~ out.cpp~ out.h~ Label.h~ Label.cpp~

