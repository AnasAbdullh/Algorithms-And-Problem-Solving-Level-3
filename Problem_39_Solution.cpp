#include <string>
#include <iostream>
#include <vector>
#include <sstream> // لاستخدام stringstream

using namespace std;

// قراءة النص من المستخدم// جمع الكلمات في نص واحد باستخدام فاصل
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

// الدالة الرئيسية
int main() {


    vector <string> words = {"Anas","Awdh","Saleh"};
    
    cout << JoinWords(words," ") << endl;

    return 0;
}