#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int firstoccurece(int *a, int s, int e, int key)
{

    int mid = (s + e) / 2;
    int ans = -1;
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
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}
int lastoccurece(int *a, int s, int e, int key)
{

    int mid = (s + e) / 2;
    int ans = -1;
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
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int a[100];
    int n;
    int count = 0;
    cin >> n;
    int s = 0;
    int e = n - 1;
    int key;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> key;

    int first = firstoccurece(a, s, e, key);
    int last = lastoccurece(a, s, e, key);
    count = last - first + 1;
    if (first == -1)
    {
        count = 0;
    }
    cout << first << " " << last << " " << count;
    return 0;
}
