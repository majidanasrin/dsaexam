#include <iostream>

using namespace std;

class MatrixProcessor {
private:
    int matrix[5][5];
public:
    MatrixProcessor() {}
    
    void setMatrix(int mat[5][5]) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                matrix[i][j] = mat[i][j];
            }
        }
    }

    void searchElement(int target) {
        bool found = false;
        int row = -1, col = -1;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (matrix[i][j] == target) {
                    found = true;
                    row = i + 1;
                    col = j + 1;
                    break;
                }
            }
            if (found) break;
        }
        if (found) {
            cout << "Element " << target << " found at position (" << row << ", " << col << ").\n";
        } else {
            cout << "Element " << target << " not found in the matrix.\n";
        }
    }

    void printSpiral() {
        int m = 5, n = 5;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int dir = 0; // 0: left to right, 1: top to bottom, 2: right to left, 3: bottom to top

        while (top <= bottom && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right; ++i)
                    cout << matrix[top][i] << " ";
                top++;
            } else if (dir == 1) {
                for (int i = top; i <= bottom; ++i)
                    cout << matrix[i][right] << " ";
                right--;
            } else if (dir == 2) {
                for (int i = right; i >= left; --i)
                    cout << matrix[bottom][i] << " ";
                bottom--;
            } else if (dir == 3) {
                for (int i = bottom; i >= top; --i)
                    cout << matrix[i][left] << " ";
                left++;
            }
            dir = (dir + 1) % 4;
        }
        cout << "\n";
    }
};

int main() {
    MatrixProcessor processor;
    
    int mat[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    processor.setMatrix(mat);

    int targetElement = 13;
    processor.searchElement(targetElement);
    processor.printSpiral();

    return 0;
}
