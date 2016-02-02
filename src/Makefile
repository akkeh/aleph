#CC-compiler:
CC=g++
CFLAGS = -Wall -lao -ldl -lm

OBJ = main.o singl.o atime.o 
all: main 

main: ${OBJ}
	${CC} -o $@ ${CFLAGS} ${OBJ}

.cpp.p:
	${CC} -c $< ${CFlAGS}
