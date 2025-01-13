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

void PrintEchoWorld(const vector<string>& arrWorld) {
    for(const auto& world : arrWorld) {
        cout << world << endl;
    }
}

vector<string> SplitString(const string& S1, const string& QuotationMark = " ") {
    vector<string> Spilt;
    size_t start = 0;
    size_t end = 0;

    while ((end = S1.find(QuotationMark, start)) != string::npos) {
        if (start != end) {
            Spilt.push_back(S1.substr(start, end - start));
        }
        start = end + QuotationMark.size();
    }

    if (start < S1.size()) {
        Spilt.push_back(S1.substr(start));
    }

    return Spilt;
}

int main() {
    string Ch1 = ReadString();
    vector<string> Spilt = SplitString(Ch1);
    PrintEchoWorld(Spilt);
}