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

    } while (Number < 1 || Number > 100);
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
            arr[i][j] = RandomNumber(1, 100); // Random numbers between 1 and 10
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
    cout << endl;
    short Number = ReadNumber("Enter the number to look for  in matrix");

    if (CountNumberInMatrix(Matrix1,3,Number))
        cout << "Yes It is there" << endl;
    else

        cout << "No It is Not there" << endl;


    return 0;
}