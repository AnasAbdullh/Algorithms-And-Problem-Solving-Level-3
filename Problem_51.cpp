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

// Helper functions
vector<string> SplitString(const string &S1, const string &Delim)
{
    vector<string> vString;
    size_t pos = 0;
    string sWord;
    string temp = S1;

    while ((pos = temp.find(Delim)) != string::npos)
    {
        sWord = temp.substr(0, pos);
        if (!sWord.empty())
        {
            vString.push_back(sWord);
        }
        temp.erase(0, pos + Delim.length());
    }
    if (!temp.empty())
    {
        vString.push_back(temp);
    }
    return vString;
}

sClient ConvertLineToRecord(const string &S1, const string &Seperator = "#//#")
{
    sClient Client;
    vector<string> ArrString = SplitString(S1, Seperator);
    if (ArrString.size() == 5)
    {
        Client.AccountNumber = ArrString[0];
        Client.PinCode = ArrString[1];
        Client.Name = ArrString[2];
        Client.Phone = ArrString[3];
        Client.AccountBalance = stod(ArrString[4]);
    }
    return Client;
}

string ConvertRecordToLine(const sClient &Client, const string &Seperator = "#//#")
{
    return Client.AccountNumber + Seperator +
           Client.PinCode + Seperator +
           Client.Name + Seperator +
           Client.Phone + Seperator +
           to_string(Client.AccountBalance);
}

vector<sClient> LoadDataOfCenter(const string &FilePath)
{
    vector<sClient> vClients;
    ifstream File(FilePath);

    if (File.is_open())
    {
        string Line;
        while (getline(File, Line))
        {
            vClients.push_back(ConvertLineToRecord(Line));
        }
        File.close();
    }
    else
    {
        cerr << "Error: Cannot open file: " << FilePath << endl;
    }

    return vClients;
}

void SaveDataToFile(const vector<sClient> &Clients, const string &FilePath)
{
    ofstream File(FilePath,ios::out);

    if (File.is_open())
    {
        for (const auto &Client : Clients)
        {
                File << ConvertRecordToLine(Client) << endl;
        }
        File.close();
    }
    else
    {
        cerr << "Error: Cannot open file: " << FilePath << endl;
    }
}

void PrintClientInfo(const sClient &Client)
{
    cout << fixed << setprecision(2);
    cout << "Account Number: " << Client.AccountNumber << endl;
    cout << "Pin Code: " << Client.PinCode << endl;
    cout << "Name: " << Client.Name << endl;
    cout << "Phone: " << Client.Phone << endl;
    cout << "Account Balance: $" << Client.AccountBalance << endl;
}

bool FindClient(const string &NumberAccount, const vector<sClient> &Clients, sClient &FoundClient)
{
    for (const auto &Client : Clients)
    {
        if (Client.AccountNumber == NumberAccount)
        {
            FoundClient = Client;
            return true;
        }
    }
    return false;
}

void UpdateClientForRemoval(const string &NumberAccount, vector<sClient> &Clients,sClient FoundClient)
{
    for (auto &Client : Clients)
    {
        if (Client.AccountNumber == NumberAccount)
        {
            Client = FoundClient;

            break;
        }
    }
}

void  ReadNewClient(sClient &Client)
{
    
    cout << "Enter PinCode? ";
    getline(cin >>ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

}


void AskUserToRemoveClient(const string &FilePath, vector<sClient> &Clients)
{
    string NumberAccount;
    cout << "Please enter the account number : ";
    cin >> NumberAccount;

    sClient FoundClient;
    if (FindClient(NumberAccount, Clients, FoundClient))
    {
        PrintClientInfo(FoundClient);
        char Confirm;
        cout << "Are you sure you want to Update this client? (y/n): ";
        cin >> Confirm;

        if (tolower(Confirm) == 'y')
        {
            ReadNewClient(FoundClient);
            UpdateClientForRemoval(NumberAccount, Clients, FoundClient);
            SaveDataToFile(Clients, FilePath);
            Clients = LoadDataOfCenter(FilePath);
            cout << "Client updated successfully.\n";
        }
        else
        {
            cout << "Operation canceled.\n";
        }
    }
    else
    {
        cout << "Client not found.\n";
    }
}

int main()
{
    const string FilePath = "/storage/emulated/0/OutputFilesCpp/Client.txt";

    vector<sClient> Clients = LoadDataOfCenter(FilePath);
    AskUserToRemoveClient(FilePath, Clients);

    return 0;
}