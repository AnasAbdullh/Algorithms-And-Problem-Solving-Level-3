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

void printReadNewClient(sClient Client)
{
    cout << fixed << setprecision(4); // تحديد 4 منازل عشرية
    cout << "Account Number: " << Client.AccountNumber << endl;
    cout << "Pin Code: " << Client.PinCode << endl;
    cout << "Name: " << Client.Name << endl;
    cout << "Phone: " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;
}

bool CheckNumberAccount(sClient &vCleints,string  NumberAccount)
{
    vector<sClient> vCleinbts  = LoadDataOfCenter();

    for (auto c : vCleinbts ) {
        if (c.AccountNumber == NumberAccount ) {
            vCleints = c;
            return true ;
        }
    }
    return false;
}

void RemoveCleintFormFile(string NumberAccount)
{
    vector<sClient> vCleints = LoadDataOfCenter() ;
    string FilePath = "/storage/emulated/0/OutputFilesCpp/Client.txt";
    fstream File;
    File.open(FilePath, ios::out);

    if (File.is_open())
    {
        for (const auto & Client : vCleints ) {

            if(Client.AccountNumber != NumberAccount) {

                File << Client.AccountNumber << "#//#"
                     << Client.PinCode << "#//#"
                     << Client.Name << "#//#"
                     << Client.Phone << "#//#"
                     << Client.AccountBalance << endl;
            }
        }

        File.close();
    }
    else
    {
        cout << "Error: File not found or cannot be opened." << endl;
    }



}


void AskUserrmoveCleint(string NumberAccount)
{
    char rmove = 'y';
    cout << "\n\nAre you sure want delete this client ? y/n ? ";
    cin >> rmove;
    if (tolower (rmove) == 'y') {
        RemoveCleintFormFile( NumberAccount);

    }
}

int main()
{

    string  NumberAccount = "";
    cout << "Please Number Account ?" ;
    cin >> NumberAccount;

    sClient vCleints;
    if (CheckNumberAccount(vCleints,NumberAccount)) {

        printReadNewClient(vCleints);
        AskUserrmoveCleint(NumberAccount);

    } else {

        cout << "Client with Account Number ("<< NumberAccount <<") Not Found!" << endl;
    }

    return 0;
}
