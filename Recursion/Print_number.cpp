#include <iostream>
using namespace std;
void printnumber(int n)
{
    if (n >= 0)
    {
        printnumber(n - 1);
        cout << n << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the number upto which you wanna print" << endl;
    cin >> n;
    printnumber(n);
}