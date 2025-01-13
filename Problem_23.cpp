#include <iostream>
#include <string>
#include <cstring>
//#include <pointer>
using namespace std;
void Printworld(string world)
{
    cout << world[0] << endl;

    for(short i = 0 ; i <= world.length(); i++) {

        if(world[i] == ' ') {
            cout << world[i+1] << endl;
        }
    }
}
int main()
{

    string Name = "anas Abdallah Awadh Saleh Abde";
    Printworld(Name);
}
    