#include <iostream>
using namespace std;

float sqrt(int n, int p)
{
    int s = 0;
    int e = n;
    float ans;
    int mid;
    while (s <= e)
    {
        mid = (s + e) / 2;

        if (mid * mid == n)
        {
            ans = mid;
            break;
        }

        if (mid * mid < n)
        {
            s = mid + 1;
            ans = mid;
        }

        if (mid * mid > n)
        {
            e = mid - 1;
        }
    }
    float inc = 0.1;
    for (int i = 0; i < p; i++)
    {
        while (ans * ans <= n)
        {
            ans += inc;
        }
        ans = ans - inc;
        inc = inc / 10;
    }
    return ans;
}
int main()
{
    int value, p;
    cout << "Enter a number to find the SQRT and Precision upto which your want answer" << endl;
    cin >> value >> p;
    cout << sqrt(value, p);
}