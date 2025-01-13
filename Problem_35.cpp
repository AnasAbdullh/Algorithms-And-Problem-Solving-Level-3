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

void PrintEchoWorld(string arrWorld)
{
    for(const auto & world : arrWorld) {
        cout << world;
    }
    cout << "\n";
}

string UpperFirstLetterOfEachWord(string S1)
{
    char lastLetter = S1.back();
    string World ;
    for (short i = 0; i < S1.size(); i++)
    {
        if (S1[i] != ' '  || S1[i] != lastLetter )
        {
            World += S1[i];

        } else {
            PrintEchoWorld(World);
            World.clear();
        }
        
    }
    return S1;
}

int main()
{
    string Ch1 = ReadString ();
    UpperFirstLetterOfEachWord(Ch1);
 // cout << Ch1.back() << endl;

}
    