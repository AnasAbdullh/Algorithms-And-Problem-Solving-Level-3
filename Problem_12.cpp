#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iomanip> // For setw()
using namespace std;

// Function to generate a random number within a range
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to fill a matrix with random numbers
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10); // Random numbers between 1 and 10
        }
    }
}

// Function to print the entire matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf(" %0*d ", 2, arr[i][j]); // Print with 2-character width
        }
        cout << "\n";
    }
}

int SumMatrix(int arr[3][3],short Rows, short Cols)
{

    int Sum =0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Sum += arr[i][j];
        }

    }
    return Sum;

}
bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3],short Rows, short Cols) {

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(Matrix1[i][j]!= Matrix2[i][j]) {
                return false;

            }
        }
    }
    return true;

}

// Function to print the middle row of the matrix


int main()
{
    // Seed the random number generator to get different numbers each run
    srand((unsigned)time(NULL));

    // Declare a 3x3 matrix
    int Matrix1[3][3];
    int Matrix2[3][3];

    // Fill the matrix with random numbers
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    FillMatrixWithRandomNumbers(Matrix2, 3, 3);


    // Print the entire matrix
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);

    if (AreTypicalMatrices(Matrix1, Matrix2,3,3))
        cout << "\nYES: both martices are Typcial.";
    else
        cout << "\nNo: martices are NOT  Typcial.";



    return 0;
}