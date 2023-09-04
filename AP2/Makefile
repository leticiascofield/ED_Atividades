all: fatorialIterativo fatorialRecursivo fibonacciIterativo fibonacciRecursivo

fatorialIterativo:
	g++ -o bin/fatorialIterativo -pg src/fatorialIterativo.cpp 

fatorialRecursivo:
	g++ -o bin/fatorialRecursivo -pg src/fatorialRecursivo.cpp

fibonacciIterativo:
	g++ -o bin/fibonacciIterativo -pg src/fibonacciIterativo.cpp 

fibonacciRecursivo:
	g++ -o bin/fibonacciRecursivo -pg src/fibonacciRecursivo.cpp

run: all
	./bin/fatorialIterativo 15
	./bin/fatorialRecursivo 15
	./bin/fibonacciIterativo 15
	./bin/fibonacciRecursivo 15

clean:
	rm -f bin/**