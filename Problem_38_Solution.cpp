#include <iostream>
#include <string>
using namespace std;

// دالة TrimLeft
string TrimLeft(const string &input) {
    size_t start = 0;
    while (start < input.size() && isspace(input[start])) {
        start++;
    }
    return input.substr(start);
}

// دالة TrimRight
string TrimRight(const string &input) {
    int end = input.size() - 1;
    while (end >= 0 && isspace(input[end])) {
        end--;
    }
    return input.substr(0, end + 1);
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