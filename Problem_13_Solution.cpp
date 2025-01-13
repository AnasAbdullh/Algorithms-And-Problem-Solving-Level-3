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
/*void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10); // Random numbers between 1 and 10
        }
    }
}*/

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


bool AreTypicalMatrices(int Matrix1[3][3], short Cols)
{



    for (short i = 0; i < Cols; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(i == j && Matrix1[i][j] != 1) {

                return false ;
            } else if (i!=j && Matrix1[i][j] != 0)
                return false;
        }

    }
    return true;
}



int main()
{
    // Seed the random number generator to get different numbers each run
    srand((unsigned)time(NULL));

    // Declare a 3x3 matrix
    int Matrix1[3][3] = {{1,0,0},
        {0,1,0},
        {0,0,1}
    };



    // Print the entire matrix
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    cout << "\nMatrix2:\n";


    if (AreTypicalMatrices(Matrix1,3) )
        cout << "\nYES: both martices are identity.";
    else
        cout << "\nNo: martices are NOT  identity.";



    return 0;
}