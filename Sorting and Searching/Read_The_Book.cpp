#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int
bool isvalidconfig(ll books[], ll n, ll k, ll ans)
{
    int students = 1;
    ll curr_pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr_pages + books[i] > ans)
        {
            curr_pages = books[i];
            students++;
            if (students > k)
            {
                return false;
            }
        }
        else
        {
            curr_pages += books[i];
        }
    }
    return true;
}
ll binarysearch(ll books[], ll n, ll k)
{
    ll s = 0;
    ll e = 0;
    ll total_page = 0;
    for (int i = 0; i < n; i++)
    {
        total_page += books[i];
        s = max(s, books[i]);
    }
    e = total_page;
    int finalans = s;
    while (s <= e)
    {
        ll mid = (s + e) / 2;
        if (isvalidconfig(books, n, k, mid))
        {
            finalans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return finalans;
}
int main()
{
    ll n;
    ll k;
    cin >> n >> k;
    ll books[100005];
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }
    cout << binarysearch(books, n, k);
}