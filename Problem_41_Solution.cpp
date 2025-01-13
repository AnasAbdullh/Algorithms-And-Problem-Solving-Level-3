#include <string>
#include <iostream>
#include <vector>
using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
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

string ReverseWordsInString(string S1)
{
    string Words = "";
    vector <string> String = SplitString(S1," ");
    vector <string>::iterator iter =  String.end();
    while(iter != String.begin()) {
        --iter;
        Words += *iter + " ";

    }

    Words.substr(0, Words.length() - 1);
    return Words;
}
int main()
{
    // string S1 = ReadString();
    string Name = "Anas Abdallah";
    // cout << Name.substr(0,) << endl;
    cout << "\n\nString after reversing words:";
    cout << "\n" << ReverseWordsInString(Name);
//   system("pause>0");
}