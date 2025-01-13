
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
//printf(" %0*d ", 2, arr[i][j]);
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int PrintMinimumNumber(int Matrix1[3][3],   short Rows, short Cols)
{
    int Number = Matrix1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Number > Matrix1[i][j])
                Number = Matrix1[i][j];

        }
    }
    return Number ;
}

int PrintMaxNumber(int Matrix1[3][3],   short Rows, short Cols)
{
    int Number = Matrix1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Number < Matrix1[i][j])
                Number = Matrix1[i][j];

        }
    }
    return Number ;
}
int main()
{
    int Matrix1[3][3] = { {77,5,12},{22,99,1},{-1,0,9} };

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    cout << "Minimum Number is " <<PrintMinimumNumber(Matrix1,3,3)  << endl;
    cout << "Max Number is " <<PrintMaxNumber(Matrix1,3,3)  << endl;

}
