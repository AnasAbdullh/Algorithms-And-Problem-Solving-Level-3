#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iomanip> //
#include <iostream>
#include <vector>
using namespace std;

// Function to generate a random number within a range
int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to fill a matrix with random numbers
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(1, 10); // Random numbers between 1 and 10
        }
    }
}

// Function to print the entire matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            printf(" %0*d ", 2, arr[i][j]); // Print with 2-character width
        }
        cout << "\n";
    }
}
bool CountNumberInMatrix(int Matrix1[3][3], short Cols, int Number)
{



    for  (short i = 0; i < Cols; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(Matrix1[i][j] == Number)
                return true;
        }

    }
    return false;
}

void EnterSimilarMatrixInVector (int Matrix1[3][3], int Matrix2[3][3], short Cols,vector<int> &vSimilarMatrix) {

    for (short i = 0; i < Cols; i++) {
        for (short j = 0; j < Cols; j++) {
            if(Matrix2,Cols,Matrix1[i][j])
            vSimilarMatrix.push_back(Matrix1[i][j]);

            }
    }

}
void PrintVector(vector<int> vSimilarMatrix) {

    for (const auto &element : vSimilarMatrix) {
        cout << element << " ";
    }
}

int main() {
    // Seed the random number generator to get different numbers each run
    srand((unsigned)time(NULL));

    // Declare a 3x3 matrix
    int Matrix1[3][3], Matrix2[3][3];
    vector<int> SimilarMatrix;

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    FillMatrixWithRandomNumbers(Matrix2, 3, 3);

    // Print the entire matrix
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    cout << endl;

    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);
    cout << endl;
    EnterSimilarMatrixInVector(Matrix1,Matrix2,3,SimilarMatrix);
    PrintVector(SimilarMatrix);



    return 0;
}