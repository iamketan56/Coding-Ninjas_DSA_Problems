#include <iostream>
using namespace std;
int smalloputput = 1;
int pow(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x * pow(x, n - 1);
    }
}
int main()
{
    cout << pow(3, 4);
}