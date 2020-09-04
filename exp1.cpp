#include <iostream>
using namespace std;

int main()
{
    int a = 100;
    int& ar = a;
    cout << a << endl;
    a = 200;
    cout << ar << endl;
    ar = 300;
    cout << a << endl;
    return 0;
}