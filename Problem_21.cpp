#include <iostream>
using namespace std;

void Serisc(short Number)
{
    short Prve1 = 1,Prve2 =1, Sum =0;
    
    cout << Prve1 << "    " ;
    cout << Prve2 << "    " ;

    for (short i = 2; i < Number ; i++) {

        Sum = Prve1 + Prve2;
        Prve2 = Prve1;
        Prve1 = Sum;

        cout << Sum << "   ";
    }
}
int main()
{

    short Number = 10;
    Serisc(Number);

}
