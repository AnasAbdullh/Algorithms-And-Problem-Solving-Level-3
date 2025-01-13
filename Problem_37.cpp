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

void PrintEchoWorld(const vector<string>& arrWorld) {
    for(const auto& world : arrWorld) {
        cout << world << endl;
    }
}

vector <string> CountWords(string & S1,short & count  )
{
    string  delim = " ";
    short pos = 0;
    string World ;
    
    vector<string> arrWorld;
    while((pos = S1.find(delim)) != std::string::npos) {

        World= S1.substr(0,pos);
        if (World != "")
        {
            count ++;
            arrWorld.push_back(World);
        }
        S1.erase(0,  pos + delim.size()) ;
    }

    if (S1 != "")
    {
        count++;
        arrWorld.push_back(S1);
    }
    return arrWorld ;
}
int main()
{
    
    string Readword = ReadString();
    short Token = 0;
    vector<string> arrWorld = CountWords(Readword,Token);
    cout << "Tokens = " << Token << endl;
    PrintEchoWorld(arrWorld);
    
   // cout << "The number of word in your string is : " <<  CountWords(Readword) <<endl;
}
    