#include <iostream>
using namespace std;
int countSetbits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += (n & 1); // O(no of bits)
        n = n >> 1;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    cout << countSetbits(n);
}