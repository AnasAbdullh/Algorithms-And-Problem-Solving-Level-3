#include <string>
#include <iostream>

using namespace std;

// تعريف هيكل بيانات العميل
struct DataClient {
    string AccountNumber = "";
    short PinCode = 0;
    string Name = "";
    int Phone = 0;
    double AccountBalance = 0;
};

// دالة لدمج بيانات العميل في نص واحد
string ClientConcatenation(DataClient Data) {
    string separator = "#//#";
    string ClientRecord = Data.AccountNumber + separator +
                          to_string(Data.PinCode) + separator +
                          Data.Name + separator +
                          to_string(Data.Phone) + separator +
                          to_string(Data.AccountBalance);
    return ClientRecord;
}

// دالة لقراءة بيانات العميل
string ReadDataFromClient(DataClient &ReadData) {
    cout << "Please Enter Client Data:\n\n";

    cout << "Enter Account Number: ";
    cin >> ReadData.AccountNumber;

    cout << "Enter PinCode: ";
    cin >> ReadData.PinCode;

    cin.ignore(); // لتجنب مشكلة newline بعد cin
    cout << "Enter Name: ";
    getline(cin, ReadData.Name);

    cout << "Enter Phone: ";
    cin >> ReadData.Phone;

    cout << "Enter Account Balance: ";
    cin >> ReadData.AccountBalance;

    return ClientConcatenation(ReadData);
}

// البرنامج الرئيسي
int main() {
    DataClient DataClient;
    cout << ReadDataFromClient(DataClient) << endl;
    return 0;
}