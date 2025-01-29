#include <iostream>
using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void multiplyMatrices(int **mat1, int **mat2, int **result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int r1 = 2, c1 = 3, c2 = 2;
    
    // Allocate matrices
    int** mat1 = allocateMatrix(r1, c1);
    int** mat2 = allocateMatrix(c1, c2);
    int** result = allocateMatrix(r1, c2);

    // Input matrix 1
    cout << "Enter matrix 1 elements:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> mat1[i][j];
        }
    }

    // Input matrix 2
    cout << "Enter matrix 2 elements:" << endl;
    for (int i = 0; i < c1; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> mat2[i][j];
        }
    }

    // Multiply matrices
    multiplyMatrices(mat1, mat2, result, r1, c1, c2);

    // Print the result matrix
    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    freeMatrix(mat1, r1);
    freeMatrix(mat2, c1);
    freeMatrix(result, r1);

    return 0;
}


/*
int** allocateMatrix(int rows, int cols) {
     int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
   
}

void multiplyMatrices(int **mat1, int **mat2, int **result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

}

void freeMatrix(int **matrix, int rows) {
     for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

}

*/