#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "/storage/emulated/0/OutputFilesCpp/Client.txt";

enum enMainMenuOptions {
    ShowClientList = 1,
    AddNewClient = 2,
    DeleteClient = 3,
    UpdateClientInfo = 4,
    FindClient = 5,
    Exit = 6
};

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;

};

void MainMenueScreen() {

    cout << "========================================\n";
    cout << "            Main Menue Screen\n";
    cout << "========================================\n";
    cout << "            [1] Show Client List.\n";
    cout << "            [2] Add New Client.\n";
    cout << "            [3] Delete Client.\n";
    cout << "            [4] Update Client Info.\n";
    cout << "            [5] Find Client.\n";
    cout << "            [6] Exit.\n";
    cout << "========================================\n";

}

void ToGoBackToMain()
{

    cout << "Press Enter to go back to Main Menu...";
    // cin.get();
    system("read");
    // system("clear");
}


enMainMenuOptions ReadChooesUser() {

    short Choice = 0;
    do
    {
        cout << "\nChoose what do you want to do? [1 to 6]? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 6);
    return (enMainMenuOptions)Choice;
}

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

    fstream File;
    File.open(ClientsFileName, ios::in);

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

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}


bool FindClientByAccountNumber(const string &NumberAccount, const vector<sClient> Clients,sClient& FoundClient)
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

sClient ReadNewClient(vector <sClient> & vClients,sClient & FoundClient )
{
    sClient Client;
    cout << string(44,'-') << endl;
    cout << setw(10) << "Add New Client" << endl;
    cout << string(44,'-') << endl;


    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);

    while(FindClientByAccountNumber(Client.AccountNumber,vClients,FoundClient )) {

        cout << "Client with [ "<<  Client.AccountNumber <<"] already exists, Enter another Account Number?" ;
        cin >> Client.AccountNumber;
    }

    cout << "Enter PinCode? ";
    getline(cin>>ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator =  "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

void addNewClient(vector <sClient> & vClients, sClient & FoundClient )
{
    sClient Client;
    Client = ReadNewClient(vClients,FoundClient);
    AddDataLineToFile(ClientsFileName,ConvertRecordToLine(Client));
}

void AddClients(vector <sClient> & vClients,sClient  &Client)
{
    char AddMore = 'Y';
    do
    {
        system("clear");
        cout << "Adding New Client:\n\n";
        addNewClient(vClients,Client);
        cout << "\nClient Added Successfully, do you want to add  more clients? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}



void SaveCleintsDataToFile(const vector<sClient> &Clients, const string &FilePath)
{
    ofstream File(FilePath);

    if (File.is_open())
    {
        for (const auto &Client : Clients)
        {
            if (!Client.MarkForDelete)
            {
                File << ConvertRecordToLine(Client) << endl;
            }
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

void MarkClientForRemoval(const string &NumberAccount, vector<sClient> &Clients)
{
    for (auto &Client : Clients)
    {
        if (Client.AccountNumber == NumberAccount)
        {
            Client.MarkForDelete = true;
            break;
        }
    }
}

void AskUserToRemoveClient(const string &FilePath, vector<sClient> &Clients)
{

    cout << string(44,'-') << endl;
    cout << setw(10) << "delete info Client" << endl;
    cout << string(44,'-') << endl;


    string NumberAccount;
    cout << "Please enter the account number to remove: ";
    cin >> NumberAccount;

    sClient FoundClient;
    if (FindClientByAccountNumber(NumberAccount, Clients, FoundClient))
    {
        PrintClientInfo(FoundClient);
        char Confirm;
        cout << "Are you sure you want to delete this client? (y/n): ";
        cin >> Confirm;

        if (tolower(Confirm) == 'y')
        {
            MarkClientForRemoval(NumberAccount, Clients);
            SaveCleintsDataToFile(Clients, FilePath);
            cout << "Client removed successfully.\n";
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


void UpdateClientByAccountNumber(string AccountNumber, vector <sClient> &vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientInfo(Client);
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
            SaveCleintsDataToFile(vClients, ClientsFileName);
            cout << "\n\nClient Updated Successfully.";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber
             << ") is Not Found!";
    }
}


string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

void CheckNumberAccount(const string &NumberAccount, vector<sClient> &Clients,sClient FoundClient)
{
    if(FindClientByAccountNumber(NumberAccount,Clients,FoundClient)) {

        PrintClientInfo(FoundClient);

    } else {

        cout << "\nClient with Account Number (" << NumberAccount  << ") is Not Found!";

    }

}

void PrintEndoftheProgram()
{
    cout << string(44,'-') << endl;
    cout << setw(10) << "Program Ends :-)" << endl;
    cout << string(44,'-') << endl;

    system("read");


}

void Choosingtherightprocess(enMainMenuOptions Chooes) {

    sClient Client;
    vector <sClient> vCleints  = LoadDataOfCenter();
    switch (Chooes)
    {
    case ShowClientList:

        PrintClientInformation(vCleints);
        ToGoBackToMain();
        break;

    case AddNewClient :
        AddClients(vCleints,Client);
        ToGoBackToMain();

        break;

    case DeleteClient :

        AskUserToRemoveClient(ClientsFileName,vCleints);
        break;

    case UpdateClientInfo :

        UpdateClientByAccountNumber(ReadClientAccountNumber(),vCleints);
        break;

    case FindClient :

        CheckNumberAccount(ReadClientAccountNumber(),vCleints,Client);

        break;

    default:
        PrintEndoftheProgram();
    }

}


int main()
{

    MainMenueScreen();

    Choosingtherightprocess(ReadChooesUser());

    return 0;
}
