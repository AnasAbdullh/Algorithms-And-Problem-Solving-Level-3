#include <string>
#include <iostream>
#include <vector>

using namespace std;

string ReadString() {
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

string RmovePauncuationsString(string S1)
{
    for (short i = 0; i< S1.size(); i++) {

        if (ispunct(S1[i]))  {
            S1.erase(i,1);
            S1.insert(i," ");
        }
    }
    if(S1.empty()) {
        S1.pop_back();
    }
    return S1;
}

int main()
{
    cout << RmovePauncuationsString(ReadString()) << endl;
    return 0;
}