#include <iostream>
using namespace std;
void clearithbit(int &n, int pos)
{
    int m = ~(1 << pos);
    n = n & m;
}
int main()
{
    int n, k;
    cin >> n >> k;
    clearithbit(n, k);
    cout << n;
}