#include <iostream>
#include <stack>
using namespace std;
void findspan(int ar[], int n)
{
    stack<int> s;
    int ans[100] = {};

    for (int d = 0; d < n; ++d)
    {
        int current = ar[d];
        while (s.empty() == false && ar[s.top()] < current)
        {
            s.pop();
        }
        int bestday = s.empty() ? 0 : s.top();
        int span = d - bestday;
        ans[d] = span;
        s.push(d);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    int n = 7;
    int ar[100] = {100, 80, 60, 70, 60, 75, 85};
    findspan(ar, n);
}