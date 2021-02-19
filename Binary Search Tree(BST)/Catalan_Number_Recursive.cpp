#include <iostream>
using namespace std;
int catalan_number(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += catalan_number(i - 1) * catalan_number(n - i);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << catalan_number(i) << " ";
    }
}