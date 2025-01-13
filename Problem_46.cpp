#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

void printReadNewClient(sClient Client)
{
    cout << fixed << setprecision(4); // تحديد 4 منازل عشرية
    cout << "Account Number: " << Client.AccountNumber << endl;
    cout << "Pin Code: " << Client.PinCode << endl;
    cout << "Name: " << Client.Name << endl;
    cout << "Phone: " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;
}

void FillInStrctur(string ArrString[100], sClient &Cleint)
{
    Cleint.AccountNumber = ArrString[0];
    Cleint.PinCode = ArrString[1];
    Cleint.Name = ArrString[2];
    Cleint.Phone = ArrString[3];
    Cleint.AccountBalance = stod(ArrString[4]);
}

void fillInArray(string S1, string arrString[100])
{
    short pos = 0;
    short count = 0;
    string delim = "#//#"; // تحديد الفاصل

    // تقسيم النص بناءً على الفاصل #//#
    while ((pos = S1.find(delim)) != string::npos) {
        arrString[count] = S1.substr(0, pos); // استخرج النص حتى الموضع الحالي
        S1.erase(0, pos + delim.size()); // احذف النص الذي تم معالجته
        count++;
    }
    arrString[count] = S1; // أضف الجزء الأخير من النص
}

void RemovePunct(string &S1, string delim = "#//#")
{
    size_t pos = 0;
    string replacement = " ";

    while ((pos = S1.find(delim)) != string::npos) {
        S1.replace(pos, delim.size(), replacement);
    }

    // إزالة المسافة الزائدة في النهاية (إن وجدت)
    if (!S1.empty() && S1.back() == ' ') {
        S1.pop_back();
    }
}

int main()
{
    string ArrString[100];
    sClient Cleint;
    string recorde = "12345#//#6789#//#Anas Abdullah#//#987654321#//#5000.000000";

    // إزالة النصوص الغير مرغوب فيها
    RemovePunct(recorde);

    // تقسيم النص إلى أجزاء بناءً على الفاصل
    fillInArray(recorde, ArrString);

    // ملء البيانات في الهيكل
    FillInStrctur(ArrString, Cleint);

    // طباعة البيانات
    printReadNewClient(Cleint);

    return 0;
}