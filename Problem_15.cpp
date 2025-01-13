#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iomanip> //
using namespace std;
int ReadNumber(string Message )
{
    short Number = 0;

    do {

        cout << Message << endl;
        cin >> Number;
        while (cin.fail())
        {

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid one:" << endl;

            cin >>Number;
        }

    } while (Number < 1 || Number > 11);
    return Number;
}
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


int AreCountInMatrices(int Matrix1[3][3], short Cols, int Number)
{

    short count = 0;

    for  (short i = 0; i < Cols; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(Matrix1[i][j] == Number)
                count++;
        }

    }
    return count;


}



int main()
{
    // Seed the random number generator to get different numbers each run
    srand((unsigned)time(NULL));

    // Declare a 3x3 matrix
    int Matrix1[3][3];

    FillMatrixWithRandomNumbers(Matrix1,3,3);

    // Print the entire matrix
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    cout <<endl;
    short Number = ReadNumber("Enter the number to count in matrix");
    cout << "Number " <<Number <<" count in matrix " << AreCountInMatrices(Matrix1,3,Number) << endl;




    return 0;
}