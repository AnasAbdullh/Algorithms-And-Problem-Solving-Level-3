#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

string InvertAllStringLettersCase(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            S1[i] = toupper(S1[i]);
        else
            S1[i] = tolower(S1[i]);
    }
    return S1;
}
int main()
{
    string S1 = ReadString();
    cout << "\nString after Lower:\n";
    S1 = InvertAllStringLettersCase(S1);
    cout << S1 << endl;
}
