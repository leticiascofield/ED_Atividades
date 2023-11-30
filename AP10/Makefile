CXX = g++
CXXFLAGS = -Wall -std=c++11
INC_DIR = -I./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin

all: $(BIN_DIR)/pa10.out

run: ./bin/pa10.out

$(BIN_DIR)/pa10.out: $(OBJ_DIR)/main.o $(OBJ_DIR)/Set.o
	$(CXX) $(CXXFLAGS) $(INC_DIR) $(OBJ_DIR)/main.o $(OBJ_DIR)/Set.o -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/Set.o: $(SRC_DIR)/Set.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/pa10.out
