#include <iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;
const int MAX_ELEMENTS = MAX_ROWS * MAX_COLS;

// Function to take user input for matrix dimensions
void userInputDimensions(int& rows, int& cols) {
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
}

// Function to take user input for matrix elements
void userInputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to sort matrix column-wise using selection sort
void sortMatrixColumnWise(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows - 1; ++i) {
            for (int k = i + 1; k < rows; ++k) {
                if (matrix[i][j] > matrix[k][j]) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            }
        }
    }
}

// Function to perform M-way merge manually
void mWayMerge(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int linearArray[MAX_ELEMENTS]) {
    int index = 0;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            linearArray[index++] = matrix[i][j];
        }
    }

    // Sort linear array using selection sort
    for (int i = 0; i < rows * cols - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < rows * cols; ++j) {
            if (linearArray[j] < linearArray[minIndex]) {
                minIndex = j;
            }
        }
        int temp = linearArray[i];
        linearArray[i] = linearArray[minIndex];
        linearArray[minIndex] = temp;
    }
}

int main() {
    int rows, cols;
    userInputDimensions(rows, cols);

    int matrix[MAX_ROWS][MAX_COLS];
    userInputMatrix(matrix, rows, cols);

    sortMatrixColumnWise(matrix, rows, cols);

    int linearArray[MAX_ELEMENTS];
    mWayMerge(matrix, rows, cols, linearArray);

    // Display sorted matrix
    cout << "Sorted Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Display linear array after merging
    cout << "Linear Array after M-way merge:" << endl;
    for (int i = 0; i < rows * cols; ++i) {
        cout << linearArray[i] << " ";
    }
    cout << endl;

    return 0;
}
