#include <string>
#include <iostream>
using namespace std;

char ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}

bool CountLettersMatchCase( char Letter)
{
    char Vomels[5] = {'a','e','i','o','u'};
    short counter = 0;
    for (short i = 0; i < 5; i++)
    {
        if(tolower(Letter) == Vomels[i]) {
            return true;
        }
    }
    return false;
}

int main()
{

    char Ch1 = ReadChar();

    if (CountLettersMatchCase(Ch1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
