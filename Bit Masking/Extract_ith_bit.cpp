#include <iostream>
using namespace std;
int getithbit(int n, int pos)
{
    return (n & (1 << pos)) != 0 ? 1 : 0;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << getithbit(n, k);
}