#include <iostream>
using namespace std;
int main()
{
    int t, c1, c2, c3, c4, m, n;
    int ricCost = 0, cabCost = 0;
    cin >> t;

    int ric[100];
    int cab[100];

    while (t--)
    {
        cin >> c1 >> c2 >> c3 >> c4;
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            cin >> ric[i];
            ricCost += min(ric[i] * c1, c2);
        }
        ricCost = min(ricCost, c3);
        for (int i = 0; i < n; i++)
        {
            cin >> cab[i];
            cabCost += min(cab[i] * c1, c2);
        }
        cabCost = min(cabCost, c3);
        cout << min(c4, ricCost + cabCost);
    }
}