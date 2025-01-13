#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iomanip> //
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


void AreZeroMoreInMatrices(int Matrix1[3][3], short Cols, int& zero, int  &number)
{

    for  (short i = 0; i < Cols; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(Matrix1[i][j] == 0)
                zero++;
            else
                number++;
        }

    }

}

int main()
{
    // Seed the random number generator to get different numbers each run
    srand((unsigned)time(NULL));

    // Declare a 3x3 matrix
    int Matrix1[3][3], zero, Number;

    FillMatrixWithRandomNumbers(Matrix1,3,3);

    // Print the entire matrix
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    cout <<endl;
    AreZeroMoreInMatrices(Matrix1,3,zero,Number);
    if(zero > Number )
        cout << "\nYes: It is Sparse\n" << endl;
    else

        cout << "\nNo: It's NOT Sparse\n";


    return 0;
}