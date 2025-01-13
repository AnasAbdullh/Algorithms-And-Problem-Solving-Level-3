#include <string>
#include <iostream>
#include <cctype>
using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
string PrintFirstLetterOfEachWord(string S1)
{
    bool IsFirstLetter = true;
    for(short i = 0 ; i < S1.length(); i++) {
        if(S1[i] != ' ' && IsFirstLetter) {

            if (islower(S1[i])) {
                S1[i] = toupper(S1[i]);
            }
        }
        IsFirstLetter = (S1[i] == ' ' ) ? true : false ;
    }
    return S1;
}
int main()
{
    string PrintBigger = PrintFirstLetterOfEachWord(ReadString());
    cout <<  PrintBigger << endl;
}
