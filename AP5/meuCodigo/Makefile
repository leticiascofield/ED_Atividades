CC=g++
CFLAGS=-std=c++11 -Wall

TARGET= ./bin/main
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/memlog.o ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o ${TARGET}

${OBJ_DIR}/memlog.o: ${INCLUDE_DIR}/msgassert.h ${INCLUDE_DIR}/memlog.h ${SRC_DIR}/memlog.c
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/memlog.c -o ${OBJ_DIR}/memlog.o

${OBJ_DIR}/main.o: ${INCLUDE_DIR}/msgassert.h ${INCLUDE_DIR}/memlog.h ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

run: all
	${TARGET}

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}