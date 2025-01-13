#include <string>
#include <iostream>

using namespace std;
string RemovePunctuationsFromString(string S1)
{
    string words = "";
    for (short i = 0; i< S1.size(); i++) {

        if (!ispunct(S1[i]))  words += S1[i];
    }
    return words;
}
int main()
{
    string S1 = "Welcome to Jordan, Jordan is a nice country; it'samazing.";
    cout << "Original String:\n" << S1;
    cout << "\n\nPauncuations Removed:\n" << RemovePunctuationsFromString(S1);
    return 0;
}