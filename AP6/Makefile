CC=g++
CFLAGS= -Wall -g
TARGET= ./bin/pa6.out
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

# Lista de arquivos-fonte
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Lista de objetos
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

all: ${TARGET}

${TARGET}: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${TARGET}

${OBJ_DIR}/TipoItem.o: ${INCLUDE_DIR}/TipoItem.hpp ${SRC_DIR}/TipoItem.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/TipoItem.cpp -o $@

${OBJ_DIR}/TipoCelula.o: ${INCLUDE_DIR}/TipoCelula.hpp ${SRC_DIR}/TipoCelula.cpp ${OBJ_DIR}/TipoItem.o
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/TipoCelula.cpp -o $@

${OBJ_DIR}/ListaEncadeada.o: ${INCLUDE_DIR}/ListaEncadeada.hpp ${SRC_DIR}/ListaEncadeada.cpp ${OBJ_DIR}/TipoCelula.o
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/ListaEncadeada.cpp -o $@

${OBJ_DIR}/ListaAdjacencia.o: ${INCLUDE_DIR}/ListaAdjacencia.hpp ${SRC_DIR}/ListaAdjacencia.cpp ${OBJ_DIR}/ListaEncadeada.o ${OBJ_DIR}/TipoCelula.o ${OBJ_DIR}/TipoItem.o
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/ListaAdjacencia.cpp -o $@

${OBJ_DIR}/graph.o: ${INCLUDE_DIR}/graph.hpp ${SRC_DIR}/graph.cpp ${OBJ_DIR}/ListaAdjacencia.o
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/graph.cpp -o $@

${OBJ_DIR}/main.o: ${SRC_DIR}/main.cpp ${OBJ_DIR}/graph.o
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o $@

run: all
	${TARGET}

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}
