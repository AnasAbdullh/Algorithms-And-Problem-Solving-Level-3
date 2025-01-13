
#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
char ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}

char InvertLetterCase(char char1)
{
    return (isupper(char1))? tolower(char1) : toupper(char1);
}


short CountLettersMatchCase(string S1, char Letter, bool MatchCase = true)
{
    short counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase) {
            if (S1[i] == Letter )
                counter++;
        } else {

            if (toupper(S1[i]) == toupper(Letter))

                counter++;
        }

    }
    return counter;

}

int main()
{
    string S1 = ReadString();
    char Ch1 = ReadChar();
    cout << "\nLetter \'" << Ch1 << "\' Count = " << CountLettersMatchCase  (S1, Ch1);
    cout << "\nLetter \'" << Ch1 <<"\' Or \'" <<InvertLetterCase(Ch1)<<"\'" << " Count = " <<   CountLettersMatchCase(S1, Ch1,false);

//   system("pause>0");
}
