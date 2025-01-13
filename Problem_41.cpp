#include <string>
#include <iostream>
#include <vector>

using namespace std;

string Reverce(string words) {

    string tree = "";
    short end = words.size();
    for (short i = words.size() - 1 ; i >=0; i--) {

        if (words[i] == ' '  || i == 0) {
            tree = tree + words.substr(i,end - i +1);
            
            end = i;
        }
    }
    tree.erase(0,1);
    return tree;
}

int main() {

    string words = "Anas Abdallah Awdh";
    cout << Reverce(words) << endl;
    cout << "Anas" << endl;
    return 0;
}