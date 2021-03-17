#include <iostream>
using namespace std;
void setithbit(int &n, int pos)
{
    int m = 1 << pos;
    n = n | m;
}
int main()
{
    int n, k;
    cin >> n >> k;
    setithbit(n, k);
    cout << n;
}