CXX = g++
CXXFLAGS = -Wall -std=c++11
INC_DIR = -I./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin

all: $(BIN_DIR)/pa8.out

$(BIN_DIR)/pa8.out: $(OBJ_DIR)/main.o $(OBJ_DIR)/heap.o $(OBJ_DIR)/unionFind.o
	$(CXX) $(CXXFLAGS) $(INC_DIR) $^ -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/heap.o: $(SRC_DIR)/heap.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/unionFind.o: $(SRC_DIR)/unionFind.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/pa8.out
