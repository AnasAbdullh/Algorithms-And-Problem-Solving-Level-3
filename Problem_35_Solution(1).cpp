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
void PrintEachWordInString(string S1)
{
    string  delim = " ";
    short pos = 0;
    string World ;
    while((pos = S1.find(delim)) != std::string::npos) {

        World= S1.substr(0,pos);
        if (World != "")
        {
            cout << World << endl;
        }
        S1.erase(0,  pos + delim.size()) ;
    }

    if (World != "")
    {
        cout << S1 << endl;
    }
}
int main()
{
    PrintEachWordInString(ReadString());
    //  cout << string::npos << endl;
}
    