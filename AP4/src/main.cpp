#include <iostream>
#include <vector>

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
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrixA = {{1, 2}, {3, 4}};
    vector<vector<int>> matrixB = {{5, 6}, {7, 8}};

    vector<vector<int>> result = multiplyMatrices(matrixA, matrixB);

    cout << "Matrix A:" << endl;
    for (const auto& row : matrixA) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Matrix B:" << endl;
    for (const auto& row : matrixB) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Matrix resultante:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}