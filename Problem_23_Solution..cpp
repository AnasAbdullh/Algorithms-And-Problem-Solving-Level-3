#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
void PrintFirstLetterOfEachWord(string S1)
{
    bool IsFirstLetter = true;
    for(short i = 0 ; i < S1.length(); i++) {
        if(S1[i] != ' ' && IsFirstLetter) {

            cout << S1[i] << endl;
        }
        IsFirstLetter = (S1[i] == ' ' ) ? true : false ;
    }
}
int main()
{
    PrintFirstLetterOfEachWord(ReadString());
    //system("pause>0");
}
