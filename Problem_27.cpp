#include <string>
#include <iostream>
using namespace std;
char ReadString()
{
    char S1;
    cout << "Please Enter Your String?\n";
    cin >>S1;
    return S1;
}
char CheckLetterLowerOrUpper(char S1) {

    if(islower(S1))
        S1 = toupper (S1);
    else
        S1 =  tolower(S1);
    return S1;
}
int main()
{
    char S1 = ReadString();
    cout << "\nString after conversation:\n";
    S1 = CheckLetterLowerOrUpper(S1);
    cout << S1 << endl;
}
