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

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
// use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);

        }
        S1.erase(0, pos + Delim.size()); /* erase() until
positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

bool IsMactchCase(string S1, string Original)
{
    short pos = S1.find(Original);
    if (isupper(S1[pos])) {
        return true ;
    }
    return false ;
}

string FillVectorInString(vector <string> vString) {
    string words = "";
    for (const auto & fill : vString) {

        words += fill + " ";
    }

    if(!words.empty()) {
        words.pop_back();
    }
    return words;
}

string ReplaceString(string S1, string Replace, string Original )
{
    string words = "";
    short  pos = 0 ;
    if(IsMactchCase(S1,Original)) {
        while (( pos = S1.find(Original)) != string::npos) {

            S1.erase(pos,Original.size());
            S1.insert(pos,Replace);
        }

    }
    return S1;
}

int main()
{
    string S1 = ReadString();
    string Replace = "USA";
    string Original = "Anas";
    vector <string> words = SplitString(S1," ");
    string input = FillVectorInString(words);
    cout << ReplaceString(input,Replace,Original) << endl;
    // cout << ReplaceString(ReadString(),Replace,Original) << endl;



    return 0;
}