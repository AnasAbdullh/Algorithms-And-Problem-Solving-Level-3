#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip> // لإعداد تنسيق الأرقام
using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

sClient ReadNewClient()
{
    sClient Client;
    cout << "\nPlease Enter Client Data: \n\n";

    cout << "Enter Account Number? ";
    getline(cin, Client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance? ";
    cin >> Client.AccountBalance;

    // تنظيف دفق الإدخال
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;

    // تنسيق الرقم العشري
    stClientRecord += to_string(static_cast<int>(Client.AccountBalance));
    return stClientRecord;
}

void LoadDataFromProgramToFile(string Client)
{

    string FilePath = "/storage/emulated/0/OutputFilesCpp/Client.txt";
    fstream ReaddData;

    ReaddData.open(FilePath, ios::out | ios::app);

    if (ReaddData.is_open())
    {
        ReaddData << Client << endl; // إضافة سطر جديد بعد كل سجل
        ReaddData.close();
    } else
    {
        cout << "Error: Unable to open file at " << FilePath << endl;
    }
}

void UserToAddMoreCleint()
{
    sClient Client;
    char Answer = 'Y';

    do {
        system("clear");
        Client = ReadNewClient();
        LoadDataFromProgramToFile(ConvertRecordToLine(Client));
        cout << "\n\nClient Added Successfully, do you want to add more clients? (Y/N): ";
        cin >> Answer;

        // تنظيف دفق الإدخال
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (toupper( Answer) == 'Y');
}

int main()
{
    UserToAddMoreCleint();
    return 0;
}