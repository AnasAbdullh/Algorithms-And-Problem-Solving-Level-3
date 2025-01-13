#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.size());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

string ReplaceString(vector<string> S1, string Replace, string Original = "Anas")
{
    string words = "";
    for (auto &v : S1)
    {
        if (v == Original)
        {
            v = Replace;
        }
        words += v + " ";
    }

    // إزالة المسافة الزائدة في النهاية
    if (!words.empty())
    {
        words = words.substr(0, words.size() - 1);
    }

    return words;
}

int main()
{
    string info = "USA";
    string Name = "Anas Abdallah";
    vector<string> String = SplitString(Name, " ");
    cout << "\n\nString after replacing words:";
    cout << "\n" << ReplaceString(String, info) << endl;

    return 0;
}