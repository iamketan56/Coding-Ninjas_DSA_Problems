#include <iostream>
using namespace std;

void printdigit(int n)
{
    if (n >= 1)
    {
        printdigit(n / 10);
        cout << n % 10 << " ";
    }
}
int main()
{
    int n;
    cout << "Enter number" << endl;
    cin >> n;
    cout << "Digits of this number are ";
    printdigit(n);
}