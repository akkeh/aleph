#CC-compiler:
CC=g++
CFLAGS = -Wall -lao -ldl -lm

OBJ = main.o singl.o atime.o proc.o aout.o
all: main 

main: ${OBJ}
	${CC} -o $@ ${CFLAGS} ${OBJ}

.cpp.p:
	${CC} -c $< ${CFlAGS}

lib: soLib.cpp
	${CC} -shared -fPIC -o soLib.so soLib.cpp singl.cpp atime.cpp

clean:
	rm -rf *.o
