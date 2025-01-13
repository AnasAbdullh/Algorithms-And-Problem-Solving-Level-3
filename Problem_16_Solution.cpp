#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to print the matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            printf(" %0*d ", 2, arr[i][j]); // Print with 2-character width
        }
        cout << "\n";
    }
}

// Function to count occurrences of a specific number in the matrix
int AreCountInMatrices(int Matrix1[3][3], short Cols, int Number) {
    short count = 0;
    for (short i = 0; i < Cols; i++) {
        for (short j = 0; j < Cols; j++) {
            if (Matrix1[i][j] == Number)
                count++;
        }
    }
    return count;
}

// Function to check if the matrix is sparse
bool IsSparseMatrix(int Matrix1[3][3], short Cols, short Rows) {
    short MatrixSize = Cols * Rows;
    // Use the AreCountInMatrices function to count zeros in the matrix
    return (AreCountInMatrices(Matrix1, Cols, 0) >= ceil((float)MatrixSize / 2));
}

int main() {
    // Declare a 3x3 matrix
    int Matrix1[3][3] = {{0, 0, 12}, {9, 9, 1}, {0, 0, 9}};

    // Print the entire matrix
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    cout << endl;
    

    // Check if the matrix is sparse
    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "\nYes: It is Sparse\n";
    else
        cout << "\nNo: It's NOT Sparse\n";

    return 0;
}