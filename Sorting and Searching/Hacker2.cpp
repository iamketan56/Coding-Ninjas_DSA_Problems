#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[100005];
    int n, key, mid;
    cin >> n;
    int s = 0;
    int e = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> key;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (a[mid] > key)
        {
            e = mid - 1;
        }
        if (a[mid] < key)
        {
            s = mid + 1;
        }
        if (a[mid] == key)
        {
            cout << mid;
            return 0;
        }
    }
    cout << "-1";
}