#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
// use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

sClient convertLinetoRecorde(string S1, string sepretor = "#//#")
{
    sClient Cleint;
    vector <string> ArrString = SplitString(S1,sepretor);
    Cleint.AccountNumber = ArrString[0];
    Cleint.PinCode = ArrString[1];
    Cleint.Name = ArrString[2];
    Cleint.Phone = ArrString[3];
    Cleint.AccountBalance = stod(ArrString[4]);
    return Cleint;
}

vector<sClient> LoadDataOfCenter()
{
    vector<sClient> vCleints;
    string FilePath = "/storage/emulated/0/OutputFilesCpp/Client.txt";
    fstream File;
    File.open(FilePath, ios::in);

    if (File.is_open())
    {
        string Line;
        while (getline(File, Line))
        {
            sClient Client = convertLinetoRecorde(Line);
            vCleints.push_back(Client); // استخدم push_back لإضافة العميل إلى المتجه
        }
        File.close();
    }
    else
    {
        cout << "Error: File not found or cannot be opened." << endl;
    }

    return vCleints;
}

void PrintClientInformation(vector <sClient> vCleints)
{
    cout << "Client List (" << vCleints.size() << ") Client(s)." << endl;
    cout << string(72, '-') << endl; // خط علوي للجدول

    // طباعة رأس الجدول
    cout << "| " << setw(15) << left << "Account Number"
         << "| " << setw(10) << left << "Pin Code"
         << "| " << setw(20) << left << "Client Name"
         << "| " << setw(10) << left << "Phone"
         << "| " << setw(10) << left << "Balance"
         << "|" << endl;

    cout << string(72, '-') << endl; // خط بين الرأس والبيانات

    // طباعة بيانات العملاء
    for (short i = 0; i < vCleints.size() ; i++)
    {
        cout << "| " << setw(15) << left << vCleints[i].AccountNumber
             << "| " << setw(10) << left << vCleints[i].PinCode
             << "| " << setw(20) << left << vCleints[i].Name
             << "| " << setw(10) << left << vCleints[i].Phone
             << "| " << setw(10) << left << fixed << setprecision(2) << vCleints[i].AccountBalance
             << "|" << endl;
    }

    cout << string(72, '-') << endl; // خط سفلي للجدول
}

int main()
{
    
    vector <sClient> vCleints = LoadDataOfCenter();
    PrintClientInformation(vCleints);
    
    return 0;
}