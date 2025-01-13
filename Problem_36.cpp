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
short CountWords(string S1)
{
    string  delim = " ";
    short pos = 0;
    string World ;
    short count = 0;
    while((pos = S1.find(delim)) != std::string::npos) {

        World= S1.substr(0,pos);
        if (World != "")
        {
            count ++;
        }
        S1.erase(0,  pos + delim.size()) ;
    }

    if (World != "")
    {
        count++;
    }
    return count;
}
int main()
{
    string Readword = ReadString();
    cout << "The number of word in your string is : " <<  CountWords(Readword) <<endl;
}
