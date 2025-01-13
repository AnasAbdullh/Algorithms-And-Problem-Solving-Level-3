#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;

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

vector<sClient> LoadCleintsDataFromFile(const string &FilePath)
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

vector <sClient> SaveCleintsDataToFile(string FileName, vector
                                       <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite
    string DataLine;
    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientCard(const sClient &Client)
{
    cout << fixed << setprecision(2);
    cout << "Account Number: " << Client.AccountNumber << endl;
    cout << "Pin Code: " << Client.PinCode << endl;
    cout << "Name: " << Client.Name << endl;
    cout << "Phone: " << Client.Phone << endl;
    cout << "Account Balance: $" << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(const string &NumberAccount, const vector<sClient> &Clients, sClient &FoundClient)
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

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber;
    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}


bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient> &vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients,
                                  Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient & C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveCleintsDataToFile(ClientsFileName, vClients);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber
             << ") is Not Found!";
        return false;
    }
}


string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}
int main()
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
    system("pause>0");
}