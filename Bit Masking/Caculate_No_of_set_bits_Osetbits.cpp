#include <iostream>
using namespace std;
int countSetbits(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    cout << countSetbits(n);
}