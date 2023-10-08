#include <iostream>
#include <vector>
#include "memlog.h" 

using namespace std;

// Função para multiplicar duas matrizes
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    
    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                ESCREVEMEMLOG((long int) (&A), sizeof(double), 0);
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

char lognome[1000];

int main() {

    lognome[0] = 'a';
    lognome[1] = 'b';
    lognome[2] = 'c';
    lognome[3] = 'd';

    iniciaMemLog(lognome);
    ativaMemLog();

    defineFaseMemLog(0); //criação das matrizes
    vector<vector<int>> matrixA = {{1, 2}, {3, 4}};
    vector<vector<int>> matrixB = {{5, 6}, {7, 8}};

    defineFaseMemLog(1); //multiplicação das matrizes
    vector<vector<int>> result = multiplyMatrices(matrixA, matrixB);

    defineFaseMemLog(2); //impressão matriz A
    cout << "Matrix A:" << endl;
    for (const auto& row : matrixA) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    defineFaseMemLog(3); //impressão matriz B
    cout << "Matrix B:" << endl;
    for (const auto& row : matrixB) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    defineFaseMemLog(4); //impressão matriz resultante
    cout << "Matrix resultante:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            LEMEMLOG((long int) (&result), sizeof(double), 1);
            cout << num << " ";
        }
        cout << endl;
    }

    desativaMemLog();
    finalizaMemLog();

    return 0;
}