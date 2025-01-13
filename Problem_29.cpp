#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin,S1);
    return S1;
}

short CountCaptilLetter(string S1) {
    short count = 0;
    for (short i = 0 ; i< S1.size(); i++) {
        if(isupper(S1[i]))
            count++;
    }
    return count;
}

short CountsmallLetter(string S1) {

    short count = 0;
    for (short i = 0 ; i< S1.size(); i++) {
        if(islower(S1[i]))
            count++;
    }
    return count;
}
int main()
{
    string S1 = ReadString();
    cout << "\nCptial letter count " << CountCaptilLetter(S1);
    cout << "\nSmall letter count " << CountsmallLetter(S1);
    cout << "\nString length " << S1.length() << endl;
    
    
}
