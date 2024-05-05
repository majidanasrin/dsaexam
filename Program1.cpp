#include <iostream>
using namespace std;

class matrix {
    int **inputmatrix; 
    int rows;
    int cols;

    //swap function
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    } 

public:
    
    //constructor
    matrix(int r, int c) {
        rows = r;
        cols = c;
        inputmatrix = new int*[rows]; 
        for (int i = 0; i < rows; i++) {
            inputmatrix[i] = new int[cols]; 
        }
    }

    //destructor
    ~matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] inputmatrix[i];
        }
        delete[] inputmatrix;
    }
    
    //getting input from the user
    void input() {
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> inputmatrix[i][j];
            }
        }
    }

    //sort columnwise
    void sortColumnwise(){
        for(int col = 0; col < cols; col++){
            for(int i = 0; i < rows - 1; ++i){
                for(int j = 0; j < rows - i -1; ++j){
                    if(inputmatrix[j][col] > inputmatrix[j + 1][col]){
                        swap(inputmatrix[j][col], inputmatrix[j+1][col]);
                    }
                }
            }
        }
    }

    int* mWaymerge(){
        int* mergedArray = new int [rows * cols];
        int index = 0;
        for (int col = 0; col < cols; col++){
            for(int row = 0; row < rows; row++){
                mergedArray[index++] = inputmatrix[row][col];
            }
        }

        for (int i = 0; i < rows * cols - 1; ++i){
            for(int j = 0; j < rows * cols - i - 1; ++j){
                if (mergedArray[j] > mergedArray[j + 1]){
                    swap(mergedArray[j], mergedArray[j + 1]);
                }
            }
        }
        return mergedArray;
    }
};

int main() {
    int row, col;

    cout << "Enter the number of rows: " << endl;
    cin >> row;
    cout << "Enter the number of cols: " << endl;
    cin >> col;

    matrix m1(row, col);
    m1.input();
    m1.sortColumnwise();
    int * linearArray = m1.mWaymerge();

    cout<<"Linear array: "<<endl;
    for(int i = 0; i < row * col; i++){
        cout<<linearArray[i] <<" ";
    }
    cout <<endl;

    delete[] linearArray;

    return 0;
}
