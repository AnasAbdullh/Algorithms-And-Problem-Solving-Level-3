#include <string>
#include <iostream>
#include <vector>
using namespace std;

string ReadString()
{
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

string ReplaceString(string S1, string Replace, string Original )
{
    short pos = S1.find(Original);

    while (S1.find(Original) != S1.npos) {

        S1 = S1.replace(pos, Original.size(),Replace);
        pos = S1.find(Original);
    }
    return S1;
}

int main()
{
    string Replace = "USA";
    string Original = "Anas";
    cout << ReplaceString(ReadString(),Replace,Original) << endl;

    return 0;
}