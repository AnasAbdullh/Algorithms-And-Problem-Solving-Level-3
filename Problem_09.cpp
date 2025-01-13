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

// Function to print the middle row of the matrix
void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleRow = Rows / 2;
    //cout << MiddleRow << endl; // Calculate the middle row
    for (short j = 0; j < Cols; j++)
    {
        printf(" %0*d ", 2, arr[MiddleRow][j]); // Print each element in the middle row
    }
    cout << "\n";
}

// Function to print the middle column of the matrix
void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleCol = Cols / 2; // Calculate the middle column
    for (short i = 0; i < Rows; i++)
    {
        printf(" %0*d ", 2, arr[i][MiddleCol]); // Print each element in the middle column
    }
    cout << "\n";
}

int main()
{
    // Seed the random number generator to get different numbers each run
    srand((unsigned)time(NULL));

    // Declare a 3x3 matrix
    int Matrix1[3][3];

    // Fill the matrix with random numbers
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);

    // Print the entire matrix
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    // Print the middle row of the matrix
    cout << "\nMiddle Row of Matrix1 is:\n";
    PrintMiddleRowOfMatrix(Matrix1, 3, 3);

    // Print the middle column of the matrix
    cout << "\nMiddle Col of Matrix1 is:\n";
    PrintMiddleColOfMatrix(Matrix1, 3, 3);

    // Pause the console (for Windows only)
  //  system("pause>0");
    return 0;
}