#include <string>
#include <iostream>
#include <vector>

using namespace std;


string JoinWords(const vector<string>& words, const string& delim) {
    if (words.empty()) {
        return ""; // إرجاع نص فارغ إذا لم تكن هناك كلمات
    }
    string text = "";
    for (const auto & word : words) {

        text = text + word + delim;

    }
    return text.substr(0,text.size() - delim.size());
}

string JoinWords( string words[3], const string& delim, short arrLength) {

    string text = "";
    for (short i = 0; i < arrLength ; i++ ) {

        text = text + words[i] + delim;

    }
    return text.substr(0,text.size() - delim.size());
}


int main() {

    vector <string> words = {"Anas","Awdh","Saleh"};
    string arrwords[3] = {"Anas","Awdh","Saleh"};
    
    string delim = ":";

    cout << JoinWords(words,delim) << endl;
    cout << JoinWords(arrwords,delim,3) << endl;

    return 0;
}