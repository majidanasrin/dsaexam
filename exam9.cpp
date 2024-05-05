#include <iostream>

using namespace std;

// Structure to represent a non-zero element in the matrix
struct Element {
    int row;
    int col;
    int value;
};

// Function to convert a matrix into a sparse matrix
Element* convertToSparseMatrix(int** matrix, int rows, int cols, int& nonZeroCount) {
    nonZeroCount = 0;
    // Count the number of non-zero elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }
    // Allocate memory for sparse matrix
    Element* sparseMatrix = new Element[nonZeroCount];
    int k = 0;
    // Populate sparse matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k].row = i;
                sparseMatrix[k].col = j;
                sparseMatrix[k].value = matrix[i][j];
                k++;
            }
        }
    }
    return sparseMatrix;
}

// Function to perform matrix addition on two sparse matrices
Element* addSparseMatrices(const Element* sparseMatrix1, int nonZeroCount1, const Element* sparseMatrix2, int nonZeroCount2, int& resultCount) {
    // Merge the two sparse matrices while adding the corresponding elements
    Element* resultMatrix = new Element[nonZeroCount1 + nonZeroCount2];
    int i = 0, j = 0, k = 0;
    while (i < nonZeroCount1 && j < nonZeroCount2) {
        if (sparseMatrix1[i].row < sparseMatrix2[j].row ||
            (sparseMatrix1[i].row == sparseMatrix2[j].row && sparseMatrix1[i].col < sparseMatrix2[j].col)) {
            resultMatrix[k++] = sparseMatrix1[i++];
        } else if (sparseMatrix1[i].row > sparseMatrix2[j].row ||
                   (sparseMatrix1[i].row == sparseMatrix2[j].row && sparseMatrix1[i].col > sparseMatrix2[j].col)) {
            resultMatrix[k++] = sparseMatrix2[j++];
        } else {
            resultMatrix[k].row = sparseMatrix1[i].row;
            resultMatrix[k].col = sparseMatrix1[i].col;
            resultMatrix[k].value = sparseMatrix1[i].value + sparseMatrix2[j].value;
            k++;
            i++;
            j++;
        }
    }
    // Copy remaining elements from sparseMatrix1, if any
    while (i < nonZeroCount1) {
        resultMatrix[k++] = sparseMatrix1[i++];
    }
    // Copy remaining elements from sparseMatrix2, if any
    while (j < nonZeroCount2) {
        resultMatrix[k++] = sparseMatrix2[j++];
    }
    resultCount = k;
    return resultMatrix;
}

// Function to print a sparse matrix
void printSparseMatrix(const Element* sparseMatrix, int nonZeroCount) {
    for (int i = 0; i < nonZeroCount; ++i) {
        cout << "(" << sparseMatrix[i].row << ", " << sparseMatrix[i].col << ", " << sparseMatrix[i].value << ")" << endl;
    }
}

int main() {
    // Sample 3x3 matrix
    int rows = 3, cols = 3;
    int** matrix1 = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix1[i] = new int[cols];
    }
    matrix1[0][0] = 1; matrix1[0][1] = 2; matrix1[0][2] = 3;
    matrix1[1][0] = 4; matrix1[1][1] = 5; matrix1[1][2] = 6;
    matrix1[2][0] = 7; matrix1[2][1] = 8; matrix1[2][2] = 9;

    int nonZeroCount1;
    Element* sparseMatrix1 = convertToSparseMatrix(matrix1, rows, cols, nonZeroCount1);

    cout << "Sparse Matrix 1:" << endl;
    printSparseMatrix(sparseMatrix1, nonZeroCount1);

    // Sample 3x3 matrix
    int** matrix2 = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix2[i] = new int[cols];
    }
    matrix2[0][0] = 9; matrix2[0][1] = 8; matrix2[0][2] = 7;
    matrix2[1][0] = 6; matrix2[1][1] = 5; matrix2[1][2] = 4;
    matrix2[2][0] = 3; matrix2[2][1] = 2; matrix2[2][2] = 1;

    int nonZeroCount2;
    Element* sparseMatrix2 = convertToSparseMatrix(matrix2, rows, cols, nonZeroCount2);

    cout << "\nSparse Matrix 2:" << endl;
    printSparseMatrix(sparseMatrix2, nonZeroCount2);

    // Perform matrix addition on sparse matrices
    int resultCount;
    Element* resultMatrix = addSparseMatrices(sparseMatrix1, nonZeroCount1, sparseMatrix2, nonZeroCount2, resultCount);

    cout << "\nResultant Sparse Matrix:" << endl;
    printSparseMatrix(resultMatrix, resultCount);

    // Free memory
    delete[] sparseMatrix1;
    delete[] sparseMatrix2;
    delete[] resultMatrix;

    for (int i = 0; i < rows; ++i) {
        delete[] matrix1[i];
        delete[] matrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;

    return 0;
}