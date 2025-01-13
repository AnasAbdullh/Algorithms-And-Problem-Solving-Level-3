#include <iostream>
#include <string>
using namespace std;

// دالة TrimLeft
string TrimLeft(const string input) {

    for(size_t i =0; i < input.size(); i++)
    {
        if (input[i] != ' ') {
            return input.substr(i);
        }
    }

    return "";
}

// دالة TrimRight
string TrimRight(const string input) {

    for (size_t i = input.size() -1; i >= 0 ; i --) {


        if (input[i] != ' ') {
            return input.substr(0, i +1);
        }
    }
}

// دالة Trim (كلا الطرفين)
string Trim(const string &input) {
    return TrimLeft(TrimRight(input));
}

int main() {
    // قراءة النص من المستخدم
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    // عرض النصوص بعد تطبيق الدوال
    cout << "\nOriginal String = \"" << input << "\"" << endl;
    cout << "Trim Left = \"" << TrimLeft(input) << "\"" << endl;
    cout << "Trim Right = \"" << TrimRight(input) << "\"" << endl;
    cout << "Trim = \"" << Trim(input) << "\"" << endl;

    return 0;

}