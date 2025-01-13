#include <iostream>
using namespace std;

void PrintFibonacciUsingRecursion(short Number)
{
    static int FebNumber = 0;
    static int Prev2 = 0, Prev1 = 1;
    static short Count= 2;


    FebNumber = Prev1 + Prev2;
    cout << FebNumber << " ";
    Prev2 = Prev1;
    Prev1 = FebNumber;
    if(Count < Number) {
        Count++;
        PrintFibonacciUsingRecursion(Number);
    }
}
int main()
{
    cout << "1 ";
    PrintFibonacciUsingRecursion(10);
    // system("pause>0");
}
