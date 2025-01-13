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
string joinString(vector <string> S1, string  delim)
{
    string word = "";
    for(const auto& world : S1) {
        word += world ;
        word += delim;
    }
    
    word.erase(word.size() - 1);
    return word;
}

vector <string> CountWords(string & S1,string  delim )
{

    short pos = 0;
    string World ;

    vector<string> arrWorld;
    while((pos = S1.find(delim)) != std::string::npos) {

        World= S1.substr(0,pos);
        if (World != "")
        {
            arrWorld.push_back(World);
        }
        S1.erase(0,  pos + delim.size()) ;
    }

    if (S1 != "")
    {
        arrWorld.push_back(S1);
    }
    return arrWorld ;
}
int main()
{

    string Readword = ReadString();
    short Token = 0;
    vector<string> arrWorld = CountWords(Readword," ");
    PrintEchoWorld(arrWorld);
    cout << joinString(arrWorld,",") << endl;

    // cout << "The number of word in your string is : " <<  CountWords(Readword) <<endl;
}
