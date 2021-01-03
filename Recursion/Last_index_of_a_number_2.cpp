#include <iostream>
using namespace std;
int last_Index(int *a, int size, int x)
{
    int ans;
    if (a[size - 1] == x)
    {
        return size - 1;
    }
    else
    {
        ans = last_Index(a, size - 1, x);
    }
    return size == 0 ? -1 : ans;
}
int main()
{
    int a[] = {10, 2, 1, 2, 4, 3};
    cout << last_Index(a, 6, 4);
}