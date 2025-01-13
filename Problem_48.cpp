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

void convertLinetoRecorde(string S1, short count,sClient arrayCleint[3],string sepretor = "#//#" )
{
    sClient Cleint;

    vector <string> ArrString = SplitString(S1,sepretor);
    arrayCleint[count].AccountNumber = ArrString[0] ;
    arrayCleint[count].PinCode= ArrString[1];
    arrayCleint[count].Name = ArrString[2];
    arrayCleint[count].Phone = ArrString[3];
    arrayCleint[count].AccountBalance  = stod(ArrString[4]);

}

void LoadDataOfCenter(sClient arrayCleint[3],short & count)
{

    string FilePath = "/storage/emulated/0/OutputFilesCpp/Client.txt";
    fstream File;
    File.open(FilePath, ios::in);

    if (File.is_open())
    {
        string Line;
        while (getline(File, Line))
        {
            convertLinetoRecorde(Line,count,arrayCleint);
            count ++;
        }
        File.close();
    }
}

void PrintClientInformation(sClient arrayClient[3], short count)
{
    cout << "Client List (" << count << ") Client(s)." << endl;
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
    for (short i = 0; i < count; i++)
    {
        cout << "| " << setw(15) << left << arrayClient[i].AccountNumber
             << "| " << setw(10) << left << arrayClient[i].PinCode
             << "| " << setw(20) << left << arrayClient[i].Name
             << "| " << setw(10) << left << arrayClient[i].Phone
             << "| " << setw(10) << left << fixed << setprecision(2) << arrayClient[i].AccountBalance
             << "|" << endl;
    }

    cout << string(72, '-') << endl; // خط سفلي للجدول
}

int main()
{
    short count = 0;

    sClient arrayCleint[3];
    LoadDataOfCenter(arrayCleint,count);
    PrintClientInformation(arrayCleint,count);

    return 0;
}